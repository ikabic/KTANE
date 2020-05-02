#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

using namespace std;

#include "timer.hpp"

enum Colours{green = 1, yellow, red, blue, black, white};
enum ButtonText{DETONATE = 1, ABORT, HOLD, PRESS};

void textcolor(unsigned short color);
void copyForButton(int lineNumber, string* copiedLine1, string* copiedLine2);

class Button{
protected:
    Colours buttonColour;
    ButtonText text;
    Timer whenPressed;
    string label;
public:
    Button(Colours c1, ButtonText t1, int h1, int m1, int s1):whenPressed(h1, m1, s1){
        buttonColour = c1;/// randomise(1,3);
        text = t1; /// randomise(0,3);
    }

    Colours getColour(){return buttonColour;}
    ButtonText getText(){return text;}
};

void printButton(ButtonText text, Colours colours){
    int c;
    string line1, line2;
    if(colours == red){c = 4;}
    if(colours == blue){c = 3;}
    if(colours == yellow){c = 6;}
    textcolor(c);
    cout << "           .............." << endl << "         ....          ...."  << endl << "        ....            ...." << endl << "       ....              ...." << endl << "      ....                ...." << endl;
    if(text == DETONATE){
            copyForButton(1, &line1, &line2);
            cout << line1 << "    ";
            textcolor(7); cout << "DETONATE"; textcolor(c);
            cout << line2 << endl;}
    if(text == ABORT || text == PRESS){
        copyForButton(3, &line1, &line2);
        cout << line1 << "     ";
        if(text == ABORT){textcolor(7); cout << "ABORT"; textcolor(c);}
        else{textcolor(7); cout << "PRESS"; textcolor(c);}
        cout << line2 << endl;}
    if(text == HOLD){
        copyForButton(5, &line1, &line2);
        cout << line1 << "      ";
        textcolor(7); cout << "HOLD"; textcolor(c);
        cout << line2 << endl;}
    cout<< "      ....                ...." << endl << "       ....              ...." << endl << "        ....            ...." << endl << "         ....          ...." << endl << "           .............." << endl;
    textcolor(7);
 }

#endif // BUTTON_HPP_INCLUDED
