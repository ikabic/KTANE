#include <iostream>
#include <time.h>
#include <windows.h>
#include <fstream>
#include <vector>
//#include <sstream>
//#include <string>
#include <stdlib.h>

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

Colours getColour(int a, int b){
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

ButtonText getText(int a, int b){
    int x = randomise(a,b);
    switch(x){
    case 1: return DETONATE;
    case 2: return ABORT;
    case 3: return HOLD;
    case 4: return PRESS;
    default: return ABORT;
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

void menu(){
    cout << "Game menu" << endl; textcolor(4);
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl; textcolor(7);
    cout << "1.  Play                2.  Exit                3.  Leaderboard" << endl << "> ";
}

void startGame(){
    ///Game(? , randomise(0,6), randomise(0,1), randomise(0,1), randomise(1,3), 0, 0, 0, 0);
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
    cin >> input;
    if(input == 1){}
    if(input == 2){return;}
    if(input == 3){}
}

int main()
{
    srand((unsigned)time(NULL));
    string buttonFile = "buttonSettings.txt";
    string playerList = "players.txt";
    start();
    return 0;
}
