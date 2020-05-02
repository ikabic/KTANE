#ifndef SETTINGS_HPP_INCLUDED
#define SETTINGS_HPP_INCLUDED

enum Difficulty{easy = 1, normal, hard};

class Settings{
private:
    Difficulty gameDifficulty;
    Timer gameTime;
public:
    Settings(Difficulty d1, int h1, int m1, int s1):gameTime(h1, m1, s1){
        gameDifficulty = d1;
    }
};

#endif // SETTINGS_HPP_INCLUDED
