#include <iostream>
#define endl '\n'
using namespace std;
int a[100][100] = {0};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int h, l, n, maxs, s;

    cin >> l >> h;

    cin >> n;

    for (int i = 1; i <= n; i ++)
    {
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        for (int j = x1; j < x2 + x1; j ++)
        {
            for (int z = y1; z < y2 + y1; z ++)
            {
                a[z][j] = -1;
            }
        }
    }


    for (int i = 0; i < h; i ++)
    {
        for (int j = 0, h = 1; j < l; j ++, h ++)
        {
            if (a[i][j] == -1)
            {
                h = 0;
            }
            else a[i][j] = h;
        }
    }

    maxs = 0;

    for (int i = 0; i < h; i ++)
    {
        for (int j = 0; j < l; j ++)
        {
            if (a[i][j] > 0)
            {
                int minpos = a[i][j], top;

                for (top = i; top >= 0; top --)
                {
                    if (a[top][j] == -1)
                        break;


                    if (minpos > a[top][j])
                    {
                        minpos = a[top][j];
                    }


                    s = (i - top + 1) * minpos;

                    if (s > maxs)
                        maxs = s;
                }
            }
        }
    }

    cout << maxs << endl;

    return 0;
}
