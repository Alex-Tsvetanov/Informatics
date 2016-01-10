#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>

using namespace std;

const float k = 0.96907438;

int main()
{
    float a, b;

    cin >> a >> b;

    if(a == b)
    {
        printf("%.3f\n", (a*b) + (2.0*((1.0/3.0*a)*(1.0/3.0*a))));
    }
    else {
        printf("%.3f\n", (a*b) * (max(a/b, b/a) * k));
    }

    return 0;
}
