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
    void setH(int h){hours = h;}
    void setM(int m){minutes = m;}
    void setS(int s){seconds = s;}
};

void gameOver(Timer &t);

void displayTimer(Timer &t){
    system("cls");
    cout << setfill(' ') << setw(55) << "        TIMER         \n";
    cout << setfill(' ') << setw(55) << " --------------------------\n";
    cout << setfill(' ') << setw(29);
    cout << "| " << setfill('0') << setw(2) << t.getH() << " hrs | ";
    cout << setfill('0') << setw(2) << t.getM() << " min | ";
    cout << setfill('0') << setw(2) << t.getS() << " sec |" << endl;
    cout << setfill(' ') << setw(55) << " --------------------------\n" << endl;
}

void timerWithoutDisplay(Timer &t){
    while (true) {
        Sleep(1000);
        t.setS(t.getS() - 1);
        if (t.getS() == 0) {
            t.setM(t.getM() - 1);
            if (t.getM() == 0) {
                t.setH(t.getH() + 1);
                t.setM(60);
            }
            t.setS(60);
        }
    }
}

#endif // TIMER_HPP_INCLUDED
