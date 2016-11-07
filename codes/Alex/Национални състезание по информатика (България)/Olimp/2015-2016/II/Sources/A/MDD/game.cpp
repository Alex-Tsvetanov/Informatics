#include <iostream>
#include <math.h>

using namespace std;

struct circle
{
    double x;
    double y;
    double r;
}c[10000];

struct point
{
    double x;
    double y;
}p[10];

    double hits[10000];

bool contains(int indexP, int indexH, int indexC, double mult)
{
    if(sqrt(pow(max(p[indexP].x, c[indexC].x) - min(p[indexP].x, c[indexC].x), 2) + pow(max(p[indexP].y, c[indexC].y) - min(p[indexP].y, c[indexC].y), 2)) + c[indexC].r < hits[indexH]*mult) return true;
    else return false;
}

int main()
{
    int n, m, q, i, score = 0, temp;
    double multiply = 1;
    cin >> n >> m >> q;
    for(i = 0; i < n; i++)
        cin >> c[i].x >> c[i].y >> c[i].r;
    for(i = 0; i < m; i++)
        cin >> p[i].x >> p[i].y;
    for(i = 0; i < q; i++)
        cin >> hits[i];
    for(int k = 0; k < m; k++)
    {
        for(int j = 0; j < q; j++)
        {
            temp = 0;
            for(int e = 0; e < n; e++)
            {
                if(contains(k, j, e, multiply))
                {
                    score++;
                    temp++;
                }
            }
            if(temp%2 == 0) multiply = 2;
            else multiply = 1;
        }
    }
    cout << score << endl;
    return 0;
}
