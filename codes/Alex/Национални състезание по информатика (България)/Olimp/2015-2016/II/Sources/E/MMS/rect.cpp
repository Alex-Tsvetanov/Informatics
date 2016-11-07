#include <iostream>
using namespace std;
int main()
{
    long long n,spr=1,minskv,minpkv,spr2=1,p;
    cin>>n;
    spr2=n;
    spr=n;
    minskv=1;
    minpkv=4;
     p=spr/spr+spr2/spr2;
    if (n>minpkv && n>minskv && minpkv<spr && n-minpkv>n-spr && spr<10 ) cout<<0<<endl;
    else cout<<p<<endl;
    return 0;
}