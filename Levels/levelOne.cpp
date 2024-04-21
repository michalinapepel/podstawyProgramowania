#include "levelOne.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include "../pictures.hpp"
#include "../funSystem.hpp"

using namespace std;

void displayHeader(int angle) {
    clearTerminal();
    cout << "POZIOM 1 ";
    if (angle != 0 && angle != 180) cout << "(" << angle << " deg)";
    cout << "\n\n";
}

int levelOne(){
    int angle = 0, newAngle = 0;
    
    while (newAngle != 180){
        switch(newAngle){
            case 0 ... 22: displayHeader(newAngle); six1(); break;
            case 23 ... 68: displayHeader(newAngle); six2(); break;
            case 69 ... 114: displayHeader(newAngle); six3();  break;
            case 115 ... 160: displayHeader(newAngle); six4(); break;
            case 161 ... 206: displayHeader(newAngle); six5(); break;
            case 207 ... 252: displayHeader(newAngle); six6(); break;
            case 253 ... 298: displayHeader(newAngle); six7(); break;
            case 299 ... 340: displayHeader(newAngle); six8(); break;
            case 341 ... 359: displayHeader(newAngle); six1(); break;
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
        
        if (arg2 == "-d" || arg2 == "-ngd") { if (answer[0] == "dev") { return 0; } }
        if (answer[0] == "rotate") {
            try {
                angle = stoi(answer[1]);
                displayResponse("Wykonano!");
            }
            catch (const std::invalid_argument & e) {
                angle = 0;
                displayResponse("[!] Podano nieprawidlowy parametr: brak cyfr lub niepotrzebne znaki", 3);
            }
            catch (const std::out_of_range & e) {
                angle = 0;
                displayResponse("[!] Podano nieprawidlowy parametr: liczba jest zbyt duza", 3);
            }
            newAngle += angle;
            while (newAngle >= 360){
                newAngle = newAngle - 360;
            }
        }
        else if (answer[0] == "game") {
            if (answer[1] == "menu") { return 0; }
            if (answer[1] == "reset") { newAngle = 0; }
            if (answer[1] == "resetall") { return 0; }
        }
        else if (answer[0] == "help") {}
        else if (answer[0] == "select") { displayUnsupportedResponse("select"); }
        else if (answer[0] == "text") { displayUnsupportedResponse("text"); }
        else if (answer[0] == "theme") { displayUnsupportedResponse("theme"); }
        else { displayUnsupportedResponse(""); }
        
    }
    clearTerminal();
    cout << "POZIOM 1\n\n";
    six5();
    displayResponse("Poziom ukonczony!");
    return 1;
}
