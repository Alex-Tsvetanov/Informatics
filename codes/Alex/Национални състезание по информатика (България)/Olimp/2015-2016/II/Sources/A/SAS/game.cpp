#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <math.h>
using namespace std;
typedef long long lld;

struct Point
{
    int x, y;
};
struct Circle
{
    Point org;
    int x, y, r;
};
Point GetPoint(int x, int y)
{
    Point ret;
    ret.x = x; ret.y = y;
    return ret;
}
Circle GetCircle(int x, int y, int r)
{
    Circle ret;
    ret.org = GetPoint(x, y); ret.x = x; ret.y = y; ret.r = r;
    return ret;
}

int N, M, Q;
Circle circ[10002];

Point option[12];
int tohit[12][20002];
int query[10002];

void Input()
{
    scanf("%d %d %d", &N, &M, &Q);
    for (int i=1; i<=N; i++)
    {
        int x, y, r;
        scanf("%d %d %d", &x, &y, &r);
        circ[i] = GetCircle(x, y, r);
    }
    for (int i=1; i<=M; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        option[i] = GetPoint(x, y);
    }
    for (int i=1; i<=Q; i++)
    {
        scanf("%d", &query[i]);
    }
}

double Distance(Point a, Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
double GetMaxDistance(Circle a, Point b)
{
    return Distance(a.org, b) + (double)a.r;
}

Point baseP;
bool SH(Circle a, Circle b)
{
    return (GetMaxDistance(a, baseP) < GetMaxDistance(b, baseP));
}

int main ()
{
    //freopen("input.txt", "r", stdin);

    Input();

    for (int i=1; i<=M; i++)
    {
        baseP = option[i];
        sort(circ+1, circ+N+1, SH);
        tohit[i][0] = 0;

        int tobein = 1;
        for (int j=1; j<=20000; j++)
        {
            tohit[i][j] = tohit[i][j-1];
            while (tobein <= N && GetMaxDistance(circ[tobein], baseP) < j)
            {
                tobein++;
                tohit[i][j]++;
            }
        }
    }

    lld ans = 0;
    bool todouble = false;

    for (int i=1; i<=Q; i++)
    {
        lld cur = 0;
        for (int j=1; j<=M; j++)
        {
            cur += (lld)tohit[j][query[i] + query[i]*(todouble)];
        }

        ans += cur;
        todouble = (cur%2 == 0);
    }

    printf("%lld\n", ans);
}
