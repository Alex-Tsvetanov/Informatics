#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    unsigned long long d1, d2, d3;
    int k = 0;
    cin >> n >> d1 >> d2 >> d3;
    bool b = true;
    for (unsigned long long i = pow(10,n - 1);i < pow(10,n);i ++)
    {
        b = true;
        int a = i;
        int d = a % 10;
        a /= 10;
        int c;
        for (int o = 1;a >= 1;o ++)
        {
            c = a % 10;
            if(c != 0)
            {
                int curr = c*10 + d;
                if(!(((curr % d1 == 0 && curr >= d1) || (curr % d2 == 0 && curr >= d2) || (curr % d3 == 0 && curr >= d3)) && b))
                {
                    b = false;
                }
            }
            else if(c == 0 && d == 0)
            {
                b = false;
            }
            d = c;
            a /= 10;
        }

        if (b)
        {
            k ++;
        }
    }
    cout << k << endl;
    return 0;
}
