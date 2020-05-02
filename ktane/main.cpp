#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

enum Colours{green, yellow, red, blue, black, white};
enum Direction{up, down, left, right};

struct Configuration{
    int combination1[6];
    int combination2[6];
    Direction correctPick;
};

string currentTime(){
    time_t now = time(0);
    tm* localtm = localtime(&now);
    return asctime(localtm);
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
