#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long p;
int a [2][10000], izh [10000], m, k, help1, help2, help;
bool dis, bool1, bool2;

int main () {
    for (int i = 0; i < 10000; i ++) {
        a [0][i] = 0;
        a [1][i] = 0;
    }
    cin >> p >> m;
    for (int i = 0; i < m; i ++) {
        cin >> help1 >> help2;
        bool1 = false;
        bool2 = false;
        for (int j = 0; j < 10000; j ++) {
            if (bool1 and bool2) break;
            if (a [0][j] == help1 and !bool1) {
                a [1][j] ++;
                bool1 = true;
            }
            if (a [0][j] == 0 and !bool1) {
                a [0][j] = help1;
                a [1][j] ++;
                bool1 = true;
            }
            if (a [0][j] == help2 and !bool2) {
                a [1][j] ++;
                bool2 = true;
            }
            if (a [0][j] == 0 and !bool2) {
                a [0][j] = help2;
                a [1][j] ++;
                bool2 = true;
            }
        }
    }
    cin >> k;
    for (int i = 0; i < 10000; i ++) {
        if (a [1][i] >= k) {
            izh[help] = a [0][i];
            help ++;
        }
    }
    sort (izh, izh + help);
    cout << help;
    for (int i = 0; i < help; i ++) {
        if (dis) cout << " ";
        else cout << endl;
        dis = true;
        cout << izh [i];
    }
    cout << endl;
    return 0;
}
