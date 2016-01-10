#include <iostream>
using namespace std;
int main () {

    long long a,b,c,d;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;

    if ((0 >= a) || (0 >= b) || (0 >= c) || (0 >= d) || (a > 1000000000) || (b > 1000000000) || (c > 1000000000) || (d > 1000000000)) {
        return 0;
    }

    if ((a == b && c == d) || (a == c && b == d) || (a == d && b == c) || (b == c && a == d) || (b == d && a == c)) {
        cout << "YES" << endl;
        if (a == b) {
            cout << a * d;
        }
        else if (a == c) {
            cout << a * b;
        }
        else if (a == d) {
            cout << a * b;
        }
    }
    else {
        cout << "NO" << endl << a + b + c + d;
    }

    return 0;
}
#include <iostream>
using namespace std;
int main () {

    long long a,b,c,d;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;

    if ((0 >= a) || (0 >= b) || (0 >= c) || (0 >= d) || (a > 1000000000) || (b > 1000000000) || (c > 1000000000) || (d > 1000000000)) {
        return 0;
    }

    if ((a == b && c == d) || (a == c && b == d) || (a == d && b == c) || (b == c && a == d) || (b == d && a == c)) {
        cout << "YES" << endl;
        if (a == b) {
            cout << a * d;
        }
        else if (a == c) {
            cout << a * b;
        }
        else if (a == d) {
            cout << a * b;
        }
    }
    else {
        cout << "NO" << endl << a + b + c + d;
    }

    return 0;
}
