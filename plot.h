#pragma once
#include<iostream>
#include<graphics.h>
#include<vector>

using namespace std;

struct Point
{
    int x,y;
};

void plot(int x1,int y1,int COLOR)
{
    putpixel(x1,y1,COLOR);
}

