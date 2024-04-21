#include "funSystem.hpp"
#ifdef _WIN32
#include <Windows.h>
#include <stdlib.h>
#endif
#include <iostream>
#include <fstream>
#include <cstring>
#include <array>
#include <chrono>
#include <thread>
using namespace std;

void clearTerminal()
{
  cout << "\033[2J\033[1;1H";
}

void displayResponse(string text, int delaySeconds) {
    cout << endl << text << flush;
    this_thread::sleep_for(chrono::seconds(delaySeconds));
}

void changeColor()
{
#if defined(_WIN32)
//  static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//  SetConsoleTextAttribute(handle, 240);
    system("Color F0");
#elif defined(__linux__) || defined(__APPLE__)
  cout << "\033[30;107m";
#endif
}

void resetColor()
{
#if defined(_WIN32)
// static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
// SetConsoleTextAttribute(handle, 7);
    system("Color 0F");
#elif defined(__linux__) || defined(__APPLE__)
  cout << "\033[0m";
#endif
}

void displayInstruction() {
    clearTerminal();
    cout << R"(INSTRUKCJA
        
Twoje odpowiedzi powinny przyjmowac ponizszy format:
    
            ----------------------
            | polecenie:parametr |
            ----------------------
    
          na przyklad -> theme:dark

W kazdej chwili mozesz wpisac /help, aby zobaczyc dostepne polecenia.
    

    
    
    


[i] To okno za chwile samo zniknie.
    )";
    displayResponse("", 12);
}

void displayGoodbye() {
    clearTerminal();
    displayResponse("Do zobaczenia\n\n");
}

// Funkcja wywolujaca menu glowne

int level = 0;
string arg1;

void menu(string name) {
    int choice = 0;
    
    while (choice == 0) {
        clearTerminal();
        cout << "-------------------\n";
        cout << "|   MENU GLOWNE   |\n";
        cout << "-------------------\n\n";
        cout << "Co chcesz zrobic?\nNowa gra" << std::setw(7) << "->" << std::setw(6) << "1" << "\nWczytaj gre" << std::setw(4) << "->" << std::setw(6) << "2" << "\n\n";
        cout << "#TIP: Polecenie /help pomoze Ci, jesli utknales\n\n";
        array<string, 2> answer;
        answer = getAnswer();
        auto ans = [&answer] {
            answer[0].erase(
                            std::remove_if(answer[0].begin(), answer[0].end(), ::isspace),
                            answer[0].end());
            answer[1].erase(
                            std::remove_if(answer[1].begin(), answer[1].end(), ::isspace),
                            answer[1].end());
        };
        ans();
        
        if (arg2 == "-d" || arg2 == "-ngd") { if (answer[0] == "dev") { return; } }
        if (answer[0] == "select") {
            try {
                choice = stoi(answer[1]);
                if (choice < 1 || choice > 2) {
                    displayResponse("[!] Podano nieprawidlowy parametr: taki element nie istnieje", 3);
                    choice = 0;
                }
            }
            catch (const std::invalid_argument & e) {
                choice = 0;
                displayResponse("[!] Podano nieprawidlowy parametr: brak cyfr lub niepotrzebne znaki", 3);
            }
            catch (const std::out_of_range & e) {
                choice = 0;
                displayResponse("[!] Podano nieprawidlowy parametr: liczba jest zbyt duza", 3);
            }
        }
        else if (answer[0] == "game") {
            if (answer[1] == "menu") { displayResponse("Znajdujesz sie juz w menu"); }
            if (answer[1] == "reset") { displayResponse("[i] Ponowne wczytywanie menu..."); }
            if (answer[1] == "resetall") { }
        }
        else if (answer[0] == "help") {}
        else if (answer[0] == "rotate") { displayUnsupportedResponse("rotate"); }
        else if (answer[0] == "text") { displayUnsupportedResponse("text"); }
        else if (answer[0] == "theme") { displayUnsupportedResponse("theme"); }
        else { displayUnsupportedResponse(""); }
    }
    
    if (choice == 1){
        ofstream gameRecord("gameRecord.txt");
        gameRecord << "";
        gameRecord << "1";
        gameRecord.close();
        level = 1;
        
    }
    else if (choice == 2){
        ifstream gameRecord("gameRecord.txt");
        char output[] = " ";
        if (gameRecord.is_open()) {
            gameRecord.get(output[0]);
            gameRecord.close();
        }
        
        if (strcmp(output, "1") == 0 || strcmp(output, "2") == 0 || strcmp(output, "3") == 0) {
            level = std::atoi(output);
            clearTerminal();
        }
        else {
            displayResponse("[i] Nie masz jeszcze swojej gry.\nStworzylismy dla Ciebie nowa rozgrywke.", 5);
            ofstream gameRecord("gameRecord.txt");
            gameRecord << "";
            gameRecord << "1";
            gameRecord.close();
            level = 1;
            clearTerminal();
        }
    }

}

