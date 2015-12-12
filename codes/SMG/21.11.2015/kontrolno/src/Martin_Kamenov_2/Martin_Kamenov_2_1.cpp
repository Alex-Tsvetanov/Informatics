#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    char x, y;
    cin >> a;
    cin >> x;
    cin >> b;
    cin >> c;
    cin >> y;
    cin >> d;

    if (d >= b && c >= a)
    {
        cout << c - a << x << d - b;
    }
    else if (b > d && c == 0)
    {
        c = 24;
        if (c - a - 1 < 10)
        {
            cout << "0" << c - a - 1 << x << 60 - b + d;
        }
        else
        {
            cout << c - a - 1 << x << 60 - b + d;
        }
    }
    else if (c > a && b > d)
    {
        cout << c - a - 1 << x << 60 - b + d;
    }

    return 0;
}
