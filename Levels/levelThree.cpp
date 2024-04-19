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
    cin.ignore();
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
            answer[1].erase(
                std::remove_if(answer[1].begin(), answer[1].end(), ::isspace),
                answer[1].end());
        };
        ans();
        if (answer[0] == "text") {
            vector<char> argumentArray(answer[1].begin( ), answer[1].end( ));
            for (auto i: argumentArray) {
                if (i == ' ') {
                    amount--;
                }
            }
            displayResponse("Wykonano!");
        }
        else {
            displayResponse("Bledne lub nieznane polecenie");
        }
    }
    
    return 1;
}
