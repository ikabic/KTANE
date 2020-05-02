#ifndef TIMER_HPP_INCLUDED
#define TIMER_HPP_INCLUDED

class Timer{
protected:
    int hours;
    int minutes;
    int seconds;
public:
    Timer(int h, int m, int s){
        hours = h;
        minutes = m;
        seconds = s;
    }

    int getH(){return hours;}
    int getM(){return minutes;}
    int getS(){return seconds;}
};

#endif // TIMER_HPP_INCLUDED
