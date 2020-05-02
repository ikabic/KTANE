#ifndef USER_HPP_INCLUDED
#define USER_HPP_INCLUDED

using namespace std;

#include "timer.hpp"

void start();

class Player{
protected:
    int points;
    Timer bestTime;
    string username;
    int playedGames;
public:
    Player(string u1, int p1 = 0, int h1 = 0, int m1 = 0, int s1 = 0, int p2 = 0):bestTime(h1, m1, s1){
        points = p1;
        username = u1;
        playedGames = p2;
    }

    int getPoints(){return points;}
    int getH(){return bestTime.getH();}
    int getM(){return bestTime.getM();}
    int getS(){return bestTime.getS();}
    string getUsername(){return username;}
    int getPlayedGames(){return playedGames;}
};

void addToPlayerFile(Player &p){
    ofstream myFile;
    myFile.open ("players.txt", ios_base::app);
    myFile << p.getUsername() << "|" << p.getPoints() << "|" << p.getPlayedGames() << "|" << p.getH() << "|" << p.getM() << "|" << p.getS() << "|" << endl;
    myFile.close();
}

bool checkUser(string username){
    string line1, line2;
    ifstream myFile("players.txt");
    if (myFile.is_open()){
        while(getline(myFile, line1)){
                for(unsigned int i = 0; i < line1.size(); i++){
                    if(line1[i] == '|'){break;}
                    line2 += line1[i];
                }
        if(username == line2){
                myFile.close();
                return true;}
        line2 = "";
        }
        myFile.close();
        return false;
    }

    else cout << "Error, file did not open";
    return true;
}

Player setUpUser(){
    string user;
    bool t;
    int x;
    system("cls");
    cout << "New user? Let's set up your account, what would you like your username to be?" << endl << "> ";
    cin >> user;
    t = checkUser(user);
    if(t == true){
        cout << "There's already an existing player with that username, would you like to try again or go back?" << endl << "1.  Try again           2.  Go back" << endl << "> ";
        cin >> x;
        if(x == 1){system("cls"); setUpUser();}
        if(x == 2){system("cls"); start();}
        exit(1);
    }
    Player p(user);
    addToPlayerFile(p);
    /// dodaj na Leaderboard
    cout << "You have successfully created an account! Welcome " << p.getUsername() << "!";
    Sleep(2000);
    system("cls");
    return p;
}

string findUser(){
    string user;
    bool t;
    int x;
    system("cls");
    cout << "Returning user? Please type in your username" << endl << "> ";
    cin >> user;
    t = checkUser(user);
    if(t == false){
        cout << "There's no existing player with that username, would you like to try again or go back?" << endl << "1.  Try again           2.  Go back" << endl << "> ";
        cin >> x;
        if(x == 1){system("cls"); findUser();}
        if(x == 2){system("cls"); start();}
        exit(2);
    }

    cout << "You have successfully logged in! Welcome back " << user << "!";
    Sleep(2000);
    system("cls");
    return user;
}

#endif // USER_HPP_INCLUDED
