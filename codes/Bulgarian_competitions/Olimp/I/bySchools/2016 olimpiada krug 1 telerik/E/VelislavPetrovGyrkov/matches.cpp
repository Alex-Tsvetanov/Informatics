#include <iostream>
using namespace std;
int main ()
{
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((a==c) && (b==d)) {
        cout << "YES" << endl;
        cout << a*b << endl;
    } else {
        cout << "NO" << endl;
        cout << a+b+c+d << endl;
    }
    return 0;
}
