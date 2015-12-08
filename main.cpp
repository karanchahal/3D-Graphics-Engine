#include "game.h"
#include<conio.h>
#include <stdlib.h>
int main()
{



    Game g;

    for(int i=0;i<100;i++)
    {
        Cuboid c(50);
        c.setcolors(RED,WHITE,GREEN,BLUE,CYAN,MAGENTA);
        c.translate(360,240,0);

        c.rotatex(i);
        c.rotatey(i);
        c.view_z(GREEN);
        delay(20);
        c.deletor(GREEN);

    }














    getch();

    return 0;
}
