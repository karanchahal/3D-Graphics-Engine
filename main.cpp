#include "game.h"

int main()
{
    Game* game =new Game();
    //game->ellipse(100,50,200,200,CYAN);*/
    //game->line(200,100,500,300,RED);
    //game->circle(300,300,50,GREEN);

    vector<Point> rectange_points;

    Point temp_point;
    temp_point.x = 100;
    temp_point.y = 100;
    rectange_points.push_back(temp_point);
    temp_point.x = 200;
    temp_point.y = 100;
    rectange_points.push_back(temp_point);
    temp_point.x = 200;
    temp_point.y = 200;
    rectange_points.push_back(temp_point);
    temp_point.x = 100;
    temp_point.y = 200;
    rectange_points.push_back(temp_point);


    Polygons rectange(rectange_points,GREEN);
    rectange.display();
    getch();
    delete game;
    return 0;
}
