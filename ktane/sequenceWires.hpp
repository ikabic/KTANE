#ifndef SEQUENCEWIRES_HPP_INCLUDED
#define SEQUENCEWIRES_HPP_INCLUDED

#include "regularWires.hpp"

class SequenceWires:public RegularWires{
protected:
    int stageNumber;
    Occurance colourOccurance;
public:

};

#endif // SEQUENCEWIRES_HPP_INCLUDED
