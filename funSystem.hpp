#ifndef funSystem_hpp
#define funSystem_hpp

#include <stdio.h>
#include <string>
#include <array>
void clearTerminal();
void changeColor();
void colorReset();
void coutNegative(const std::string &s);
std::array<std::string, 2> getAnswer();
void postAnswer(std::string text, int time = 2);

#endif /* funSystem_hpp */
