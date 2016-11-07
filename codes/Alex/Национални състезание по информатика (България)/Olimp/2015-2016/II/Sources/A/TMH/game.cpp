#include <stdio.h> ///Todor Milenov Hristov
#include <algorithm>
#include <math.h>

using namespace std;

struct Circle
{
    int x,y,r;
};

struct Point
{
    int x,y;
};

int N,M,Q;
int result;
Circle circles[10002];
Point points[10002];
int power;
int doubling;

int Dest(int &x1,int &y1,int &x2,int &y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void Check()
{
    int a,b;
    int include=0;

    if(doubling) power*=2;

    for(a=0;a<M;a++)
    {
        for(b=0;b<N;b++)
        {
            if(Dest(points[a].x, points[a].y, circles[b].x, circles[b].y)+circles[b].r<power) include++;
        }
    }
    result+=include;
    if(include%2) doubling=0;
    else doubling=1;
}

int main()
{
    int a;

    scanf("%d",&N);
    scanf("%d",&M);
    scanf("%d",&Q);

    for(a=0;a<N;a++)
    {
        scanf("%d", &circles[a].x);
        scanf("%d", &circles[a].y);
        scanf("%d", &circles[a].r);
    }

    for(a=0;a<M;a++)
    {
        scanf("%d", &points[a].x);
        scanf("%d", &points[a].y);
    }

    for(a=0;a<Q;a++)
    {
        scanf("%d", &power);
        Check();
    }

    printf("%d\n",result);

    return 0;
}
