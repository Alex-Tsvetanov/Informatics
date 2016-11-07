#include<iostream>
using namespace std;
int m,n,br=1,c[201][201];
int pr(int x,int y)
{
    c[x][y]=br;
    if(x+1<m && c[x+1][y]==0)pr(x+1,y);
    if(x-1>=0 && c[x-1][y]==0)pr(x-1,y);
    if(y+1<n && c[x][y+1]==0)pr(x,y+1);
    if(y-1>=0 && c[x][y-1]==0)pr(x,y-1);
    return 0;
}

int main()
{
    int i,j;
    cin>>m>>n;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>c[i][j];
        }
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(c[i][j]==0)
            {
                pr(i,j);br++;
            }
        }
    }
    cout<<br-1<<endl;
    return 0;
}
//5 7 0 1 0 1 0 1 0 0 0 0 1 0 0 0 1 1 0 0 1 0 1 0 1 1 0 1 1 0 1 0 0 0 1 0 0