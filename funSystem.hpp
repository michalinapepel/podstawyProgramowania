#ifndef funSystem_hpp
#define funSystem_hpp

#include <stdio.h>
#include <string>
#include <array>
void clearTerminal();
void changeColor();
void resetColor();
void coutNegative(const std::string &s);
std::array<std::string, 2> getAnswer();
void displayResponse(std::string text, int delaySeconds = 2);

#endif /* funSystem_hpp */
