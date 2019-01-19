#include <iostream>
#include<windows.h>
using namespace std;
class matrixes
{
private:
    int matrix[3][3];
    int determinant;
public:
    matrixes(int mat[3][3]);
    matrixes();
    void calculateDeterminant()
    {
        determinant = matrix[0][0]*(matrix[1][1]*matrix[2][2]-matrix[2][1]*matrix[1][2]) - matrix[0][1]*(matrix[1][0]*matrix[2][2]-matrix[2][0]*matrix[1][2]) + matrix[0][2]*(matrix[1][0]*matrix[2][1]-matrix[2][0]*matrix[1][1]);
    }
    int getDeterminant()
    {
        return determinant;
    }
    void showmatrixes();
};
matrixes::matrixes()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            matrix[i][j] = 0;
        }
    }
    calculateDeterminant();
}
matrixes::matrixes(int mat[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            matrix[i][j] = mat[i][j];
        }
    }
    calculateDeterminant();
}

void matrixes::showmatrixes()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}


class lineareqn
{
private:
    int val[3][4];
    int det[4][3][3];
    matrixes m,m1,m2,m3;
public:
    lineareqn()
    {
        cout<<"Enter a1, b1, c1 and d1 of linear equation:"<<endl;
        cin>>val[0][0]>>val[0][1]>>val[0][2]>>val[0][3];
        cout<<"Enter a1, b1, c1 and d1 of linear equation:"<<endl;
        cin>>val[1][0]>>val[1][1]>>val[1][2]>>val[1][3];
        cout<<"Enter a1, b1, c1 and d1 of linear equation:"<<endl;
        cin>>val[2][0]>>val[2][1]>>val[2][2]>>val[2][3];
        creatematrix();

    }
    void creatematrix()
    {
        for(int i=0;i<3;i++)
        {
            for(int j = 0;j <4;j++)
            {
                if(j!=3)
                {
                    det[0][i][j] = val[i][j];
                }
                if(j!=0)
                {
                    if(j==3)
                    {
                        det[1][i][0] = val[i][j];
                    }else
                    {
                        det[1][i][j] = val[i][j];
                    }
                }
                if(j!=1)
                {
                    if(j==3)
                    {
                        det[2][i][1] = val[i][j];
                    }else
                    {
                        det[2][i][j] = val[i][j];
                    }
                }
                if(j!=2)
                {
                    if(j==3)
                    {
                        det[3][i][2] = val[i][j];
                    }else
                    {
                        det[3][i][j] = val[i][j];
                    }
                }
            }
        }
        m = det[0];
        cout<<endl<<"Delta"<<endl;
        m.showmatrixes();
        cout<<m.getDeterminant();
        cout<<endl;
        m1 = det[1];
        cout<<endl<<"Delta1"<<endl;
        m1.showmatrixes();
        cout<<m1.getDeterminant();
        cout<<endl;
        m2 = det[2];
        cout<<endl<<"Delta2"<<endl;
        m2.showmatrixes();
        cout<<m2.getDeterminant();
        cout<<endl;
        m3 = det[3];
        cout<<endl<<"Delta3"<<endl;
        m3.showmatrixes();
        cout<<m3.getDeterminant();
        cout<<endl;
    }
    void showresult()
    {
        if(m.getDeterminant()!=0)
            cout<<"The value of (x,y,z) is: ("<<(float)m1.getDeterminant()/m.getDeterminant()<<", "<<(float)m2.getDeterminant()/m.getDeterminant()<<", "<<(float)m3.getDeterminant()/m.getDeterminant()<<")";
        else
            cout<<"No solution";
    }
};




int main()
{
    lineareqn l;
    l.showresult();
    cout<<endl;
    system("pause");
    return 0;
}
