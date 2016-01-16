#include <iostream>
using namespace std;

int main () {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    if ((a==b) and (c==d)) {
        cout << "YES" << endl << a*c << endl;
        return 0;
    }
    if ((a==c) and (b==d)) {
        cout << "YES" << endl << a*b << endl;
        return 0;
    }
    if ((a==d) and (b==c)) {
        cout << "YES" << endl << a*b << endl;
        return 0;
    }

    cout << "NO" << endl << a+b+c+d << endl;
    return 0;
}
