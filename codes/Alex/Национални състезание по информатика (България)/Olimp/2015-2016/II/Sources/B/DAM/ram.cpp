#include <iostream>
using namespace std;
int Rows[1000];
int Columns[1000];
int c=0;
int br=0;
bool direction=true;
int broken=0;
int get_Broken=0;
int x=1,y=1;
bool FirstIf = true;
bool SecondIf = true;
int CountBroken(int rows,int columns)
{
    x=1;
    y=1;
    broken=0;
    direction=true;
    while (true)
    {
        if (direction)
        {
            y++;
            direction=false;
            broken++;
        }
        if (x>rows)
        {
            return broken;
            break;
        }
        if (y>columns)
        {
            return broken;
            break;
        }
        if (!direction)
        {
            x++;
            direction=true;
            broken++;
        }
        if (x>rows)
        {
            return broken;
            break;
        }
        if (y>columns)
        {
            return broken;
            break;
        }
    }
}
int main ()
{
    int K;
    cin>>K;
    int first=0;
    for (int i=1; FirstIf; i++)
    {
        if (i>K) FirstIf=false;
        first = 3*i+1;
        SecondIf=true;
        for (int j=1; SecondIf; j++)
        {
            if(first>K)
            {
                get_Broken=CountBroken(i,j);
                if (first==K+get_Broken)
                {
                    Rows[c]=i;
                    Columns[c]=j;
                    c++;
                    br++;
                }
            }
            first+=2*i+1;
            if (j>(K+i+1)/(2*i+1)) SecondIf=false;
        }
    }
    for (int i=0; i<c-1; i++)
    {
        for (int j=0; j<c-1; j++)
        {
            if (Rows[j]>Rows[j+1])
            {
                swap(Rows[j],Rows[j+1]);
                swap(Columns[j],Columns[j+1]);
            }
        }
    }
    cout<<br<<endl;
    for (int i=0; i<c; i++)
    {
        cout<<Rows[i]<<" "<<Columns[i]<<endl;
    }

    return 0;
}
/**
M*N*4-(M-1)*N-(N-1)*M=
= 2*M*N+M+N
*/
