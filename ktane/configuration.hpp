#ifndef CONFIGURATION_HPP_INCLUDED
#define CONFIGURATION_HPP_INCLUDED

enum Direction{up, down, left, right};

class Configuration{
protected:
    int combination1[6];
    int combination2[6];
    Direction correctPick;
};

#endif // CONFIGURATION_HPP_INCLUDED
