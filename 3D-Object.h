#include<bits/stdc++.h>
#include<graphics.h>
#define PI 3.14159
struct point_3d
{
    float x,y,z;
};

class polygon_3d
{

    public : vector<Line*> lines;
    public: vector< vector <point_3d> > point_list;
    public: vector< vector <point_3d> > corner_list;
    public: vector<point_3d> normal_list;
    public: vector<bool> visible_list;
    public: vector <int> color_list;
    public : int no_sides;
    public:void putpoint(int x,int y,int colour)
    {
        putpixel(x+320,240-y,colour);
    }
    public : void show_corners()
    {
        for(int i = 0;i<no_sides;i++)
        {
            for(int j=0;j<corner_list[i].size();j++)
            {
                cout<<corner_list[i][j].x<<"\t";;
                cout<<corner_list[i][j].y<<"\t";
                cout<<corner_list[i][j].z<<"\t";
            }
            cout<<endl;
        }

    }
    public: void translate(int xt,int yt,int zt)
    {

        for(int i = 0;i<no_sides;i++)
        {
            for(int j=0;j<corner_list[i].size();j++)
            {
                corner_list[i][j].x +=xt;
                corner_list[i][j].y +=yt;
                corner_list[i][j].z +=zt;
            }
        }
    }
    public : void rotatex(float angle)
    {
        float radians = (PI/180)*angle;

        for(int i = 0;i<no_sides;i++)
        {
            for(int j=0;j<corner_list[i].size();j++)
            {
                float yold = corner_list[i][j].y;
                float zold = corner_list[i][j].z;
                corner_list[i][j].y = yold*cos(radians) - zold*sin(radians);
                corner_list[i][j].z = zold*cos(radians) + yold*sin(radians);
            }
        }
        for(int i = 0;i< no_sides;i++)
        {
            float yold = normal_list[i].y;
            float zold = normal_list[i].z;
            normal_list[i].y = yold*cos(radians) - zold*sin(radians);
            normal_list[i].z = zold*cos(radians) + yold*sin(radians);
        }
        for(int i=0;i< no_sides;i++)
        {
            if(normal_list[i].z>0)
                visible_list[i] = true;
            else visible_list[i] = false;
        }
    }
    public : void rotatey(float angle)
    {
        float radians = (PI/180)*angle;
        for(int i = 0;i<no_sides;i++)
        {
            for(int j=0;j<corner_list[i].size();j++)
            {
                float zold = corner_list[i][j].z;
                float xold = corner_list[i][j].x;
                corner_list[i][j].z = zold*cos(radians) - xold*sin(radians);
                corner_list[i][j].x = xold*cos(radians) + zold*sin(radians);
            }
        }
        for(int i = 0;i< no_sides;i++)
        {

            float zold = normal_list[i].z;
            float xold = normal_list[i].x;
            normal_list[i].z = zold*cos(radians) - xold*sin(radians);
            normal_list[i].x = xold*cos(radians) + zold*sin(radians);
        }
        for(int i=0;i< no_sides;i++)
        {
            if(normal_list[i].z>0)
                visible_list[i] = true;
            else visible_list[i] = false;
        }

    }
    public : void rotatez(float angle)
    {
        float radians = (PI/180)*angle;
        for(int i = 0;i<no_sides;i++)
        {
            for(int j=0;j<corner_list[i].size();j++)
            {
                float xold = corner_list[i][j].x;
                float yold = corner_list[i][j].y;
                corner_list[i][j].x = xold*cos(radians) - yold*sin(radians);
                corner_list[i][j].y = yold*cos(radians) + xold*sin(radians);
            }
        }
        for(int i = 0;i< no_sides;i++)
        {
            float xold = normal_list[i].x;
            float yold = normal_list[i].y;
            normal_list[i].x = xold*cos(radians) - yold*sin(radians);
            normal_list[i].y = yold*cos(radians) + xold*sin(radians);
        }
        for(int i=0;i< no_sides;i++)
        {
            if(normal_list[i].z>0)
                visible_list[i] = true;
            else visible_list[i] = false;
        }

    }
    public : void view_z(int colour)
    {
        for(int i=0;i<no_sides;i++)
        {
            if(visible_list[i]==false)continue;
            for(int j=0;j<corner_list[i].size();j++)
            {
                Line *temp = new Line(corner_list[i][j].x,corner_list[i][j].y,corner_list[i][(j+1)%corner_list[i].size()].x,corner_list[i][(j+1)%corner_list[i].size()].y);
                lines.push_back(temp);
            }
        }
        for(int i = 0;i<lines.size();i++)
        {
            lines[i]->draw_object(colour);
        }
    }

    public : void scale(float xs,float ys,float zs)
    {
        for(int i = 0;i<no_sides;i++)
        {
            for(int j=0;j<corner_list[i].size();j++)
            {
                corner_list[i][j].x *=xs;
                corner_list[i][j].y *=ys;
                corner_list[i][j].z *=zs;
            }
        }
    }
    public : void view_z_color(int color)
    {
        for(int i=0;i<no_sides;i++)
        {
            if(visible_list[i]==false)continue;
            for(int j=0;j<corner_list[i].size();j++)
            {
                Line *temp = new Line(corner_list[i][j].x,corner_list[i][j].y,corner_list[i][(j+1)%corner_list[i].size()].x,corner_list[i][(j+1)%corner_list[i].size()].y);
                lines.push_back(temp);
            }
        }
        for(int i = 0;i<lines.size();i++)
        {
            lines[i]->draw_object(color);
        }
        for(int i=0;i<no_sides;i++)
        {
            float xcenter = 0;float ycenter  = 0;
            if(visible_list[i]==false)continue;
            for(int j=0;j<corner_list[i].size();j++)
            {
                xcenter+= corner_list[i][j].x;
                ycenter+=corner_list[i][j].y;
            }
            xcenter/=corner_list[i].size();
            ycenter/=corner_list[i].size();
            setfillstyle(SOLID_FILL,color_list[i]);
            floodfill(xcenter,ycenter,color);

        }




    }








    public: void deletor(int COLOR)
    {
        for(int i=0;i<no_sides;i++)
        {
            float xcenter = 0;float ycenter  = 0;
            if(visible_list[i]==false)continue;
            for(int j=0;j<corner_list[i].size();j++)
            {
                xcenter+= corner_list[i][j].x;
                ycenter+=corner_list[i][j].y;
            }
            xcenter/=corner_list[i].size();
            ycenter/=corner_list[i].size();
            Color c;
            Point p;
            p.x = (double)xcenter;
            p.y =(double)ycenter;
            c.seedfillforpolygons(p,BLACK,COLOR);
        }
        for(int i=0;i<no_sides;i++)
        {
            if(visible_list[i]==false)continue;
            for(int j=0;j<corner_list[i].size();j++)
            {
                Line *temp = new Line(corner_list[i][j].x,corner_list[i][j].y,corner_list[i][(j+1)%corner_list[i].size()].x,corner_list[i][(j+1)%corner_list[i].size()].y);
                lines.push_back(temp);
            }
        }
        for(int i = 0;i<lines.size();i++)
        {
            lines[i]->draw_object(BLACK);
        }

    }





};
