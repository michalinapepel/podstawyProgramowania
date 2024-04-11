#include "funSystem.hpp"
#ifdef _WIN32
#include <Windows.h>
#endif
#include <iostream>
#include <string>
#include <array>
using namespace std;

void clearTerminal()
{
  cout << "\033[2J\033[1;1H";
}

void changeColor()
{
#if defined(_WIN32)
  static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(handle, 240);
#elif defined(__linux__) || defined(__APPLE__)
  cout << "\033[30;107m";
#endif
}

void colorReset()
{
#if defined(_WIN32)
  static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(handle, 7);
#elif defined(__linux__) || defined(__APPLE__)
  cout << "\033[0m";
#endif
}

void coutNegative(const string &s)
{
  changeColor();
  cout << s;
  colorReset();
}

array<string, 2> getAnswer() {
    array<string, 2> answerArray;
    string answer = "";
    answerArray[0] = "";
    answerArray[1] = "";
    string::size_type position = 0;
    
    cout << "/";
    getline(cin, answer);
    
    position = answer.find(":");
    if (position != 0 && position < 100) {
        answerArray[0] = answer.substr(0, position);
        answerArray[1] = answer.substr(position + 1, answer.length());
    }
    
    return answerArray;
}
