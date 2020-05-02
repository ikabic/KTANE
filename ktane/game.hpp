#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include "settings.hpp"

class Game{
protected:
    int moduleNumber;
    int finishedModuleNumber;
    int earnedPoints;
    Settings gameSettings;
    int strikes;
    int serialNumber;
    int batteries;
    bool port;
    bool needyModule;
public:
    Game(int serialNumber1, int batteries1, bool port1, bool needyModule1, Difficulty difficulty1, int hour1, int minute1, int second1, int moduleNumber1, int points1 = 0, int finishedModuleNumber1 = 0, int strikes1 = 0)
    :gameSettings(difficulty1, hour1, minute1, second1){
        moduleNumber = moduleNumber1;
        finishedModuleNumber = finishedModuleNumber1;
        strikes = strikes1;
        serialNumber = serialNumber1;
        batteries = batteries1;
        port = port1;
        needyModule = needyModule1;
        earnedPoints = points1;
    }
};

#endif // GAME_HPP_INCLUDED
