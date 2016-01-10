#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // for squares
    double a;
    cin >> a;
    double b;
    cin >> b;

    double result;
    double min_area = a * b;
    if (a == b)
    {
        double tr_c = a / 3.0;
        double tr_area =4 * ( tr_c * tr_c * 1/ 2.0);
        result = min_area + tr_area;
    }
    else
    {
        double tr_c = a / 3.0;
        double tr_area =4 * ( tr_c * tr_c * 1/ 2.0);
        result = min_area + tr_area;
    }

    cout << result << endl;
}
