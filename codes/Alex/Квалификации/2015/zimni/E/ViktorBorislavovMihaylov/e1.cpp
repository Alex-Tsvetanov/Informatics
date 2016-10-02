#include <iostream>

using namespace std;

int main()
{
    long long x, y, d, a, b, P;

// a > b
    x = -1;
    y = -1;
    d = -1;
    while ((x < 0) || (x > 999999999) || (y < 0) || (y > 999999999)) {
        cin >> x;
        cin >> y;
    }
    while ((d < 0) || (d > 999999999)) {
        cin >> d;
    }
    P = 100 * x + y;
    for (a = 1; a < P; a++) {
        for (b = 1; b < P; b++) {
            if ((a == b + d) && (P == 2 * (a + b))) {
                cout << a / 100 << " " << a - (a / 100) * 100 << endl;
                cout << b / 100 << " " << b - (b / 100) * 100;
            }
        }
    }
    return 0;
}
