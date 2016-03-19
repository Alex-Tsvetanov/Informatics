# include <algorithm>
# include <cstdio>
# include <cmath>

using namespace std;

const int MAX_N = 1e4 + 10;
const int MAX_M = 11;
const int MAX_Q = 1e4 + 10;

struct circle
{
    int x, y;
    int r;

    bool contains (circle p)
    {
        double br = r, sr = p.r, dist = sqrt (double ((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y)));
        return (br - dist - sr >= 0);
    }
};

int n, m, q;
int s[MAX_Q];

circle a[MAX_N];
circle b[MAX_M];

int ans;

int rd[MAX_M][MAX_N];

int main ()
{
    int i, j, k, cr, last = 1, l, r, mid;
    scanf ("%d%d%d", &n, &m, &q);
    for (i = 1; i <= n; i ++)
        scanf ("%d%d%d", &a[i].x, &a[i].y, &a[i].r);

    for (i = 1; i <= m; i ++)
        scanf ("%d%d", &b[i].x, &b[i].y);

    for (i = 1; i <= m; i ++)
    {
        for (j = 1; j <= n; j ++)
            rd[i][j] = ceil (sqrt (double ((b[i].x - a[j].x) * (b[i].x - a[j].x) + (b[i].y - a[j].y) * (b[i].y - a[j].y)))) + a[j].r;
        sort (rd[i] + 1, rd[i] + n + 1);
    }

    for (i = 1; i <= q; i ++)
    {
        scanf ("%d", &s[i]);
        cr = s[i];
        if (!(last & 1))
            cr = s[i] * 2;
        ///printf ("%d\n", cr);
        last = 0;
        for (j = 1; j <= m; j ++)
        {
            l = 0;
            r = n + 1;
            while (r - l > 1)
            {
                mid = (l + r) >> 1;
                if (rd[j][mid] <= cr)
                    l = mid;
                else
                    r = mid;
            }
            last += l;
        }
        ///printf ("%d\n", last);

        ans += last;
    }
    printf ("%d\n", ans);
    return 0;
}
