#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Point
{
    int x;
    int y;
};
struct Circle
{
    int x;
    int y;
    int r;
};
Point p[16];
Circle c[10100];
int score[16][10100];
int n,m,q,ans,t,tans;
inline int reqrad(Point A,Circle K){return ceil(sqrt((A.x-K.x)*(A.x-K.x)+(A.y-K.y)*(A.y-K.y)))+K.r;}
int mult=1;
int main()
{
    int i,j;
    scanf("%d%d%d",&n,&m,&q);
    for(i=0;i<n;++i){scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].r);}
    for(i=0;i<m;++i)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
        for(j=0;j<n;++j){score[i][j]=reqrad(p[i],c[j]);}
        score[i][n]=20000;
        sort(score[i],score[i]+n+1);
    }
    for(i=0;i<q;++i)
    {
        tans=0;
        scanf("%d",&t);t*=mult;
        for(j=0;j<m;++j){tans+=upper_bound(score[0],score[0]+n+1,t)-score[0];}
        if(tans%2==0){mult=2;}else{mult=1;}
        ans+=tans;
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
