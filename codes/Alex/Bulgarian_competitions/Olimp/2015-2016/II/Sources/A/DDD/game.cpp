#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct point
{
    int x,y;
};
struct circle
{
    point o;
    double r;
};
point p[16];
circle c[10010];
int s[10010];
int n,m,q,i,j,bp,ans;
double x,y;
double b[10010];
bool s1[10010];
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%lf",&c[i].o.x,&c[i].o.y,&c[i].r);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    s[0]=1;
    for(i=1;i<=q;i++)
    {
        scanf("%d",&s[i]);
        if(s[i-1]%2==0) s1[i]=1;
    }
    for(i=1;i<=q;i++)
    {
        s[i]+=s1[i]*s[i];
    }
    sort(s+1,s+q+1);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            x=p[i].x-c[j].o.x;
            y=p[i].y-c[j].o.y;
            b[j]=sqrt(x*x+y*y)+c[j].r;
        }
        sort(b+1,b+n+1);
        bp=1;
        for(j=1;j<=q;j++)
        {
            for(;bp<=n;bp++)
            {
                if(b[bp]>s[j]) break;
            }
            ans+=bp-1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
4 1 3
2 2 1
3 5 2
6 2 3
8 8 1
4 4
4 3 3
*/
//5
