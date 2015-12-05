#pragma once
#include "plot.h"


class Elipse{
public:
     Elipse(int a,int b,int xCenter,int yCenter,int COLOR)
     {
        int x =0,y =b;
        int aa = a*a,bb = b*b;
        int aa2 = 2*aa,bb2 = bb*2;
        int fx =0,fy = aa2*b;
        int p = bb -aa*b + 0.25*aa;

        while(fx < fy)
        {
            plotEllipse(x,y,xCenter,yCenter,COLOR);
            x++;
            fx = fx + bb2;

            if(p < 0)
                p += fx + bb;
            else
            {
                y--;
                fy = fy -aa2;
                p = p + fx + bb -fy;
            }
        }
        plotEllipse(x,y,xCenter,yCenter,COLOR);

        p = bb*(x + 0.5)*(x + 0.5) + aa*(y-1)*(y-1) - aa*bb;

        while(y > 0)
        {
            y--;
            fy = fy - aa2;

            if(p >= 0)
                p = p -fy +aa;
            else
            {
                x++;
                fx = fx + bb2;
                p = p+fx-fy+aa;
            }
            plotEllipse(x,y,xCenter,yCenter,COLOR);
        }
     }

     void plotEllipse(int x,int y,int xCenter,int yCenter,int COLOR)
     {
         plot(x + xCenter,y + yCenter,COLOR);
         plot(xCenter -x,y + yCenter,COLOR);
         plot(x + xCenter,-y + yCenter,COLOR);
         plot(-x+xCenter,-y + yCenter,COLOR);
     }

};
