#pragma once
#include<iostream>
#include<graphics.h>
#include<vector>
#include<math.h>

#define Pi 3.14

using namespace std;

struct Point
{
    double x,y,z;
};


void plot(int x,int y,int COLOR)
{
    putpixel(x,y,COLOR);
}
void clearscreen()
{
    for(int i=0;i<200;i++)
    {
        for(int j =0;j<200;j++)
        {
            plot(i,j,BLACK);
        }
    }
}

int getPixelColour(int x,int y)
{
    return getpixel(x,y);
}

