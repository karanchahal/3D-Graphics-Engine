#pragma once

class Color
{
 private:

 public:

    void seedfillforpolygons(Point point,int COLOR,int CORNER_COLOR)
    {
        Point temp;

        if(COLOR != getPixelColour(point.x,point.y) && CORNER_COLOR != getPixelColour(point.x,point.y))
        {
            plot(point.x,point.y,COLOR);
            temp.x = point.x +1;
            temp.y = point.y;
            seedfillforpolygons(temp,COLOR,CORNER_COLOR);

            temp.x = point.x;
            temp.y = point.y + 1;
            seedfillforpolygons(temp,COLOR,CORNER_COLOR);

            temp.x = point.x - 1;
            temp.y = point.y;
            seedfillforpolygons(temp,COLOR,CORNER_COLOR);

            temp.x = point.x;
            temp.y = point.y - 1;
            seedfillforpolygons(temp,COLOR,CORNER_COLOR);

        }
        return;
    }

    void seedfill(Point point,int COLOR)
    {
        Point temp;

        if(COLOR != getPixelColour(point.x,point.y))
        {
            plot(point.x,point.y,COLOR);
            temp.x = point.x +1;
            temp.y = point.y;
            seedfill(temp,COLOR);

            temp.x = point.x;
            temp.y = point.y + 1;
            seedfill(temp,COLOR);

            temp.x = point.x - 1;
            temp.y = point.y;
            seedfill(temp,COLOR);

            temp.x = point.x;
            temp.y = point.y - 1;
            seedfill(temp,COLOR);

        }
        return;
    }

    void scanfill(Polygons polygon,int COLOR)
    {

    }

    Color()
    {
        //nothing
    }

    Color(Polygons polygon,int COLOR,int flag)
    {
        if(flag == 0)
        {
            Point point;

            point.x = polygon.points[0].x + 1;
            point.y = (polygon.points[1].y - polygon.points[0].y)/2 + polygon.points[0].y;

            seedfill(point,COLOR);
        }
        else
        {
            scanfill(polygon,COLOR);
        }
    }

};
