#include <iostream>
#include <string>
#include "../pictures.cpp"
#include "../funSystem.cpp"
using namespace std;
int levelOne(){
    int angle = 0, newAngle = 0, count = 0;
    cout<< "POZIOM 1\n\n";
    while (newAngle != 180){
        string answer = "";
        // CZESC DO ZASTAPIENIA

        if (newAngle>=0 && newAngle<=22 || newAngle>=341 && newAngle<=359){
            clearTerminal();
            cout<< "POZIOM 1\n\n";
            cout << six1;
        }
        else if (newAngle>=23 && newAngle<=68)
        {
            clearTerminal();
            cout<< "POZIOM 1\n\n";
            cout << six2;
        }
        else if (newAngle>=69 && newAngle<=114)
        {
            clearTerminal();
            cout<< "POZIOM 1\n\n";
            cout << six3;
        }
        else if (newAngle>=115 && newAngle<=160)
        {
            clearTerminal();
            cout<< "POZIOM 1\n\n";
            cout << six4;
        }
        else if (newAngle>=161 && newAngle<=206)
        {
            clearTerminal();
            cout<< "POZIOM 1\n\n";
            cout << six5;
        }
        else if (newAngle>=207 && newAngle<=252)
        {
            clearTerminal();
            cout<< "POZIOM 1\n\n";
            cout << six6;
        }
        else if (newAngle>=253 && newAngle<=298)
        {
            clearTerminal();
            cout<< "POZIOM 1\n\n";
            cout << six7;
        }
        else if (newAngle>=299 && newAngle<=340)
        {
            clearTerminal();
            cout<< "POZIOM 1\n\n";
            cout << six8;
        }
        // KONIEC CZESCI DO ZASTAPIENIA

        if (count == 0){
            cout << "Twoja odpowiedz: ";
        }
        else {
            cout << "Zla odpowiedz.\nTwoja odpowiedz: ";
        }
        cin >> answer;
        string subAnswer = "";
         if (answer.length() > 7){
             subAnswer =  answer.substr(0,7);
             }        
         if(subAnswer == "rotate:"){
             string::size_type answerLen;
             string::size_type pos = answer.find(":");
             angle = stoi(answer.substr(7, answer.length()-7), &answerLen);
             newAngle += angle;
             while (newAngle >= 360){
                 newAngle = newAngle - 360;
             }
         }
         else if (answer == "reset")
         {
             newAngle = 0;
         }
        count++;
        
        // nie dziala w VS CODE
        // switch(newAngle){
        //     case 0 ... 22: clearTerminal(); cout<< "POZIOM 1\n\n" << six1;break;
        //     case 23 ... 68: clearTerminal(); cout<< "POZIOM 1\n\n" << six2;break;
        //     case 115 ... 160: clearTerminal(); cout<< "POZIOM 1\n\n" << six3;break;
        //     case 161 ... 206: clearTerminal(); cout<< "POZIOM 1\n\n" << six4;break;
        //     case 207 ... 252: clearTerminal(); cout<< "POZIOM 1\n\n" << six5; break;
        //     case 207 ... 252: clearTerminal(); cout<< "POZIOM 1\n\n" << six6; break;
        //     case 253 ... 298: clearTerminal(); cout<< "POZIOM 1\n\n" << six7; break;
        //     case 299 ... 340: clearTerminal(); cout<< "POZIOM 1\n\n" << six8; break;
        //     case 341 ... 359: clearTerminal(); cout<< "POZIOM 1\n\n" << six1; break;
        //     default: 0; break;
        // }
    }
    int score = 1;
    return score;
}

int main() {
    levelOne();
    return 0;
}