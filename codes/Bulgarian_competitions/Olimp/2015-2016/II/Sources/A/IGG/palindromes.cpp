# include <cstdio>
# include <cstring>

using namespace std;

const int MAX_N = 1e4 + 10;

int n;
int ans[MAX_N];
bool dp[MAX_N][MAX_N];
char c[MAX_N];

int main ()
{
    int i, j, k;
    ///scanf ("%d", &n);
    scanf ("%s", c);
    n = strlen (c);

    for (i = 0; i < n; i ++)
        dp[i][0] = 1;
    for (i = 0; i < n - 1; i ++)
        dp[i][1] = (c[i] == c[i + 1]);
    for (i = 2; i < n; i ++)
        for (j = 0; j + i < n; j ++)
        {
            if (c[j] == c[j + i] && dp[j + 1][i - 2])
                dp[j][i] = 1;
        }

    /**
    for (i = 0; i < n; i ++)
        for (j = 0; j + i < n; j ++)
            if (dp[j][i])
                printf ("%d %d\n", j + 1, j + i + 1);
    **/

    ans[0] = 0;

    for (i = 1; i <= n; i ++)
    {
        ans[i] = 1e9;
        for (j = 1; j <= i; j ++)
        {
            if (dp[(j - 1)][((i - 1) - (j - 1))] && ans[j - 1] + 1 < ans[i])
                ans[i] = ans[j - 1] + 1;
        }
    }

    printf ("%d\n", ans[n] - 1);

    return 0;
}
