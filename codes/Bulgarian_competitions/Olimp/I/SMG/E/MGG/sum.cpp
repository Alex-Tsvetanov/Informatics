#include <iostream>
using namespace std;
int main () {

    char p;
    long long a, b, c, d;
    long long x, y, z, w, n, m;
    cin >> a;
    cin >> p;
    cin >> b;
    c = a;
    d = b;

    if ((a < 100) || (b < 100) || (a > 999) || (b > 999)) {
        return 0;
    }
    x = a % 10;
    a = a / 10;
    y = a % 10;
    a = a / 10;
    z = a % 10;

    w = b % 10;
    b = b / 10;
    n = b % 10;
    b = b / 10;
    m = b % 10;

    if (z + m > 10) {
        cout << z + m - 10;
    }
    else {
        cout << z + m;
    }
    if (y + n > 10) {
        cout << y + n - 10;
    }
    else {
        cout << y + n;
    }
    if (x + w > 10) {
        cout << x + w - 10;
    }
    else {
        cout << x + w;
    }
    cout << endl << c + d;

    return 0;
}

