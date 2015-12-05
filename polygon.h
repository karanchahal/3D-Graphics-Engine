#pragma once
#include "plot.h"


class Polygons
{
private:
    vector<Point> points;
    int COLOR;

public:
    Polygons(vector<Point> points,int COLOR)
    {
        this->points = points;
        this->COLOR = COLOR;

    }

    void display()
    {

        for(int i=0;i<points.size();i++)
        {
            if(i == points.size() - 1)
            {
                Line line(points[i].x,points[i].y,points[0].x,points[0].y,COLOR);
            }
            else
            {
                Line line(points[i].x,points[i].y,points[i+1].x,points[i+1].y,COLOR);
            }

        }
    }




};
