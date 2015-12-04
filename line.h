#pragma once
#include "plot.h"


class Line{

public:

    Line(int x1,int y1,int x2,int y2,int COLOR)
    {
         int dx = x2-x1,
           dy =y2- y1,
           dT = 2*(dy-dx),
           dS = 2*dy,
           d = 2*dy - dx;

           int x = x1,y =y1;
           plot(x,y,COLOR);

           while(x <= x2)
           {
               x++;
               if(d > 0)
               {
                    y++;
                    d = d+dT;
               }
               else
               {
                    d = d + dS;
               }

               plot(x,y,COLOR);
           }
    }




};
