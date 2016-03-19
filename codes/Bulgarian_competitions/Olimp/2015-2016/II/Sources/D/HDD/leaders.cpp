#include <iostream>
#define endl '\n'
using namespace std;
int a[1000000] = {0}, b[1000000] = {0};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, maxi;

    cin >> n;

    for (int i = 0; i < n ; i ++)
        cin >> a[i];

    maxi = a[n-1];
    b[0] = a[n-1];

    int z = 1;

    for (int i = n - 2; i >= 0;i --)
    {
        if (maxi < a[i])
        {
            maxi = a[i];
            b[z] = a[i];
            z ++;
        }
    }

    for (int i = z - 1; i >= 0; i --)
    {
        if (i == 0)
            cout << b[0] << endl;
        else
            cout << b[i] << " ";
    }

    return 0;
}
