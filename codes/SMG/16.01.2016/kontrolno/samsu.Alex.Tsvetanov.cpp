#include <iostream>

using namespace std;

int a [3][3] =
{
    {3, 2, 6},
    {9, 4, 1},
    {7, 5, 8}
};
int minCnt = 22;

void input ()
{
    for (int r = 0; r < 3; r ++)
        for (int c = 0; c < 3; c ++)
            cin >> a [r][c];
}

bool check ()
{
    int r, c, s;
    for (r = 0; r < 2; r ++)
    {
        s=0;
        for (c = 0; c < 3; c ++) s += a [r][c];
        if (s%3 != 0)
        	return false;
    }
    for (c = 0; c < 2; c ++)
    {
        s = 0;
        for (r = 0; r < 3; r ++)
        	s += a [r][c];
        if (s % 3 != 0)
        	return false;
    }
    return true;
}
void go (int cnt, int prow, int pcol)
{
    if (cnt >= minCnt)
    	return;
    if (check ())
    {
        minCnt = cnt;
        return;
    }
    for (int r = 0; r < 3; r ++)
        for (int c = 0; c < 2; c ++)
        	if ((r != prow or c != pcol) and (a [r][c] - a [r][c + 1]) % 3 != 0)
            {
                swap (a [r][c], a [r][c + 1]);
                go (cnt + 1, r, c);
                swap (a [r][c], a [r][c + 1]);
            }
    for (int c = 0; c < 3; c ++)
        for (int r = 0; r < 2; r ++)
        	if ((r != prow or c != pcol) and (a [r][c] - a [r + 1][c]) % 3 != 0)
            {
                swap (a [r][c], a [r+1][c]);
                go (cnt+1,r,c);
                swap (a [r][c], a [r+1][c]);
            }
}
//int main ()
{
    inp ();
    go (0, -1, -1);
    cout << minCnt << endl;
}
