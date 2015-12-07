#pragma once

#include "plot.h"
#include "line.h"
#include "circle.h"
#include "ellipse.h"
#include "polygon.h"
#include "matrix.h"
#include "curves.h"
#include "colour.h"
#include "transformation.h"



class Game{

public:
    Game()
    {
        int gd = DETECT, gm;
        initgraph(&gd, &gm, "C:\\TC\\BGI");
    }

    void line(int x1,int y1,int x2,int y2,int COLOR)
    {
        Line line(x1,y1,x2,y2,COLOR);

    }

    void circle(int xCenter,int yCenter,int radius,int COLOR)
    {
        Circle circle(xCenter,yCenter,radius,COLOR);

    }

    void ellipse(int a,int b,int xCenter,int yCenter,int COLOR)
    {
       Elipse e(a,b,xCenter,yCenter,COLOR);

    }


    ~Game()
    {
        cout<<"Game ended.."<<endl;
    }

};
