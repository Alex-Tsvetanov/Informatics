#include<iostream>
#include<vector>
using namespace std;
int n,a,b,used[400000],d[400000],br=0,ak[20000][20000];
void Read()
{
    int i,x,y;
    cin>>n>>a>>b;
  while(!cin.eof())
    {
        cin>>x>>y;
        ak[x][y]=1;
        br++;
    }
}
void init()
{
    int i,j;
    for(i=0;i<br;i++)
    {
        for(j=0;j<br;j++)
        {
            if(ak[i][j]==0)
            {
                ak[i][j]=5000000;
            }

        }
    }
    for(i=0;i<br;i++)
    {
        d[i]=ak[a][i];
    }
    d[a]=0;
}
void dij(int s)
{
    int i,j,u,md;
    used[s]=1;
    for(i=0;i<=br-2;i++)
    {
        md=5000000;
        for(j=0;j<br;j++)
        {
            if(used[j]==0)
            {
                if(d[j]<md)
                {
                    u=j;
                    md=d[j];
                }
            }
        }
    }
    used[u]=1;
    for(i=0;i<br;i++)
    {
        if(d[u]>d[j]+ak[u][j])
        {
            d[u]=d[j]+ak[u][j];
        }
    }
}
int main()
{
    Read();
    init();
    dij(b);
    cout<<d[b]<<endl;
return 0;
}
