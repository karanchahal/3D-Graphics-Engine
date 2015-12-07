#include "game.h"

int main()
{

    Game g;
    Point a;
    a.x = 100;
    a.y = 100;

    Point b;
    b.x = 0;
    b.y = 0;

    Point c;
    c.x = 150;
    c.y = 100;

    Point d;
    d.x = 0;
    d.y = 0;

    Curves curve;
    curve.drawHermiCurve(a,b,c,d,RED);




    getch();

    return 0;
}
