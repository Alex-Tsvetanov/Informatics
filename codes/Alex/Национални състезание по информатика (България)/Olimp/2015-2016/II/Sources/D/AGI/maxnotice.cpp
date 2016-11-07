#include<iostream>
using namespace std;
int main ()
{
    int l, h, n, i, x1, x2, x3, x4, k;
    cin>>l>>h;
    k=l*h;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>x1>>x2>>x3>>x4;
        k-=(x3*x4);
    }
    cout<<k<<endl;
return 0;
}
