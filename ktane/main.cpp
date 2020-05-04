#include <iostream>
#include <time.h>
#include <windows.h>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <iomanip>
#include <thread>

#include "button.hpp"
#include "complicatedWires.hpp"
#include "config.hpp"
#include "configuration.hpp"
#include "egg.hpp"
#include "game.hpp"
#include "leaderboard.hpp"
#include "needyModule.hpp"
#include "occurance.hpp"
#include "player.hpp"
#include "regularWires.hpp"
#include "sequenceWires.hpp"
#include "settings.hpp"
#include "simonSays.hpp"
#include "timer.hpp"
#include "up.hpp"
#include "user.hpp"

using namespace std;

int Leaderboard::totalGamesPlayed = 0;
int Leaderboard::totalPointsEarned = 0;
int SimonSays::stageNumber = 0;

void textcolor(unsigned short color){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon,color);
}

string currentTime(){
    time_t now = time(0);
    tm* localtm = localtime(&now);
    return asctime(localtm);
}

int randomise(int a, int b){
    return a + (rand() % ( b - a + 1));
}

Colours getRandomColour(int a, int b){
    int x = randomise(a,b);
    switch(x){
    case 1: return green;
    case 2: return yellow;
    case 3: return red;
    case 4: return blue;
    case 5: return black;
    case 6: return white;
    default: return red;
    }
}

ButtonText getRandomButtonText(int a, int b){
    int x = randomise(a,b);
    switch(x){
    case 1: return DETONATE;
    case 2: return ABORT;
    case 3: return HOLD;
    case 4: return PRESS;
    default: return ABORT;
    }
}

ExtraLabel getRandomLabel(int a, int b){
    int x = randomise(a,b);
    switch(x){
    case 1: return FRQ;
    case 2: return CAR;
    case 3: return CLR;
    case 4: return IND;
    case 5: return FRK;
    case 6: return SND;
    case 7: return BOB;
    case 8: return NO;
    default: return NO;
    }
}

Difficulty getRandomDifficulty(int a, int b){
   int x = randomise(a,b);
   switch(x){
   case 1: return easy;
   case 2: return normal;
   case 3: return hard;
   default: return easy;
   }
}

void copyForButton(int lineNumber, string* copiedLine1, string* copiedLine2){
    string line;
    ifstream myFile("buttonSettings.txt");
    if (myFile.is_open()){
        for(int i = 1; i < lineNumber; i++) getline(myFile,line);
        getline(myFile, line);
        *copiedLine1 = line;
        getline(myFile, line);
        *copiedLine2 = line;
        myFile.close();
    }

    else cout << "Error, file did not open";
}

void introduction(){
    cout << "Welcome to a recreation of the game KTANE (Keep Talking And No one Explodes)" << endl; textcolor(4);
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl; textcolor(7);
    cout << "Are you a new or an existing player?" << endl << "1.  New player          2.  Existing player" << endl << "> ";
}

void wrongInput(){
    cout << "The option you picked is not in our system, please try again";
    Sleep(2000);
    system("cls");
}

void printEssential(Game &g){
    cout << "Serial number: " << g.getSerialNumber() << endl;
    cout << "Number of batteries: " << g.getBatteries() << endl;
    cout << "Port: ";
    if(!g.getPort()) cout << "no" << endl;
    else cout << "yes" << endl;
    cout << "Number of strikes: " << g.getStrikes() << endl;
}

void menu(){
    cout << "Game menu" << endl; textcolor(4);
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl; textcolor(7);
    cout << "1.  Play                2.  Exit                3.  Leaderboard" << endl << "> ";
    int input;
    cin >> input;
    if(input == 1){}
    if(input == 2){return;}
    if(input == 3){}
}

void stageComplete(){
    system("cls");
    textcolor(10);
    cout << "Stage complete.";
    textcolor(7);
    Sleep(500);
    system("cls");
}

void startGame(){
    ///Game(? , randomise(0,6), randomise(0,1), randomise(0,1), randomise(1,3), 0, 0, 0, 0);
}

void gameOver(Timer &t){
    textcolor(4);
    system("cls");
    cout << "boom";
    Sleep(500);
    system("cls");
    cout << "Game over." << endl;
    textcolor(7);
    cout << "Time remaining: " << t.getH() << ":" << t.getM() << ":" << t.getS() << endl;
    textcolor(4);
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    textcolor(7);
    cout << "Would you like to play a new game or go back to the menu?" << endl << "1.  Try again           2.  Go back" << endl << "> ";
    int x;
    cin >> x;
    system("cls");
    if(x == 1){startGame();}
    if(x == 2){menu();}
    exit(4);
}

void start(){
    Leaderboard l;
    loadLeaderboard(l);
    introduction();
    int input;
    cin >> input;
    if(input == 1){
            Player p = setUpUser();
    }
    if(input == 2){string username = findUser();}
    else if(input != 1 && input != 2){
        wrongInput();
        start();}
    menu();
}

int main()
{
    srand((unsigned)time(NULL));
    string buttonFile = "buttonSettings.txt";
    string playerList = "players.txt";
    //start();
    Game g ("3GFDSGF3", randomise(0,6), randomise(0,1), randomise(0,1), getRandomDifficulty(1,3), 0, 0, 0, 0);
    Timer t(0,1,5);
    playButton(g,t);
    return 0;
}
