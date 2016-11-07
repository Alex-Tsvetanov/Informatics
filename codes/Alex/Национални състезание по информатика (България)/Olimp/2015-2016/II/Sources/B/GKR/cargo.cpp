#include<iostream>
using namespace std;
int main()
{
    int n,m,p,x,y,a[7],b[7][7];
    cin>>n>>m>>p;
    for(int i=1;i<=7;i++) a[i]=0;
    for(int i=1;i<=m;i++)
    {
        cin>>x;
        cin>>y;
        b[x][y]=1;
    }
    for(int i=1;i<=7;i++)
    {
        for(int j=1;j<=7;j++)
        {
            if(b[i][j]==1) a[i]=1;
        }
    }
    if( a[7]!=1 && a[6]!=1 ) cout<<"OK";
    else if(( a[7]==1 || a[6]==1 )&&( a[1]==1 || a[2]==1 || a[3]==1 || a[4]==1 || a[5]==1 )) cout<<"MIXED";
        else cout<<"IMPOSSIBLE";
    return 0;
}
/*
100 3 2
4 5
5 6
5 7
*/
