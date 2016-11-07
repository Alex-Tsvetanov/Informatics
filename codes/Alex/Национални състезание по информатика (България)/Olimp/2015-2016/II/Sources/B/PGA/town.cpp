#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,a[20000][20000],s,f,b[20000];
void read()
{
    int i,j,x,y;
    cin>>n>>s>>f;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        a[i][j]=9999999;
    while(!cin.eof())
    {
        cin>>x>>y;
        a[x][y]=0;
        if(a[y][x]!=0) a[y][x]=1;
    }
    for(i=1;i<=n;i++)
        b[i]=a[s][i];
}
void alg()
{
    int k,i,j;
    for(k=1;k<=n-2;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            if(b[i]+a[i][j]<b[j]) b[j]=b[i]+a[i][j];
}
int main()
{
    read();
    alg();
    if(b[f]==9999999) cout<<"X"<<endl;
    else cout<<b[f]<<endl;
    return 0;
}
