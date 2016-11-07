#include<iostream>
#include<queue>
using namespace std;
int mas[200][200],m,n,wave=1;
void dfs(int wave,int x,int y)
{
    mas[x][y]=wave;
    //cout<<x<<" "<<y<<endl;
    if(x!=0&&mas[x-1][y]==0)dfs(wave,x-1,y);
    if(y!=0&&mas[x][y-1]==0)dfs(wave,x,y-1);
    if(x!=m-1&&mas[x+1][y]==0)dfs(wave,x+1,y);
    if(y!=n-1&&mas[x][y+1]==0)dfs(wave,x,y+1);
}
int main()
{
    cin>>m>>n;
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    {
        cin>>mas[i][j];
    }
    /*
    for(int i=0;i<m;i++)
    {
       for(int j=0;j<n;j++)
        {
        cout<<mas[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    {
        // cout<<i<<" "<<j;
        if(mas[i][j]==0){dfs(wave,i,j);wave++;}

    }
    cout<<wave-1<<endl;
    return 0;
}
//2 4 0 1 1 0 0 0 1 1
