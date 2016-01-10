#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b;
    cin >> a >> b;
    double s=0;
    if(a==b) {
        double d = sqrt(2) * a;
        double h = (d-a)/2;
        double as = a*(h/(d/2));
        s = a*a;
        s += 2*as*as;
    }
    cout << s << endl;
    return 0;
}

