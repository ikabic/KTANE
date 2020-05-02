#ifndef LEADERBOARD_HPP_INCLUDED
#define LEADERBOARD_HPP_INCLUDED

#include "user.hpp"

using namespace std;

class Leaderboard{
protected:
    vector <Player> topPlayers;
    static int totalGamesPlayed;
    static int totalPointsEarned;
public:
    Leaderboard(){}

    void setTopPlayers(Player &p){
        topPlayers.push_back(p);
    }

    void getTopPlayers(){
        for(unsigned int i = 0; i < topPlayers.size(); i++){
        cout << topPlayers[i].getUsername() << " " << topPlayers[i].getPoints() << " " << topPlayers[i].getPlayedGames() << " " << topPlayers[i].getH() << ":" << topPlayers[i].getM() << ":" << topPlayers[i].getS() << endl;}}
};

void addToLeaderboardFile(){

}

void loadLeaderboard(Leaderboard &l){
     int points, h, m, s, gameNumber, i = 0;
    string user, line, line2;
    ifstream myFile("leaderboard.txt");
    if (myFile.is_open()){
            while(getline(myFile,line)){
                        i = 0;
                        user = "";
                    while(line[i] != '|'){user += line[i]; i++;}
                    i++;
                     line2 = "";
                    while(line[i] != '|'){line2 += line[i]; i++;}
                    i++;
                        points = atoi(line2.c_str());
                        line2 = "";
                    while(line[i] != '|'){line2 += line[i]; i++;}
                    i++;
                        gameNumber = atoi(line2.c_str());
                        line2 = "";
                    while(line[i] != '|'){line2 += line[i]; i++;}
                    i++;
                        h = atoi(line2.c_str());
                        line2 = "";
                    while(line[i] != '|'){line2 += line[i]; i++;}
                    i++;
                        m = atoi(line2.c_str());
                        line2 = "";
                    while(line[i] != '|'){line2 += line[i]; i++;}
                    i++;
                        s = atoi(line2.c_str());
                        line2 = "";
                        Player p(user, points, h, m, s, gameNumber);
                        l.setTopPlayers(p);
                }
        }
        myFile.close();
}

void addToLeaderboard(Leaderboard &l, Player &p){
    l.setTopPlayers(p);
    /// upis u fajl
}

void displayLeaderboard(int num){

}

#endif // LEADERBOARD_HPP_INCLUDED*/
