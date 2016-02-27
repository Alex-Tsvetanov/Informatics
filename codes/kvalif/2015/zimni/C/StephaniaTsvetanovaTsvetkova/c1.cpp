#include <iostream>

using namespace std;

int main ()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int br = 0; br < n; ++br)
    {
        int a;
        cin >> a;

        int res = 0;
        if (a == 0)
        {
            res = 1;
        }
        for (int i = 1; i * i <= a; ++i)
        {
            if (a % i == 0)
            {
                //cout << i << ' ';
                ++res;
                if (a / i != i)
                {
                    ++res;
                    //cout << a / i;
                }
                //cout << endl;
            }
        }
        cout << res;
        if (br != n - 1)
        {
             cout << ' ';
        }
    }

    cout << '\n';
    return 0;
}
