#pragma once
#include "plot.h"
#include "line.h"
#include "circle.h"
#include "ellipse.h"




class Game{

public:
    Game()
    {
        int gd = DETECT, gm;
        initgraph(&gd, &gm, "C:\\TC\\BGI");
    }

    void line(int x1,int y1,int x2,int y2,int COLOR)
    {
        Line* line = new Line(x1,y1,x2,y2,COLOR);
        delete line;
    }

    void circle(int xCenter,int yCenter,int radius,int COLOR)
    {
        Circle* circle = new Circle(xCenter,yCenter,radius,COLOR);
        delete circle;
    }

    void ellipse(int a,int b,int xCenter,int yCenter,int COLOR)
    {
         int x =0,y =b;
        int aa =a*a,bb =b*b,aa2 = aa*2,bb2 =bb*2;

        int fx =0,fy = aa2*b;
        int p = bb -aa*b + aa/4;
        while(fx < fy)
        {
            plotEllipse(x,y,xCenter,yCenter,COLOR);
            x++;
            fx = fx +bb2;
            if(p < 0)
                p = p+ fx + bb;
            else{
                y--;
                fy = fy - aa2;
                p = p+fx + bb -fy;
            }
        }
        plotEllipse(x,y,xCenter,yCenter,COLOR);

        p = bb*(x + 1/2)*(x + 1/2) + aa*(y -1)*(y-1) - a*bb;

        while(y > 0)
        {
            y--;
            fy = fy -aa2;
            if(p >= 0)
                p = p - fy + aa;
            else {
                x++;
                fx = fx + bb2;
                p = p + fx -fy +aa;
            }
            plotEllipse(x,y,xCenter,yCenter,COLOR);
        }

    }

    void plotEllipse(int x,int y,int xCenter,int yCenter,int COLOR)
    {
        plot(xCenter + x,yCenter + y,COLOR);
        plot(xCenter - x,yCenter + y,COLOR);
        plot(xCenter + x,yCenter - y,COLOR);
        plot(xCenter - x,yCenter - y,COLOR);

    }









    ~Game()
    {
        cout<<"Game ended.."<<endl;
    }

};
