#include <cstdio>
#include <math.h>
#include <iostream>
using namespace std;

#define MAX_M 10
#define MAX_Q 10000
#define MAX_N 10000

int s[MAX_Q];
int xp[MAX_M],yp[MAX_M];
int x[MAX_N],y[MAX_N],r[MAX_N];

double distance(double x1,double y1,double x2,double y2)
{
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

int main()
{
    int n,m,q,i,j,k,br=0;
    long long score=0;
    scanf("%d %d %d", &n, &m, &q);
    for(i=0;i<n;i++)scanf("%d %d %d", &x[i], &y[i], &r[i]);
    for(i=0;i<m;i++)scanf("%d %d", &xp[i], &yp[i]);
    for(i=0;i<q;i++)
    {
        scanf("%d", &s[i]);
        if(i>0&&br%2==0)s[i]*=2;
        br=0;
        for(j=0;j<m;j++)
        {
            for(k=0;k<n;k++)
            {
                if((distance(x[k]+r[k],y[k],xp[j],yp[j])<double(s[i]))&&(distance(x[k]-r[k],y[k],xp[j],yp[j])<double(s[i]))&&(distance(x[k],y[k]+r[k],xp[j],yp[j])<double(s[i]))&&(distance(x[k],y[k]-r[k],xp[j],yp[j])<double(s[i])))br++;
            }
        }
        score+=br;
    }
    printf("%I64d\n", score);
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
