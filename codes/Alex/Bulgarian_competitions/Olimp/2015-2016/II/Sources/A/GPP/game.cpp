#include <iostream>
using namespace std;

struct Point
{
    int x,y;
};

struct Cir
{
    Point o;
    int r;
};

int n,m,q;

Cir a[10001];
Point b[16];
int c[10001];

int sign(int a)
{
    if (a>=0) return 1;
    return -1;
}

void inp()
{
    cin>>n>>m>>q;
    
    for (int i=0;i<n;i++) cin>>a[i].o.x>>a[i].o.y>>a[i].r;
    for (int i=0;i<m;i++) cin>>b[i].x>>b[i].y;
    for (int i=0;i<q;i++) cin>>c[i];
}

int sqDist(Point a, Point b)
{
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

/*a <- b*/
bool inRange(Cir a, Cir b)
{
    int sqT = sqDist(a.o, b.o);
    if (sqT > (a.r - b.r)*(a.r - b.r)*sign(a.r - b.r)) return false;
    return true;
}

int score(Cir s)
{
    int c=0;
    for (int i=0;i<n;i++) if (inRange(s, a[i])) c++;
    return c;
}

void sol()
{
    int cnt = 0;
    
    for (int i=0;i<q;i++) for (int j=0;j<m;j++) cnt+=score({b[j], i%2==1 ? c[i]*2 : c[i]});
    
    cout<<cnt<<endl;
}

int main()
{
    inp();
    //cout<<score({{4, 4}, 6})<<endl;
    sol();
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