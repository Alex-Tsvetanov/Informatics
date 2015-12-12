/*0<b<10^50, a - min b, c - max b, a + c = ?*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main ()
{
    char b_c[55];
    cin >> b_c;
    int a[55], c[55], b[55], n;
    n = strlen(b_c);
    for(int i = 0; i < n; ++i)
        b[i] = b_c[i] - '0';
    sort(b + 0, b + n);
    for(int i = 0; i < n; ++i)
    {
        if(i == 0 && b[i] == 0)
        {
            int k = 1;
            while(b[k] == 0)
                ++k;
            a[i] = b[k];
            ++i;
            for(int j = 1; j <= k; ++j)
                a[j] = 0;
        } else
            a[i] = b[i];
    }
    for(int i = n - 1, j = 0; i >= 0; --i, ++j)
        c[j] = b[i];
    int prenos = 0;
    for(int i = 0, j = n - 1; i < n; ++i, --j)
    {
        b[i] = a[j] + c[j] + prenos;
        prenos = 0;
        if(b[i] >= 10)
        {
            b[i] -= 10;
            prenos = 1;
        }
    }
    if(prenos == 1)
    {
        b[n] = 1;
        ++n;
    }
    for(int i = n - 1; i >= 0; --i)
        cout << b[i];
    cout << endl;
    return 0;
}
