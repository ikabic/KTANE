#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

enum ButtonText{DETONATE, ABORT, HOLD, PRESS};

class Button{
protected:
    Colours buttonColour;
    ButtonText text;
    Time whenPressed;
public:
};

#endif // BUTTON_HPP_INCLUDED
