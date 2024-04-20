#include "levelOne.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include "../pictures.hpp"
#include "../funSystem.hpp"

using namespace std;

int levelOne(){
    cin.ignore();
    int angle = 0, newAngle = 0;
    cout<< "POZIOM 1\n\nsix\n\n";
    while (newAngle != 180){
        switch(newAngle){
            case 0 ... 22: clearTerminal(); cout << "POZIOM 1\n\nsix\n\n"; six1(); break;
            case 23 ... 68: clearTerminal(); cout << "POZIOM 1\n\nsix\n\n"; six2(); break;
            case 69 ... 114: clearTerminal(); cout << "POZIOM 1\n\nsix\n\n"; six3();  break;
            case 115 ... 160: clearTerminal(); cout << "POZIOM 1\n\nsix\n\n"; six4(); break;
            case 161 ... 206: clearTerminal(); cout << "POZIOM 1\n\nsix\n\n"; six5(); break;
            case 207 ... 252: clearTerminal(); cout << "POZIOM 1\n\nsix\n\n"; six6(); break;
            case 253 ... 298: clearTerminal(); cout << "POZIOM 1\n\nsix\n\n"; six7(); break;
            case 299 ... 340: clearTerminal(); cout << "POZIOM 1\n\nsix\n\n"; six8(); break;
            case 341 ... 359: clearTerminal(); cout << "POZIOM 1\n\nsix\n\n"; six1(); break;
        } 
        
        array<string, 2> answer = getAnswer();
        auto ans = [&answer] {
            answer[0].erase(
                std::remove_if(answer[0].begin(), answer[0].end(), ::isspace),
                answer[0].end());
            answer[1].erase(
                std::remove_if(answer[1].begin(), answer[1].end(), ::isspace),
                answer[1].end());
        };
        ans();
        if (answer[0] == "rotate") {
            try {
                angle = stoi(answer[1]);
                displayResponse("Wykonano!");
            }
            catch (const std::invalid_argument & e) {
                angle = 0;
                displayResponse("Podano zly parametr - brak cyfr lub niepotrzebne znaki.", 3);
            }
            catch (const std::out_of_range & e) {
                angle = 0;
                displayResponse("Podano zly parametr - liczba jest zbyt duza.", 3);
            }
            newAngle += angle;
            while (newAngle >= 360){
                newAngle = newAngle - 360;
            }
        }
        else if (answer[0] == "reset")
        {
            newAngle = 0;
            displayResponse("Resetujemy dla ciebie poziom.");
        }
        else {
            displayResponse("Bledne lub nieznane polecenie");
        }
        
    }
    clearTerminal();
    cout << "POZIOM 1\n\nsix\n\n";
    six5();
    displayResponse("");
    return 1;
}
