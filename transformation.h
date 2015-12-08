#pragma once
#include "plot.h"

class Transform
{
private:

    vector< vector<double> > translateMatrix;
    vector< vector<double> > rotateMatrix;
    vector< vector<double> > scaleMatrix;


public:

    void init( vector<vector<double> > &M)
    {
        M.resize(4);
        for(int i = 0;i<4;i++)
        {
            for(int j =0;j <4;j++)
            {
                M[i].push_back(0);
                if(j == i)
                    M[i][j] = 1;
            }
        }
    }

    vector<Point> initPointMatrix(vector< vector<double> > M)
    {
        vector<Point> points;
        Point p;
        for(int i =0;i<M[0].size();i++)
        {
            p.x = M[0][i];
            p.y = M[1][i];

            points.push_back(p);
        }
        return points;
    }

    vector< vector<double> > initTransformMatrix(vector<Point> points)
    {
        vector< vector<double> > M;
        M.resize(4);

        for(int i=0;i<points.size();i++)
        {
            M[0].push_back(points[i].x);
            M[1].push_back(points[i].y);
            M[2].push_back(0);  // points[i].z
            M[3].push_back(1);
        }


        return M;



    }

    Transform()
    {
        init(translateMatrix);
        init(scaleMatrix);
        init(rotateMatrix);
    }



    Polygons translate(Polygons polygon ,int x,int y,int z,int COLOR)
    {
        vector< vector<double> > points_before;

        translateMatrix[0][3] = x;
        translateMatrix[1][3] = y;
        translateMatrix[2][3] = z;

        points_before = initTransformMatrix(polygon.points);

        Matrix m(4);

        m.multiply(translateMatrix,points_before);
        vector<Point> final_points = initPointMatrix(m.result);

        Polygons transformed_polygon(final_points,COLOR);


        return transformed_polygon;


    }

    Polygons scale(Polygons polygon ,int x,int y,int z,int COLOR)
    {
        vector< vector<double> > points_before;

        scaleMatrix[0][0] = x;
        scaleMatrix[1][1] = y;
        scaleMatrix[3][3] = z;

        points_before = initTransformMatrix(polygon.points);

        Matrix m(4);

        m.multiply(scaleMatrix,points_before);
        vector<Point> final_points = initPointMatrix(m.result);

        Polygons transformed_polygon(final_points,COLOR);

        return transformed_polygon;
    }

    void rotate()
    {

    }



};
