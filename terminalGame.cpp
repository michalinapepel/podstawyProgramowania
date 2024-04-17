#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "funSystem.hpp"
#include "./Levels/levelOne.hpp"
#include "./Levels/levelTwo.hpp"
#include "./Levels/levelThree.hpp"
using namespace std;
int menu(string name) {
    clearTerminal();
    int choice = 0;
    int level = 0;
    cout.width(45);
    cout << right << "Witaj " + name;
    cout << "!\n\n\n\n\nWybierz:\nNowa gra" << std::setw(7) << "->" << std::setw(6) << "1" << "\nWczytaj gre" << std::setw(4) << "->" << std::setw(6) << "2" << endl;
    cin >> choice;
    if (choice == 1){
        ofstream gameRecord("gameRecord.txt");
        gameRecord << "";
        gameRecord << "1";
        gameRecord.close(); 
        level = 1;
        clearTerminal();
        cout << "INSTRUKCJA\n\nTwoje odpowiedzi powinny przyjmowac ponizszy format:\npolecenie:parametr, na przykład" << std::setw(7) << "->"<< std::setw(6) << "theme:dark\n\nWpisz polecenie help, aby zobaczyc dostepne komendy";
        displayResponse("", 10);
    }
    else if (choice == 2){
        ifstream gameRecord("gameRecord.txt");
        char output[] = " ";
        if (gameRecord.is_open()) {
            gameRecord.get(output[0]);
            gameRecord.close();
        }
        if (strcmp(output, "1") == 0 || strcmp(output, "2") == 0 || strcmp(output, "3") == 0) {
            level =  std::atoi(output);
            clearTerminal();
            cout << "INSTRUKCJA\n\nTwoje odpowiedzi powinny przyjmowac ponizszy format:\npolecenie:parametr, na przykład" << std::setw(7) << "->"<< std::setw(6) << "theme:dark\n\nWpisz polecenie help, aby zobaczyc dostepne komendy";
            displayResponse("", 10);
        }
        else {
            cout << "Nie masz jeszcze swojej gry.\nStworzylismy dla ciebie nowa rozgrywke.";
            ofstream gameRecord("gameRecord.txt");
            gameRecord << "";
            gameRecord << "1";
            gameRecord.close(); 
            level = 1;
            clearTerminal();
            cout << "INSTRUKCJA\n\nTwoje odpowiedzi powinny przyjmowac ponizszy format:\npolecenie:parametr, na przykład" << std::setw(7) << "->"<< std::setw(6) << "theme:dark\n\nWpisz polecenie help, aby zobaczyc dostepne komendy";
            displayResponse("", 10);
        }
    }
    
    return level;
}

int main(int argc, char* argv[]) { 
    string name = argv[1];
    int level = menu(name);
    int win = 0;
    while (true){
        switch(level){
            case 1 : if (levelOne() == 1) {
                ofstream gameRecord("gameRecord.txt");
                gameRecord << "" << "2";
                gameRecord.close();
                level = 2;
            }; break;
            case 2 : if (levelTwo() == 1) {
                ofstream gameRecord("gameRecord.txt");
                gameRecord << "" << "3";
                gameRecord.close();
                level = 3;
            }; break;
            case 3 : if (levelThree() == 1) {
                clearTerminal();
                cout << "Brawo! Udalo ci sie przejsc wszystkie poziomy.";
                win = 1;
            }; break;
        }
        if (win == 1) break;
    }
    return 0;
}
