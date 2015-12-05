#include "basicfunctions.h"

int main()
{
    Game* game =new Game();
    game->ellipse(100,50,200,200,CYAN);
    game->line(200,100,500,300,RED);
    game->circle(300,300,50,GREEN);

    getch();
    delete game;
    return 0;
}
