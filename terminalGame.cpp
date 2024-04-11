#include <iostream>
#include <iomanip>
#include "./Levels/levelOne.hpp"
#include "./Levels/levelTwo.hpp"
#include "./Levels/levelThree.hpp"
using namespace std;
int menu(string name) {
    int choice = 0;
    int level = 0;
    cout.width(45);
    cout << right << "\n\n\n\nWitaj " + name;
    cout << "!\n\n\n\n\nWybierz:\nNowa gra" << std::setw(7) << "->" << std::setw(6) << "1" << "\nWczytaj gre" << std::setw(4) << "->" << std::setw(6) << "2";
    cin >> choice;
    if (choice == 1){
        // otworz plik z zapisem postepu gry (jak nie ma to utworz)
        // wyczysc plik, wpisz 1
        level = 1;
    }
    else if (choice == 2){
        // otworz plik z zapisem postepu gry i sprawdz, na ktorym poziomie stanela rozgrywka
        // jeżeli w pliku nie ma 1, 2 ani 3 to wyświetl "Nie masz jeszcze swojej gry. Stworzyliśmy dla ciebie nową rozgrywkę"
        // jeżeli jest któraś z tych cyfr to level = liczba z pliku
    }
    
    return level;
}
int main(int argc, char* argv[]) { 
    string name = argv[1];
    int level = menu(name);
    int win = 0;
    while (true){
        switch(level){
            case 1 : if (levelOne() == 1) {
                //wpisz do pliku 2
                level = 2;
            }; break;
            case 2 : if (levelTwo() == 1) {
                //wpisz do pliku 3
                level = 3;
            }; break;
            case 3 : if (/*levelThree()*/1 == 1) {
                cout << "Brawo! Udalo ci sie przejsc wszystkie poziomy.";
                win = 1;
            }; break;
            default: 0; break;
        }
        if (win == 1) break;
    }
    return 0;
}
