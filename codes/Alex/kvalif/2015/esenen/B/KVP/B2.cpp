#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int m, n, help, x [200], cur, sb, ban;
vector <int> y;
pair <int, int> res;
bool used [200];

void dodo (int a) {
    ban = 0;
    for (int i = 0; i < m; i ++) {
        if (!used [i] and min (n, sb) + 1 - a > x [i] and x [i] != ban) {
            used [i] = true;
            cur += y [a + x [i]];
            dodo (a + x [i]);
            cur -= y [a + x [i]];
            used [i] = false;
            ban = x [i];
        }
    }
    if (cur > res.first) {
        res.first = cur;
        res.second = a;
    }
    if (cur == res.first and a < res.second) res.second = a;
}

int main () {
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        cin >> help;
        x [i] = help;
        sb += help;
    }
    for (int i = 0; i < n + 1; i ++) {
        cin >> help;
        y.push_back (help);
    }
    sort (x, x + m);
    cur = y [0];
    dodo (0);
    cout << res.first << " " << res.second << endl;
    return 0;
}
