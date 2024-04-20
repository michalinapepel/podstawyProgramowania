#include "levelTwo.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>
#include "../pictures.hpp"
#include "../funSystem.hpp"

using namespace std;

int levelTwo(){
    cin.ignore();
    cout << flush;
    string answer = "";
    int count = 0;
    do {
        if(count > 1){
            displayResponse("\nBledne lub nieznane polecenie");
        }
        clearTerminal();
        cout << "POZIOM 2\n\n";
        birdCage();
        cout << "/";
        getline(cin, answer);
        auto ans = [&answer] {
            answer.erase(
                std::remove_if(answer.begin(), answer.end(), ::isspace),
                answer.end());};
        ans();
        count++;
    } while (answer != "theme:light");
        clearTerminal();
        changeColor();
        cout << "Brawo, uwolniles ptaszka\n\n\033[K";
        birdFree();
        resetColor();
        displayResponse("");
    return 1;
}
