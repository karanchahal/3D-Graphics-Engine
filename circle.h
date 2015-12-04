#pragma once
#include "plot.h"

class Circle{

public:

    Circle(int xCenter,int yCenter,int radius,int COLOR)
    {
        int x = 0,y = radius,p = 1-radius;

        while(x <= y)
        {
            plotCircle(x,y,xCenter,yCenter,COLOR);
            if(p < 0)
            {
                p = p + 2*x + 3;
            }
            else
            {
                p = p + 2*(x-y) + 5;
                y--;
            }
            x++;

        }
    }

    void plotCircle(int x,int y,int xCenter,int yCenter,int COLOR)
    {
        plot(xCenter + x,yCenter + y,COLOR);
        plot(xCenter - x,yCenter + y,COLOR);
        plot(xCenter + x,yCenter - y,COLOR);
        plot(xCenter - x,yCenter - y,COLOR);
        plot(xCenter + y,yCenter + x,COLOR);
        plot(xCenter - y,yCenter + x,COLOR);
        plot(xCenter + y,yCenter - x,COLOR);
        plot(xCenter - y,yCenter - x,COLOR);
    }







};

