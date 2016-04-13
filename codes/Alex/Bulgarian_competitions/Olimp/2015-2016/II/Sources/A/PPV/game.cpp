#include <iostream>
#include <cmath>
#define Num 12000
using namespace std;
struct Point
{
    int x,y,r;
};
Point Np[Num];
int S[Num];
int main()
{
    int N,M,Q;
    cin>>N>>M>>Q;
    for(int i=1;i<=N;i++)
    {
        cin>>Np[i].x>>Np[i].y>>Np[i].r;
    }
    Point Mp;
    cin>>Mp.x>>Mp.y;
    for(int i=1;i<=Q;i++)
    {
        cin>>S[i];
    }
    int fin=0,res=1;
    double d;
    for(int i=1;i<=Q;i++)
    {
        //cout<<res<<endl;
        if(res%2==0)S[i]=S[i]*2;
        res=0;

        for(int j=1;j<=N;j++)
        {
            d = sqrt((Np[j].x-Mp.x)*(Np[j].x-Mp.x)+(Np[j].y-Mp.y)*(Np[j].y-Mp.y));
            if(S[i]>=d+Np[j].r)res++;
        }
        fin+=res;
    }
    cout<<fin<<endl;
}
/*
4 1 3
2 2 1
3 5 2
6 2 3
8 8 1
4 4
4 3 3
*/
