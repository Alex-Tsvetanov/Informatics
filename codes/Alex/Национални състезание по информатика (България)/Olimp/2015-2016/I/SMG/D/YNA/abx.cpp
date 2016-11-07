#include <iostream>
using namespace std;
int main () {
    long long x2, a2, c;
    char pljus, ravno, x, a, b;
    cin >> a >> pljus >> x >> ravno >> b;
    if ('0' <= a % 10 and '9' >= a % 10) {
        x = b - a;
        x2 = x;
        cout << x2;

    }else {
        c = x;
        x = a;
        a = c;
        x = b - a;
        x2 = x;
        cout << x2;
    }
    cout << 'x';
return 0;
}
