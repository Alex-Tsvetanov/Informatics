#include <iostream>
#define endl '\n'
using namespace std;
int a[200][200] = {0};
int m, n, p;
void izch(int i, int j, int p)
{
    if (i < 0 || i == m || j < 0 || j == n || a[i][j] != 0)return;
    a[i][j] = p;
    izch(i+1,j, p);
    izch(i-1,j, p);
    izch(i,j+1, p);
    izch(i,j-1, p);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;

    for (int i = 0; i < m; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
                a[i][j] = -1;
        }
    }

    a[0][0] = 1;

    for (int i = 0; i < m; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            if (a[i][j] == -1)
            {
                if (i + 1 < m && a[i+1][j] != -1)
                    a[i+1][j] = 1;
                if (i - 1 >= 0 && a[i-1][j] != -1)
                    a[i-1][j] = 1;
                if (j - 1 >= 0 && a[i][j-1] != -1)
                    a[i][j-1] = 1;
                if (j + 1 < n && a[i][j+1] != -1)
                    a[i][j+1] = 1;
            }
        }
    }

    bool ok = true;
    p = 2;

    while (ok)
    {
        ok = false;

        bool fl = false;

        for (int i = 0; i < m; i ++)
        {
            for (int j = 0; j < n; j ++)
            {
                if (a[i][j] == 0 && ok == false)
                {
                    ok = true;
                    izch(i, j, p);
                }
            }
        }
        p ++;
    }

    cout << p - 2 << endl;

    return 0;
}
