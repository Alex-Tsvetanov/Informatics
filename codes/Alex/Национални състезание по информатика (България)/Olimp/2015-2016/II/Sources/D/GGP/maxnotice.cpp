#include<iostream>
using namespace std;
int n, m;
bool is[128][128];
void read()
{
    int br;
    cin >> m >> n >> br;
    for (int temp = 0; temp < br; temp++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        for (int i = y; i < y+b; i++)
            for (int j = x; j < x+a; j++)
                is[i][j] = 1;
    }
}
void solve()
{
    int maxs = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (is[i][j] == 0)
            {
                int br = 0, tempbr, minbr = 128;
                for (int p = i; p < n; p++)
                {
                    if (is[p][j] == 1) break;
                    br++;
                    tempbr = 0;
                    for (int temp = j; temp < m; temp++)
                    {
                        if (is[p][temp] == 1) break;
                        tempbr++;
                    }
                    minbr = min(minbr, tempbr);
                    maxs = max(maxs, minbr * br);
                }
            }
        }
        cout << maxs << endl;
}
int main()
{
    read();
    solve();
}
