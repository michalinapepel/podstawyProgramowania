#include "funSystem.hpp"

#ifdef _WIN32
#include <Windows.h>
#endif
#include <iostream>
#include <string>
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
