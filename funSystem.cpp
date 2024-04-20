#include "funSystem.hpp"
#ifdef _WIN32
#include <Windows.h>
#include <stdlib.h>
#endif
#include <iostream>
#include <cstring>
#include <array>
#include <chrono>
#include <thread>
using namespace std;

void clearTerminal()
{
  cout << "\033[2J\033[1;1H";
}

void changeColor()
{
#if defined(_WIN32)
//  static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//  SetConsoleTextAttribute(handle, 240);
    system("Color F0");
#elif defined(__linux__) || defined(__APPLE__)
  cout << "\033[30;107m";
#endif
}

void resetColor()
{
#if defined(_WIN32)
// static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
// SetConsoleTextAttribute(handle, 7);
    system("Color 0F");
#elif defined(__linux__) || defined(__APPLE__)
  cout << "\033[0m";
#endif
}

void coutNegative(const string &s)
{
  changeColor();
  cout << s;
  resetColor();
}

void displayResponse(string text, int delaySeconds) {
    cout << endl << text << flush;
    this_thread::sleep_for(chrono::seconds(delaySeconds));
}

array<string, 2> getAnswer() {
    array<string, 2> answerArray;
    string answer = "";
    answerArray[0] = "";
    answerArray[1] = "";
    string::size_type position = 0;
    cout << "/";
    getline(cin, answer);
    if (answer == "help") {
        cout << "help\n:commands\n:reset";
        answerArray[0] = "help";
        displayResponse("", 3);
    }
    else {
        position = answer.find(":");
      if (position != 0 && position < 100) {
          answerArray[0] = answer.substr(0, position);
          answerArray[1] = answer.substr(position + 1, answer.length());
      }
      if (answerArray[0] == "help" && answerArray[1] == "commands") {
        displayResponse("Dostepne komendy to:\nhelp\nrotate:(number)\ntext:(chars)\ntheme:(light/dark)", 4);
      }
      else if (answerArray[0] == "help" && answerArray[1] == "reset") {
        answerArray[0] = "reset";
      }
    }
    return answerArray;
}


