#include "levelTwo.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>
#include "../pictures.hpp"
#include "../funSystem.hpp"

using namespace std;

int levelTwo(){
    array<string, 2> answer;
    
    do {
        clearTerminal();
        cout << "POZIOM 2\n\n";
        birdCage();
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
        
        if (arg2 == "-d" || arg2 == "-ngd") { if (answer[0] == "dev") { return 0; } }
        if (answer[0] == "theme" && (answer[1] == "light"|| answer[1] == "dark")) {
            displayResponse("Wykonano!");
        }
        else if (answer[0] == "theme") displayResponse("[!] Podano nieprawidlowy parametr: polecenie /theme go nie akceptuje!", 3);
        else if (answer[0] == "game") {
            if (answer[1] == "menu") { return 0; }
            if (answer[1] == "resetall") { return 0; }
        }
        else if (answer[0] == "help") {}
        else if (answer[0] == "rotate") { displayUnsupportedResponse("rotate"); }
        else if (answer[0] == "select") { displayUnsupportedResponse("select"); }
        else if (answer[0] == "text") { displayUnsupportedResponse("text"); }
        else { displayUnsupportedResponse(""); }
        
    } while (answer[0] != "theme" || answer[1] != "light");
    
    clearTerminal();
    changeColor();
    cout << "POZIOM 2                                   \n";
    cout << "                                           \n";
    cout << "                                           ";
    birdFree();
    cout << "                                           \n";
    cout << "                                           \n";
    cout << "Brawo, uwolniles ptaszka!                  \n";
    cout << "                                           \n";
    displayResponse("");
    resetColor();
    int a;
    cin >> a;
    return 1;
}

