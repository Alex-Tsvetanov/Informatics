#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

struct Circle
{
    int x, y, r;
}arr[10010], A[11];

int n, m ,q, current[10010], ans, R;

double dist(int p1, int q1, int p2, int q2)
{
    return sqrt((p1 - p2)*(p1 - p2) + (q1 - q2)*(q1 - q2));
}

int main()
{
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &arr[i].x, &arr[i].y, &arr[i].r);
    for (int i = 0; i < m; i++)
        scanf("%d %d", &A[i].x, &A[i].y);

    for (int i = 0; i < q; i++)
    {
        scanf("%d", &R);
        if (i > 0 and current[i - 1] % 2 == 0) R *= 2;
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                double d = dist(arr[k].x, arr[k].y, A[j].x, A[j].y);
                double R1 = R;
                double r1 = arr[k].r;
                if (R1 - d - r1 > 0.01) current[i]++;
            }
        }
    }
    for (int i = 0; i < q; i++) ans += current[i];
    printf("%d\n", ans);
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
