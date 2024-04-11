#include "levelThree.hpp"

#include <iostream>
#include <string>

#include "../pictures.hpp"
#include "../funSystem.hpp"

using namespace std;

int levelThree() {
    int amount = 10;
    cin.ignore();
    while (amount > 0) {
        clearTerminal();
        cout << "need\nm";
        for (int i = 0; i < amount; i++) {
            cout << "o";
        }
        cout << "re\nspace\n\n";
        
        
        array<string, 2> answer = getAnswer();
        

        if (answer[0] == "text") {
            int argumentLength = static_cast<int>(answer[1].length());
            char argumentArray[argumentLength + 1];
            strcpy(argumentArray, answer[1].c_str());
            for (auto i: argumentArray) {
                if (i == ' ') {
                    amount--;
                }
            }
            postAnswer("Wykonano!");
        }
        else {
            postAnswer("Nieznane polecenie");
        }
    }
    
    return 1;
}
