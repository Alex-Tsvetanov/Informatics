#include<iostream>
using namespace std;
long long table[202][202],maxbr=1,m,n;
void s3archwh1t3s(int x,int y)
{
    table[x][y]=maxbr;
    if(table[x-1][y]==0)
        s3archwh1t3s(x-1,y);
    if(table[x+1][y]==0)
        s3archwh1t3s(x+1,y);
    if(table[x][y+1]==0)
        s3archwh1t3s(x,y+1);
    if(table[x][y-1]==0)
        s3archwh1t3s(x,y-1);
}
int main()
{
    cin>>m>>n;
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            cin>>table[i][j];
    for(int i=0; i<=m+1; i++)
    {
        table[i][0]=table[i][n+1]=40001;
    }
    for(int i=0; i<=n+1; i++)
    {
        table[0][i]=table[m+1][i]=40001;
    }
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            if(table[i][j]==0)
            {
                s3archwh1t3s(i,j);
                maxbr++;
            }
    maxbr--;
    cout<<maxbr<<endl;
    return 0;
}
