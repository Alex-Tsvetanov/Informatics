#include<iostream>
using namespace std;

int grid[208][208];
int brw;
int m,n;

int brn=1;
int wx=0,wy=0;

void zap(int x, int y)
{
    grid[x][y]=brn;

    if(y<n-1)
        if(grid[x][y+1]==0)
            zap(x,y+1);
    if(y>0)
        if(grid[x][y-1]==0)
            zap(x,y-1);
    if(x<m-1)
        if(grid[x+1][y]==0)
            zap(x+1,y);
    if(x>0)
        if(grid[x-1][y]==0)
            zap(x-1,y);
}

void findw()
{
    wx=-1, wy=-1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==0)
            {
                wx=i;
                wy=j;

                j=n;
                i=m;
            }
        }
    }
}

int main()
{
    cin>>m>>n;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]==1)
                grid[i][j]=-1;
            else brw++;
        }
    }

    bool y=true;

    while(y)
    {
        zap(wx,wy);
        findw();

        if(wx<0)
            y=false;

        brn++;

       /* for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==-1)
                    cout<<"- ";
                else
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;*/

    }
    cout<<brn-1<<endl;
    return 0;
}
// 2 4 0 1 1 0 0 0 1 1
// 7 6 0 1 0 1 0 0 0 1 0 1 0 0 0 0 1 1 0 0 0 0 1 0 1 0 1 1 1 0 0 0 0 0 1 1 1 1 0 1 0 1 0 0
