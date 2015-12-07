#include "game.h"

int main()
{



    Game g;

    vector<Point> points;
    Point point;
    point.x = 100;
    point.y = 100;

    points.push_back(point);

    point.x = 100;
    point.y = 200;

    points.push_back(point);

    point.x = 200;
    point.y = 200;

    points.push_back(point);

    point.x = 200;
    point.y = 100;

    points.push_back(point);
    Polygons rectangle(points,RED);
    rectangle.display();

    Color colorthis(rectangle,RED,0);









    getch();

    return 0;
}
