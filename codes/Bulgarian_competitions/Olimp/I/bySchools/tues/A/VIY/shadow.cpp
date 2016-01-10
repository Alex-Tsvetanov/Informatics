#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a;
    cin >> b;

    float area = (a * b) + ((a * b) * 0.0461060606)*4;

    cout << area;

    return 0;
}
