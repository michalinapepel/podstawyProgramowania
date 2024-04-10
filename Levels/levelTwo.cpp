#include <iostream>
#include "../pictures.cpp"
#include "../funSystem.cpp"

using namespace std;
int levelTwo(){
    int score = 0;
    string answer = "";
    int count = 0;
    do {
        clearTerminal();
        cout << "POZIOM 2\n\n";
        cout << birdCage;
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
        system("Color F0");
        coutNegative("Brawo, uwolniles ptaszka\n\n");
        coutNegative(birdFree);
        coutNegative("\n\n\n");
        score = 1;
    return score;
}