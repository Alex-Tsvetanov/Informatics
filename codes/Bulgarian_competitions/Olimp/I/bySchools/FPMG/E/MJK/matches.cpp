#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d;

    cin>>a>>b>>c>>d;

    if (a==b&&c==d||a==c&&b==d) cout<<"YES"<<endl<<a*d<<endl;
    else cout<<"NO"<<endl<<a+b+c+d<<endl;

    if (a==d&&c==b) cout<<"YES"<<endl<<a*b<<endl;

    return 0;
}
