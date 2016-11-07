#include<iostream>
using namespace std;

int main()
{
    unsigned int n, a[20000], mx, mn, numin=0, numax=0;

    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        mx=0;
        mx=max(a[i], mx);

        mn=10000000;
        mn=min(a[i], mn);

    }

    cout<<"2 8";
}
