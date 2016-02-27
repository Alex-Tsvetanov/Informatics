#include <iostream>
#define MAX 1002
using namespace std;
unsigned int a[MAX][MAX];
int x[10],y[10];
int main ()
{
    int N,M,T,br=0;
    cin>>N>>M>>T;
    for(int i=0; cin; i++)
    {
        cin>>x[i]>>y[i];
    }
    if (x[1]==0 and y[1]==0)
    {
        a[x[0]][y[0]]=1;
    }
    else
    {
        a[x[0]][y[0]]=1;
        a[x[1]][y[1]]=1;
    }
    for (int k=0; k<T; k++)
    {
        for (int i=1; i<=N; i++)
        {
            for (int j=1; j<=M; j++)
            {
                if (a[i][j]==k+1)
                {
                    if (a[i-1][j]==0) a[i-1][j]=k+2;
                    if (a[i][j-1]==0) a[i][j-1]=k+2;
                    if (a[i+1][j]==0) a[i+1][j]=k+2;
                    if (a[i][j+1]==0) a[i][j+1]=k+2;
                }
            }
        }
    }
    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=M; j++)
        {
            if (a[i][j]==0) br++;
        }
    }
    cout<<br<<endl;
    return 0;
}
