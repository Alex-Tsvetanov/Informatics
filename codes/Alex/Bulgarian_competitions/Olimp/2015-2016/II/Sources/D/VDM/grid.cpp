#include <bits/stdc++.h>
using namespace std;
int m, n;
int t;
bool g[202][202];
int gc[202][202];
int v = 1;
void virus(int x1, int y1,int v1)
{
    gc[y1][x1] == v1;
    if(gc[y1 + 1][x1] == 0 && g[y1 + 1][x1] == 0)
        virus(x1, y1 + 1, v1);
    if(gc[y1 - 1][x1] == 0 && g[y1 - 1][x1] == 0)
        virus(x1, y1 - 1, v1);
    if(gc[y1][x1 + 1] == 0 && g[y1][x1 + 1] == 0)
        virus(x1 + 1, y1, v1);
    if(gc[y1][x1 - 1] == 0 && g[y1][x1 - 1] == 0)
        virus(x1 - 1, y1, v1);
}
void read()
{
    cin >> m >> n;
    for(int i = 1;i <= m;i ++)
        for(int j = 1;j <= n;j ++)
            cin >> g[i][j];
}
void solve()
{
    for(int i = 0;i < n;i ++)
        g[0][i] = 1;
    for(int i = 0;i < n;i ++)
        g[m + 1][i] = 1;
    for(int i = 0;i < m;i ++)
        g[i][0] = 1;
    for(int i = 0;i < m;i ++)
        g[i][n + 1] = 1;
    for(int y = 1;y <= m;y ++)
        for(int x = 1;x <= n;x ++)
        {

            if(gc[y][x] == 0 && g[y][x] == 0)
            {
                virus(x, y, v);
                v ++;


            }
        }
    cout << v - 1 << endl;
}
int main()
{
    read();
    solve();
    return 0;
}
