#include <iostream>
using namespace std;
int main()
{
    long long a, cb=1, b, c, brb=0;
    bool ltr=true;
    cin >> a >> b >> c;
    while (1)
    {
        cout << a << ' ' << b << ' ' << c << endl;
        if (cb==1)
        {
            if (a>0)
            {
                a--;
                brb++;
                if (ltr==1) cb=2;
                else
                {
                    cb=2;
                    ltr=1;
                }
            }
            else
            {
                cout << brb << endl;
                return 0;
            }
        }
        else if (cb==2)
        {
            if (b>0)
            {
                b--;
                brb++;
                if (ltr==1) cb=3;
                else cb=1;
            }
            else
            {
                cout << brb << endl;
                return 0;
            }
        }
        else
        {
            if (c>0)
            {
                c--;
                brb++;
                if (ltr==1) {ltr=0; cb=2;}
                else cb=2;
            }
            else
            {
                cout << brb << endl;
                return 0;
            }
        }
    }
}
