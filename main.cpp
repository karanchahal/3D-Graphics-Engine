#include "game.h"

int main()
{

    Game g;
    Point a;
    a.x = 100;
    a.y = 100;

    Point a_t;
    a.x = 50;
    a.y = 10;

    Point b;
    a.x = 100;
    a.y = 200;

    Point b_t;
    a.x = 100;
    a.y = 50;

    Curves c;
    c.drawHermiCurve(a,a_t,b,b_t,RED);




    getch();
    delete m;
    return 0;
}
