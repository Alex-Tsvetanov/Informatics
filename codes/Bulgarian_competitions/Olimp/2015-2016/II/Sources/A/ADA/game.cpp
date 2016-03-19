#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#define MAXN 100001
#define MAXM 16
using namespace std;
struct Circle
{
    double x, y, r;
    void set(double _x, double _y, double _r)
    {
        x = _x; y = _y; r = _r;
    }
    void set(double _r)
    {
        r = _r;
    }
    bool covers(Circle b)
    {
        if (r < b.r)
            return false;
        double dist = (b.x - x) * (b.x - x) + (b.y - y) * (b.y - y);
        double r1 = (r - b.r) * (r - b.r);
        return r1 >= dist;
    }
};
int n, m, q;
Circle aims[MAXN], punches[MAXM];
vector<double> sorted[MAXM];
double dist (double x, double y, int f)
{
    double dist;
    dist = (x - aims[f].x) * (x - aims[f].x);
    dist += (y - aims[f].y) * (y - aims[f].y);
    dist = sqrt(dist);
    dist += aims[f].r;
    return dist;
}
int findCount (int f, double power)
{
    int pos = upper_bound(sorted[f].begin(), sorted[f].end(), power) - sorted[f].begin();
    return pos;
}
int main ()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; i++)
    {
        double x, y, r;
        scanf("%lf%lf%lf", &x, &y, &r);
        aims[i].set(x, y, r);
    }
    for (int i = 0; i < m; i++)
    {
        double x, y;
        scanf("%lf%lf", &x, &y);
        punches[i].set(x, y, 0);
        for (int j = 0; j < n; j++)
            sorted[i].push_back(dist(x, y, j));
        sort(sorted[i].begin(), sorted[i].end());
    }
    bool OP = false;
    int ans = 0;
    for (int i = 0; i < q; i++)
    {
        double power;
        int cnt = 0;
        scanf("%lf", &power);
        if (OP)
            power = 2 * power;
        for (int j = 0; j < m; j++)
            cnt += findCount(j, power);
        ans += cnt;
        OP = !(cnt % 2);
    }
    printf("%d\n", ans);
    return 0;
}
/*
4 1 3
2 2 1
3 5 2
6 2 3
8 8 1
4 4
4 2 2
*/
