#include<iostream>
#include<stdio.h>
using namespace std;
int n,maxx=0,a[10000][10000],v[10000];
void rek(int r,int br)
{
    for(int i=1;i<n;i++)
    {
        if(i==n-1 and a[r][i]>maxx)
        {
            if(a[r][i]<br)maxx=a[r][i];
            else maxx=br;
        }
        else if(a[r][i]>maxx and v[i]!=1)
        {
            v[r]=1;
            if(a[r][i]<br)rek(i,a[r][i]);
            else rek(i,br);
        }

    }
    for(int j=0;j<n;j++)v[j]=0;
}
int main()
{
    int m,x,y,w;
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&x);
        scanf("%d",&y);
        scanf("%d",&w);
        a[x-1][y-1]=w;
        a[y-1][x-1]=a[x-1][y-1];
    }
    rek(0,65000);
    printf("%d\n",maxx);
    return 0;
}
