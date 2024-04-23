#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "funSystem.hpp"
#include "./Levels/levelOne.hpp"
#include "./Levels/levelTwo.hpp"
#include "./Levels/levelThree.hpp"

using namespace std;

// Konfiguracja aplikacji

struct config
{
    string arg1 = "Nieznajomy"; // Imie uzytkownika
    string arg2 = "";           // Flaga deweloperska
};

config parse_command_params(char** argv)
{
    config cfg;

    if(!argv[1]) { return cfg; }
    cfg.arg1 = argv[1];
    
    if(!argv[2]) { return cfg; }
    cfg.arg2 = argv[2];

    return cfg;
}

// Funkcja witajaca uzytkownika (flaga 'ng' blokuje)

void displayGreeting(string name) {
    clearTerminal();
    displayResponse("Witaj " + name + ".", 3);
    clearTerminal();
    displayResponse("Zacznijmy od krotkiej instrukcji.", 5);
    displayInstruction();
    clearTerminal();
    displayResponse("Przejdziemy teraz do menu glownego.\nJuz teraz sprawdzisz swoja umiejetnosc obslugi aplikacji :)", 7);
}



// Glowna czesc aplikacji

int main(int argc, char* argv[]) {
    /* Utworzenie struktury pozwalajacej na uruchomienie aplikacji z parametrami lub bez
       Pierwszy parametr arg1 to imie uzytkownika
       Drugi paramentr arg2 'ng' pozwala na pominiecie powitania (ng=NoGreeting) */
    config cfg;
    
    try { cfg = parse_command_params(argv); }
    catch(std::exception const& e) { return EXIT_FAILURE; }
    
    if (cfg.arg2 != "-ng" && cfg.arg2 != "-ngd") { displayGreeting(cfg.arg1); }
    arg1 = cfg.arg1;
    arg2 = cfg.arg2;
    
    // Petla sterujaca przebigem aplikacji - przelacza poziomy
    int win = 0;
    while (win == 0){
        switch(level){
            case 0 :
                menu(arg1); break;
            case 1 : if (levelOne() == 1) {
                ofstream gameRecord("gameRecord.txt");
                gameRecord << "" << "2";
                gameRecord.close();
                level = 2;
            }; break;
            case 2 : if (levelTwo() == 1) {
                ofstream gameRecord("gameRecord.txt");
                gameRecord << "" << "3";
                gameRecord.close();
                level = 3;
            }; break;
            case 3 : if (levelThree() == 1) {
                clearTerminal();
                cout << R"(
            --------------
            | BRAWOOOOO! |
            --------------
Udalo Ci sie przejsc wszystkie poziomy.




            Made with <3 by
     Michalina Pepel & Rafal Kraz



)";
                win = 1;
            }; break;
        }
    }
    return 0;
}