string arg2;

array<string, 2> getAnswer() {
    array<string, 2> answerArray;
    string answer = "";
    answerArray[0] = "";
    answerArray[1] = "";
    string::size_type position = 0;
    cout << "/";
    getline(cin, answer);
    
    position = answer.find(":");
    if (position != 0 && position < 100) {
        answerArray[0] = answer.substr(0, position);
        answerArray[1] = answer.substr(position + 1, answer.length());
    }
    else {
        answerArray[0] = answer;
        answerArray[1] = "";
    }
    
    // Obsluga polecenia help
    if (answerArray[0] == "help") {
        if (answerArray[1] == "") {
            displayResponse("help\n:commands\t#Wyswietla dostepne polecenia\n:instruction\t#Wyswietla instrukcje obslugi gry", 4);
        }
        else if (answerArray[1] == "commands") {
            displayResponse("Dostepne komendy to:\ngame:(exit|menu|reset|resetall)\t#Umozliwia sterowanie gra\nhelp:(commands|instruction)\t#Wyswietla pomoc\nrotate:(number)\t\t\t#Obraca widok\nselect:(number)\t\t\t#Wybiera jeden z dostepnych elementow\ntext:(chars)\t\t\t#Wpisuje tekst\ntheme:(light/dark)\t\t#Zmienia motyw", 7);
        }
        else if (answerArray[1] == "instruction") { displayInstruction(); }
        else { displayResponse("[!] Podano nieprawidlowy parametr: polecenie /help go nie akceptuje", 3); }
    }
    
    // Obsluga polecenia game
    if (answerArray[0] == "game") {
        if (answerArray[1] == "") {
            displayResponse("game\n:exit\t#Konczy dzialanie aplikacji\n:menu\t\t#Wraca do menu glownego\n:reset\t\t#Resetuje poziom\n:resetall\t#Resetuje caly postep w grze!", 4);
        }
        else if (answerArray[1] == "exit") { displayGoodbye(); exit(0); }
        else if (answerArray[1] == "menu") { level = 0; }
        else if (answerArray[1] == "reset") { displayResponse("[i] Resetujemy dla Ciebie poziom!");}
        else if (answerArray[1] == "resetall") {
            ofstream gameRecord("gameRecord.txt");
            gameRecord << "" << "0";
            gameRecord.close();
            level = 0;
            displayResponse("[i] Caly postep zostal zresetowany!", 3);
        }
        else {
            displayResponse("[!] Podano nieprawidlowy parametr: polecenie /game go nie akceptuje", 3);
        }
    }
    
    // Obsluga polecenia dev:(number)
    
    if (arg2 == "-d" || arg2 == "-ngd") {
        if (answerArray[0] == "dev") {
            int levelNumber = 0;
            try {
                levelNumber = stoi(answerArray[1]);
                if (levelNumber > 0 && levelNumber < 4) {
                    displayResponse("[D] Wykonano!");
                    level = levelNumber;
                }
                else {
                    displayResponse("[!] Podano nieprawidlowy parametr: nie znaleziono takiego poziomu", 3);
                }
            }
            catch (const std::invalid_argument & e) { displayResponse("[!] Podano nieprawidlowy parametr: brak cyfr lub niepotrzebne znaki", 3); }
            catch (const std::out_of_range & e) { displayResponse("[!] Podano nieprawidlowy parametr: liczba jest zbyt duza", 3); }
        }
    }
    
    return answerArray;
}

void displayUnsupportedResponse(string command) {
    if (command == "rotate") { displayResponse("[?] Tu nie ma czego obrocic"); }
    else if (command == "select") { displayResponse("[?] Tu nie ma nic do wyboru"); }
    else if (command == "text") { displayResponse("[?] Nie ma gdzie tego wyswietlic"); }
    else if (command == "theme") { displayResponse("[?] Zostanmy przy aktualnym motywie"); }
    else { displayResponse("[!] Bledne lub nieznane polecenie"); }
}
