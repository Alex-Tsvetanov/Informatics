#include <iostream>
using namespace std;
int main () {
    long long n, m, a, broj;
    cin >> m >> n;
    for (broj = 1; m != n; n = n + 1) {
        if (n > m) {
            a = n;
            n = m;
            m = a;
        }
        m = m - n;
        broj = broj + 1;
    }
    cout << broj;
}
