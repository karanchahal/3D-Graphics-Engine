#include "basicfunctions.h"

int main()
{
    Game* game =new Game();
    game->ellipse(200,200,0,0,CYAN);

    getch();
    delete game;
    return 0;
}
