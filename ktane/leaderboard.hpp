#ifndef LEADERBOARD_HPP_INCLUDED
#define LEADERBOARD_HPP_INCLUDED

int Leaderboard::totalGamesPlayed;
int Leaderboard::totalPointsEarned;

class Leaderboard{
protected:
    Player topPlayers[10];
    static int totalGamesPlayed;
    static int totalPointsEarned;
public:

};

#endif // LEADERBOARD_HPP_INCLUDED
