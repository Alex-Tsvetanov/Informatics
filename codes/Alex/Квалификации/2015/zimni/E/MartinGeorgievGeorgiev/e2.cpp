#include <iostream>
using namespace std;
int main () {
    long long t1, t2, t3, n, steseizpylnqwa, tx[20], x, y, z, a;
    cin >> t1;
    cin >> t2;
    cin >> t3;
    cin >> n;
    tx[1] = t1;
    tx[2] = t2;
    tx[3] = t3;
    if (n > 3) {
        x = 4;
        y = t1;
        z = t2;
        a = t3;
        for (long long steseizpylnqwa = n - 3; steseizpylnqwa > 0; steseizpylnqwa = steseizpylnqwa - 1) {
            tx[x] = y + z + a;
            if (y > z) {
                swap(y, z);
            }
            if (y > a) {
                swap(y, a);
            }
            y = tx[x];
            ++x;
        }
        cout << tx[x - 1];
    }
    else {
        cout << tx[n];
    }

    return 0;
}
