#ifndef funSystem_hpp
#define funSystem_hpp

#include <stdio.h>
#include <string>
#include <array>
void clearTerminal();
void displayResponse(std::string text, int delaySeconds = 2);
void changeColor();
void resetColor();
void displayInstruction();
void displayHelp();
void displayGoodbye();
extern int level;
extern int lastLevel;
extern std::string arg1;
extern std::string arg2;
void menu(std::string name);
std::array<std::string, 2> getAnswer(bool isLocked = false);
void displayUnsupportedResponse(std::string command);

#endif /* funSystem_hpp */
