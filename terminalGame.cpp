#include <iostream>
#include "./Levels/levelOne.hpp"
#include "./Levels/levelTwo.hpp"
#include "./Levels/levelThree.hpp"
using namespace std;
int menu() {
    int choice = 0;
    int level = 0;
    cout << "Wybierz:\n1 -> Nowa gra\n2 -> Wczytaj gre";
    cin >> choice;
    if (choice == 1){
        // otworz plik z zapisem postepu gry (jak nie ma to utworz)
        // wyczysc plik, nadpisz pustym znakiem
        level = 1;
    }
    else if (choice == 2){
        // otworz plik z zapisem postepu gry i sprawdz, na ktorym poziomie stanela rozgrywka
        // level = liczba z pliku + 1
    }
    
    return level;
}
int main() {
    int level = menu();
    int win = 0;
    while (true){
        switch(level){
            case 1 : if (/*levelOne()*/ 1 == 1) {
                level = 2;
            }; break;
            case 2 : if (/*levelTwo()*/ 1 == 1) {
                level = 3;
            }; break;
            case 3 : if (levelThree() == 1) {
                cout << "\n\nBrawo! Udalo ci sie przejsc wszystkie poziomy.";
                win = 1;
            }; break;
            default: 0; break;
        }
        if (win == 1) break;
    }
    return 0;
}
