#include "levelTwo.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>
#include "../pictures.hpp"
#include "../funSystem.hpp"

using namespace std;

int levelTwo(){
    array<string, 2> answer;
    cin.ignore();
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
        if(answer[0] == "help") {}
        else if (answer[0] == "reset")
        {
            displayResponse("Resetujemy dla ciebie poziom.");
        }
        else if(answer[0] == "theme" && (answer[1] == "light"||answer[1] == "dark")) {
            displayResponse("Wykonano!");
        }
        else if (answer[0] != "theme") {
            displayResponse("\nBledne lub nieznane polecenie");
        }
    } while (answer[0] != "theme" && answer[1] != "light");
        clearTerminal();
        changeColor();
        cout << "Brawo, uwolniles ptaszka\n\n";
        birdFree();
        resetColor();
        displayResponse("");
    return 1;
}

