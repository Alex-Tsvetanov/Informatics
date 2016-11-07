#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int n, m, p, help1, help2, used [1000001], i, j;
pair <int, int> por [1000001];

int main () {
    cin >> n >> m >> p;
    p /= 2;
    for (int i = 0; i < m; i ++) {
        cin >> help1 >> help2;
        por [i].first = help1;
        por [i].second = help2;
    }
    sort (por, por + m);
    for (i = 0; i < m; i ++) {
        for (j = 0; j < por [i].second - por [i].first; j ++) {
            if (used [por [i].first + j] < p and (por [i].first + j) % 6 and (por [i].first + j) % 7) {
                used [por [i].first + j] ++;
                break;
            }
        }
        if (j == por [i].second - por [i].first) break;
    }
    if (i < m) {
        for (i = 0; i < n; i ++) {
            used [i] = 0;
        }
        for (i = 0; i < m; i ++) {
            for (j = 0; j < por [i].second - por [i].first; j ++) {
                if (used [por [i].first + j] < p) {
                    used [por [i].first + j] ++;
                    break;
                }
            }
            if (j == por [i].second - por [i].first) break;
        }
        if (i < m) cout << "IMPOSSIBLE\n";
        else cout << "MIXED\n";
    } else cout << "OK\n";
    return 0;
}
