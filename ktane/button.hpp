#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

using namespace std;

#include "timer.hpp"
#include "game.hpp"

enum Colours{green = 1, yellow, red, blue, black, white};
enum ButtonText{DETONATE = 1, ABORT, HOLD, PRESS};
enum ExtraLabel{FRQ = 1, CAR, CLR, IND, FRK, SND, BOB, NO};

void textcolor(unsigned short color);
ButtonText getRandomButtonText(int a, int b);
ExtraLabel getRandomLabel(int a, int b);
Colours getRandomColour(int a, int b);
void copyForButton(int lineNumber, string* copiedLine1, string* copiedLine2);
ExtraLabel getRandomLabel(int a, int b);
void stageComplete();
void gameOver(Timer &t);
void printEssential(Game &g);

class Button{
protected:
    Colours buttonColour;
    Colours strip;
    ButtonText text;
    Timer whenPressed;
    ExtraLabel label;
public:
    Button(Colours c1, Colours s1, ButtonText t1, ExtraLabel l1, int h1 = 0, int m1 = 0, int s2 = 0):whenPressed(h1, m1, s2){
        buttonColour = c1;
        text = t1;
        strip = s1;
        label = l1;
    }

    Colours getColour(){return buttonColour;}
    Colours getStrip(){return strip;}
    ButtonText getText(){return text;}
    ExtraLabel getLabel(){return label;}
    int getH(){return whenPressed.getH();}
    int getM(){return whenPressed.getM();}
    int getS(){return whenPressed.getS();}
};

void printButton(ButtonText text, Colours colours){
    int c;
    string line1, line2;
    if(colours == red){c = 4;}
    if(colours == blue){c = 3;}
    if(colours == yellow){c = 6;}
    if(colours == black){c = 8;}
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

 void buttonTimerWithDisplay(Timer &t, Button &b, int &x){
    while (true) {
        displayTimer(t);
        cout << "Button strip: ";
        if(b.getStrip() == green){textcolor(10); cout << "green";}
        if(b.getStrip() == yellow){textcolor(14); cout << "yellow";}
        if(b.getStrip() == red){textcolor(4); cout << "red";}
        if(b.getStrip() == blue){textcolor(3); cout << "blue";}
        if(b.getStrip() == white){textcolor(7); cout << "white";}
        if(b.getStrip() == black){textcolor(8); cout << "black";}
        textcolor(7);
        cout << endl << "Press 1 to release the held button" << endl << "> ";
        Sleep(1000);
        t.setS(t.getS() - 1);
        if(t.getS() == 0 && t.getM() > 0){
            t.setM(t.getM() - 1);
            if (t.getM() == 0 && t.getH() > 0){
                t.setH(t.getH() - 1);
                t.setM(60);
            }
            t.setS(60);
        }
    }
}

void playButton(Game &g, Timer &t){
     Button b(getRandomColour(2,5), getRandomColour(1,6), getRandomButtonText(1,4), getRandomLabel(1, 8));
     printEssential(g);
     cout << "Label: " << b.getLabel() << endl;
     printButton(b.getText(), b.getColour());
     cout << endl << "1.  Tap                     2.  Hold" << endl << "> ";
     int input;
     cin >> input;
     if(input == 1 && ((g.getBatteries() > 1 && b.getText() == DETONATE) || (g.getBatteries() > 2 && b.getLabel() == FRK) || (b.getColour() == red && b.getText() == HOLD))){stageComplete(); return;}
     if(input == 2){
        int x;
        thread timer(buttonTimerWithDisplay, ref(t), ref(b));
       // timer.join();
        cin >> x;
        terminate();
        stageComplete();
     }
        Timer t1(b.getH(), b.getM(), b.getS());
        //gameOver(t1);
}

#endif // BUTTON_HPP_INCLUDED
