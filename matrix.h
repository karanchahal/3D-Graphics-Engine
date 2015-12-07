#pragma once
#include "plot.h"

class Matrix{

public:
    vector<vector<double> > result;

    Matrix(double height)
    {
        result.resize(height);
    }

    vector<vector<double> > init(double a1[20],double a2[20],double a3[20],double height,double width)
    {
        vector< vector<double> > A(height);

        for(int i=0;i<width;i++)
        {
            A[0].push_back(a1[i]);
            A[1].push_back(a2[i]);
            A[2].push_back(a3[i]);
        }

        return A;
    }

    vector<vector<double> > multiply(vector< vector<double> > A,vector< vector<double> > B)
    {

        if(A[0].size() != B.size())
        {
            return result;
        }


        for(double i=0;i<A.size();i++)
        {
            for(double j=0;j<B[0].size();j++)
            {
                double sum =0;
                for(double k=0;k<A[0].size();k++)
                {
                    sum += A[i][k]*B[k][j];
                }

                result[i].push_back(sum);
            }
        }
        return result;
    }


    void display()
    {
        for(int i=0;i<result.size();i++)
        {
            for(int j=0;j<result[0].size();j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void display_matrix(vector<vector<double> > M)
    {
         for(int i=0;i<M.size();i++)
        {
            for(int j=0;j<M[0].size();j++)
            {
                cout<<M[i][j]<<" ";
            }
            cout<<endl;
        }
    }


};
