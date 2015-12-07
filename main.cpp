#include "game.h"

int main()
{



    Game g;

    double a1[20] = {100,100,200};
    double a2[20] = {100,200,300};
    double a3[20] = {1,1,1};

    double b1[20] = {1,0,10};
    double b2[20] = {0,1,10};
    double b3[20] = {0,0,1};
    Matrix m(3);

    vector<vector<double> > A = m.init(a1,a2,a3,3,3);
    vector<vector<double> > B = m.init(b1,b2,b3,3,3);

    m.multiply(B,A);
    //m.display();
    cout<<endl;
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

    Transform t;

    rectangle = t.translate(rectangle,10,10,0,GREEN);

    Color colorthistoo(rectangle,GREEN,0);










    getch();

    return 0;
}
