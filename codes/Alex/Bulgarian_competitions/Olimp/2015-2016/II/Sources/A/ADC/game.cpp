#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=10100,MAXM=11;
const double EPS=0.0000001;
struct point
{
    double x,y;
    point(){}
    point(double _x,double _y)
    {
        x=_x;
        y=_y;
    }
};
struct circle
{
    point center;
    double R;
    circle() {}
    circle(point _center,double _R)
    {
        center=_center;
        R=_R;
    }
};
inline double Distance(point A,point B)
{
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
int n,m,q;
circle d[MAXN];
point a[MAXM];
double dists[MAXM][MAXN];
void read()
{
    int i;
    double x,y,z;
    scanf("%d%d%d",&n,&m,&q);
    for(i=1;i<=n;i++)
    {
        scanf("%lf%lf%lf",&x,&y,&z);
        d[i]=circle(point(x,y),z);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%lf%lf",&x,&y);
        a[i]=point(x,y);
    }
}
bool cmp(double el1,double el2)
{
    if(el1+EPS<el2)return 1;
    return 0;
}
void init()
{
    int i,j;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
            dists[i][j]=Distance(a[i],d[j].center)+d[j].R;
        sort(dists[i]+1,dists[i]+n+1,cmp);
    }
}
int findCircles(int x,double str)
{
    int l,r,mid;
    int answer=0;
    l=1;
    r=n;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(dists[x][mid]+EPS<=str)
        {
            answer=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return answer;
}
void solve()
{
    int i,j;
    int current,answer=0;
    double str;
    bool even=false;
    for(i=1;i<=q;i++)
    {
        scanf("%lf",&str);
        if(even)str*=2.;
        current=0;
        for(j=1;j<=m;j++)
            current+=findCircles(j,str);
        if(current%2==0)even=true;
        else even=false;
        answer+=current;
    }
    printf("%d\n",answer);
}
int main()
{
    read();
    init();
    solve();
}
/*
4 1 3
2 2 1
3 5 2
6 2 3
8 8 1
4 4
4 3 3

3 3 3
1 1 3
1 100 3
1 200 3
0 0
0 100
0 200
3 3 5
*/
