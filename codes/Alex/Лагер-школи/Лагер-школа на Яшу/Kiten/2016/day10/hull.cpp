#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

#define x second
#define y first

using namespace std;

int64_t orientationFace (int64_t dX0, int64_t dY0, int64_t dX1, int64_t dY1, int64_t dX2, int64_t dY2)
{
    int64_t dorientationFace = (dX0 + dX1) * (dY0 - dY1) + (dX1 + dX2) * (dY1 - dY2) + (dX0 + dX2) * (dY2 - dY0);
    return dorientationFace;
}

vector < pair <int64_t, int64_t> > v;
set <int64_t> hull;

int main ()
{
    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    int64_t n;
    cin >> n;
    for (int64_t i = 0 ; i < n ; i ++)
    {
        int64_t a, b;
        cin >> a >> b;
        v.push_back ({b, a});
    }

    sort (v.begin (), v.end ());

    int64_t cur = 0;
    int64_t cur_cand = 1;

    hull.insert (cur);
    cout << v [0].x << " " << v [0].y << "\n";

    while (true)
    {
        for (int64_t i = 0 ; i < n ; i ++)
            if (orientationFace (v [i].x, v [i].y, v [cur].x, v [cur].y, v [cur_cand].x, v [cur_cand].y) > 0)
                cur_cand = i;
        if (hull.insert (cur_cand).second == true and cur_cand < n)
        {
            cout << v [cur_cand].x << " " << v [cur_cand].y << '\n';
            cur = cur_cand;
            cur_cand ++;
        }
        else
            break;
    }
    return 0;
}
