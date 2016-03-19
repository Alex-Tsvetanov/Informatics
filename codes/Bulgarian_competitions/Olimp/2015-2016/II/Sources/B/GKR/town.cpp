#include<iostream>
#include<iomanip>
using namespace std;
long long graph[200][200],n,a,b,m,q,p,flag=0,br=0;
void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(graph[i][j]>graph[i][k]+graph[k][j])
                {
                    graph[i][j]=graph[i][k]+graph[k][j];
                }
            }
        }
    }
}
int main()
{
    cin>>n>>a>>b>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            graph[i][j]=9999;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cin>>q>>p;
        graph[q][p]=1;
        graph[p][q]=1;
        if(a==q) flag=1;
    }
    if(flag!=1) cout<<"X";
    else
    {
        floyd();
        for(int i=1;i<=n;i++) graph[i][i]=0;
        cout<<graph[a][b];
    }
    return 0;
}
