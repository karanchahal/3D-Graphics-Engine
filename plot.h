#pragma once
#include<iostream>
#include<graphics.h>
#include<vector>
#include<math.h>

using namespace std;

struct Point
{
    int x,y;
};

void plot(int x,int y,int COLOR)
{
    putpixel(x,y,COLOR);
}

int getPixelColour(int x,int y)
{
    return getpixel(x,y);
}

