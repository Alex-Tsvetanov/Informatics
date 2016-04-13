#include <cstdio>
#include <iostream>
using namespace std;

short int a[1001][1001];

int main()
{
    int N,M,T,x,y;
    scanf("%d%d%d",&N,&M,&T);
    while(cin>>x>>y)
    {
        a[x][y]=1;
    }
    for(int i=0; i<T; i++)
    {
        for(int j=1; j<=N; j++)
        {
            for(int k=1; k<=M; k++)
            {
                if(a[j][k]==1)
                {
                    if(a[j][k+1]==0)a[j][k+1]=2;
                    if(a[j][k-1]==0)a[j][k-1]=2;
                    if(a[j+1][k]==0)a[j+1][k]=2;
                    if(a[j-1][k]==0)a[j-1][k]=2;
                }
            }
        }
        for(int j=1; j<=N; j++)
        {
            for(int k=1; k<=M; k++)
            {
                if(a[j][k]==2)
                {
                    a[j][k]=1;
                }
            }
        }


    }
    short int summ=0;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            if(a[i][j]==0)summ++;
        }
    }
    cout<<summ<<endl;
    return 0;
}
