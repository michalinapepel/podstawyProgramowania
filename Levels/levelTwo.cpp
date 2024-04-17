#include "levelTwo.hpp"
#include <iostream>
#include "../pictures.hpp"
#include "../funSystem.hpp"

using namespace std;
int levelTwo(){
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
        cin >> answer;
        count++;
    } while (answer != "theme:light");
        clearTerminal();
        coutNegative("Brawo, uwolniles ptaszka\n\n");
        changeColor();
        birdFree();
        resetColor();
        coutNegative("\n\n\n");
        displayResponse("");
    return 1;
}
