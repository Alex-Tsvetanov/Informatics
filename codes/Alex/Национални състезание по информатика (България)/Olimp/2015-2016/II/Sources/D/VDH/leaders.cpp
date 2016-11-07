#include <iostream>
using namespace std;
long long a[1000002], b[1000002], c[1000002];
int main()
{
    long long n, j=0;
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    b[n]=-1000000002;
    b[n-1]=a[n-1];
    for (int i=n-2; i>=0; i--)
    {
        if (a[i]>b[i+1]) b[i]=a[i];
        else b[i]=b[i+1];
    }
    for (int i=0; i<n; i++)
    {
        if (a[i]>=b[i+1]) {c[j]=a[i]; j++;}
    }
    for (int i=0; i<j-1; i++) cout<<c[i]<<" ";
    cout<<c[j-1]<<endl;
    return 0;
}
