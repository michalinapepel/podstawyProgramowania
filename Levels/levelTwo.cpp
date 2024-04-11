#include "levelTwo.hpp"
#include <iostream>
#include "../pictures.hpp"
#include "../funSystem.hpp"

using namespace std;
int levelTwo(){
    int score = 0;
    string answer = "";
    int count = 0;
    do {
        clearTerminal();
        cout << "POZIOM 2\n\n";
        birdCage();
        if(count == 0){
            cout << "Twoja odpowiedz: ";
        }
        else{
            cout << "To byla zla odpowiedz.\nTwoja odpowiedz: ";
        }
        cin >> answer;
        count++;
    } while (answer != "theme:white");
        clearTerminal();
        coutNegative("Brawo, uwolniles ptaszka\n\n");
        changeColor();
        birdFree();
        colorReset();
        coutNegative("\n\n\n");
        score = 1;
    return score;
}
