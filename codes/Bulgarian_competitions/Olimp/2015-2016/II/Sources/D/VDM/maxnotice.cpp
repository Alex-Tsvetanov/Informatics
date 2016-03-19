#include <bits/stdc++.h>
using namespace std;
int h, l;
int n;
int x1, y11, a1, b1;
bool g[102][102];
int ms, ts, ax, ay, ad, dx, dy;
bool f(int ad1, int ay1, int i1, int j1)
{
    for(int ii = i1;ii < ad;ii ++)
        if(g[ii][j1] == 1)
            return 0;
    return 1;
}
void read()
{
    cin >> l >> h;
    for(int i = 0;i <= l + 1;i++)
        g[i][0] = 1;
    for(int i = 0;i <= l + 1;i++)
        g[i][h + 1] = 1;
    for(int i = 0;i <= h + 1;i++)
        g[0][i] = 1;
    for(int i = 0;i <= l + 1;i++)
        g[l + 1][i] = 1;
    cin >> n;
    for(int i = 0;i < n;i ++)
    {
        cin >> x1 >> y11 >> a1 >> b1;
        for(int j = 1;j < a1;j ++)
            for(int k = 0;k < b1;k ++)
                g[x1 + j][y11+ k] = 1;
    }
    for(int i = 0;i < l;i ++)
        for(int j = 0;j < h;j ++)
        {
            if(g[i][j] == 1)
                j++;
            ad  = 0;
            while(g[i + ad][j] != 1)
                ad ++;
            while(f(ad, ay, i, j) == 1)
                ay ++;
            ts = (ad - 1) * (ay - 1);
            if(ts > ms)
                ms = ts;
        }
        cout << ms << endl;
}
int main()
{
    read();
    //solve();
    return 0;
}
