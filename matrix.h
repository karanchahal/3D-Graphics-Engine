#pragma once
#include "plot.h"

class Matrix{

private:
    vector< vector<int> > result;

public:
    Matrix(int height)
    {
        result.resize(height);
    }

    vector<vector<int> > init(int a1[20],int a2[20],int a3[20],int height,int width)
    {
        vector< vector<int> > A(height);

        for(int i=0;i<width;i++)
        {
            A[0].push_back(a1[i]);
            A[1].push_back(a2[i]);
            A[2].push_back(a3[i]);
        }

        return A;
    }

    vector<vector<int> > multiply(vector< vector<int> > A,vector< vector<int> > B)
    {

        if(A[0].size() != B.size())
        {
            return result;
        }


        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<B[0].size();j++)
            {
                int sum =0;
                for(int k=0;k<A[0].size();k++)
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




};
