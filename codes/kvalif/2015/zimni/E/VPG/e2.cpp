#include <iostream>
using namespace std;
int main ()
{
    long long a[21], n;
    cin >> a[0] >> a[1] >> a[2] >> n;
    for (int i=3;i<=n-1;i++) {a[i]=a[i-1]+a[i-2]+a[i-3];}
    cout << a[n-1] << endl;
    return 0;
}
