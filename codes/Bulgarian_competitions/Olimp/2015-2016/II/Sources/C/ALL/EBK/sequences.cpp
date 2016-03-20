#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main () {

    ios_base::sync_with_stdio(false);

    int p, n, s;
    cin >> p >> n >> s;

    int sum = 0, current, a = 0, k, i = 1, b[n];
    bool noMore = true;

    do {
        current = 0;
        k = a;
        for (int i = 1; i <= n; i++) {
            b[n - i] = a % p;
            current += b[n - i];
            a = a / p;
        }

        if (a != 0) {
            break;
        }

        if (current < s) {
            sum++;
        }
        a = k;
        a++;
    } while(true);

    cout << sum << "\n";

    return 0;
}
