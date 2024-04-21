#include "levelThree.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

#include "../pictures.hpp"
#include "../funSystem.hpp"

using namespace std;

int levelThree() {
    int amount = 10;
    while (amount > 0) {
        clearTerminal();
        cout<< "POZIOM 3\n\n";
        cout << "need\nm";
        for (int i = 0; i < amount; i++) {
            cout << "o";
        }
        cout << "re\nspace\n\n";
        array<string, 2> answer = getAnswer();
        auto ans = [&answer] {
            answer[0].erase(
                std::remove_if(answer[0].begin(), answer[0].end(), ::isspace),
                answer[0].end());
        };
        ans();
        
        if (arg2 == "-d" || arg2 == "-ngd") { if (answer[0] == "dev") { return 0; } }
        if (answer[0] == "text") {
            vector<char> argumentArray(answer[1].begin( ), answer[1].end( ));
            for (auto i: argumentArray) {
                if (i == ' ') {
                    amount--;
                }
            }
            displayResponse("Wykonano!");
        }
        else if (answer[0] == "game") {
            if (answer[1] == "menu") { return 0; }
            if (answer[1] == "reset") { amount = 10; }
            if (answer[1] == "resetall") { return 0; }
        }
        else if (answer[0] == "help") {}
        else if (answer[0] == "rotate") { displayUnsupportedResponse("rotate"); }
        else if (answer[0] == "select") { displayUnsupportedResponse("select"); }
        else if (answer[0] == "text") { displayUnsupportedResponse("text"); }
        else if (answer[0] == "theme") { displayUnsupportedResponse("theme"); }
        else { displayUnsupportedResponse(""); }
    }
    clearTerminal();
    cout << "POZIOM 3\n\nneed\nmre\nspace\n\n";
    displayResponse("Chyba byles glodny - zjadles wszystkie ooooo!");
    return 1;
}
