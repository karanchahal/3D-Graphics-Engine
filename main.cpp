#include "game.h"

int main()
{

    Game g;
    Matrix* m = new Matrix(3);
    int a1[20] = {1,0,0};
    int a2[20] = {0,1,0};
    int a3[20] = {0,0,1};
    int b1[20] ={1,2,4};
    int b2[20] = {2,1,3};
    int b3[20] = {1,1,1};
    vector< vector<int> > A = m->init(a1,a2,a3,3,3);
    vector< vector<int> > B = m->init(b1,b2,b3,3,3);

    m->multiply(A,B);
    m->display();




    getch();
    delete m;
    return 0;
}
