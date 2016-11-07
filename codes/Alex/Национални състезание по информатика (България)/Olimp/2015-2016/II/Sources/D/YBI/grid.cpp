#include<iostream>
using namespace std;
int m,n,whites=0,res=0;
int chess[200][200];
void infect(int x,int y, int a)
{
    chess[x][y]=a;
    whites--;
    if(x!=0&&chess[x-1][y]==0)
    {
        infect(x-1,y,a);
    }
    if(y!=0&&chess[x][y-1]==0)
    {
        infect(x,y-1,a);
    }
    if(x!=n-1&&chess[x+1][y]==0)
    {
        infect(x+1,y,a);
    }
    if(y!=m-1&&chess[x][y+1]==0)
    {
        infect(x,y+1,a);
    }
}
int main()
{
    cin>>m>>n;
    for(int y=0;y<m;y++)
    {
        for(int x=0;x<n;x++)
        {
            cin>>chess[x][y];
            if(chess[x][y]==0)
            {
                whites++;
            }
        }
    }
    for(int y=0;y<m;y++)
    {
        for(int x=0;x<n;x++)
        {
            if(whites==0)
            {

                break;
            }
            if(chess[x][y]==0)
            {
               infect(x,y,++res);
            }
        }
    }
    cout<<res<<"\n";
    return 0;
}
