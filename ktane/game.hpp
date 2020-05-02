#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

class Game{
protected:
    int moduleNumber;
    int finishedModuleNumber;
    Settings gameSettings;
    Player player;
    int strikes;
    int serialNumber;
    int batteries;
    bool port;
    bool needyModule;
public:
};

#endif // GAME_HPP_INCLUDED
