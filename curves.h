#pragma once
#include "plot.h"

class Curves
{

public:


    Curves()
    {

    }

    double hermiPoints(double t,Point a1,Point at1,Point a2,Point at2,int flag)
    {
        if(flag == 0)
        {
            double x1 = (2*pow(t,3) - 3*pow(t,2) +1)*a1.x;
            double x2 = ( (-2)*pow(t,3) + 3*pow(t,2))*a2.x;
            double x3 = (pow(t,3)-2*pow(t,2)+t)*at1.x;
            double x4 = (pow(t,3)-pow(t,2))*at2.x;

            return x1+x2+x3+x4;
        }
        else
        if(flag == 1)
        {
            double x1 = (2*pow(t,3) - 3*pow(t,2) +1)*a1.y;
            double x2 = ( (-2)*pow(t,3) + 3*pow(t,2))*a2.y;
            double x3 = (pow(t,3)-2*pow(t,2)+t)*at1.y;
            double x4 = (pow(t,3)-pow(t,2))*at2.y;

            return x1+x2+x3+x4;
        }

    }

    void drawHermiCurve(Point a1,Point at1,Point a2,Point at2,double COLOR)
    {
        double prevx = -1,prevy = -1;
        double x,y;

        for(double t =0;t <=1 ; t+=0.001)
        {
            x = hermiPoints(t,a1,at1,a2,at2,0);
            y = hermiPoints(t,a1,at1,a2,at2,1);

            if(prevx == -1)
            {
                prevx = x;
                prevy = y;
            }

            Line l(prevx,prevy,x,y,COLOR);
            prevx = x;
            prevy = y;

        }

    }

    void drawBezierCurve (Point a1,Point a2,Point a3,Point a4,int COLOR)
    {

        double t;
        for (t = 0.0; t < 1.0; t += 0.001)
        {
        double xt = pow (1-t, 3) * a1.x + 3 * t * pow (1-t, 2) * a2.x +
                3 * pow (t, 2) * (1-t) * a3.x + pow (t, 3) * a4.x;

        double yt = pow (1-t, 3) * a1.y + 3 * t * pow (1-t, 2) * a2.y +
                3 * pow (t, 2) * (1-t) * a3.y + pow (t, 3) * a4.y;

        plot(xt, yt, WHITE);
        }




    }


};
