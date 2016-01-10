#include <iostream>
using namespace std;
int main()
{
long long a,b,c,d;
cin>>a>>b>>c>>d;
if(a>b&&a>c&&a>d&&b>c&&b>d&&c>d)
{
    cout<<"NO"<<endl<<a+b+c+d;
    return 0;
}
if(a<b&&a<c&&a<d&&b<c&&b<d&&c<d)
{
    cout<<"NO"<<endl<<a+b+c+d;
    return 0;
}
if(a==b&&a==c&&a==d&&b==c&&b==d&&c==d)
{
    cout<<"YES"<<endl<<a*a;
}
if(a==b&&a>c&&a>d&&b>c&&b>d&&c==d)
{
    cout<<"YES"<<endl<<a*c;
}
if(a==b&&a<c&&a<d&&b<c&&b<d&&c==d)
{
    cout<<"YES"<<endl<<a*c;
}
if(a==c&&a>b&&a>d&&c>b&&c>d&&b==d)
{
    cout<<"YES"<<endl<<a*b;
}
if(a==c&&a<b&&a<d&&c<b&&c<d&&b==d)
{
    cout<<"YES"<<endl<<a*b;
}
if(a==d&&a>b&&a>c&&d>b&&d>c&&b==c)
{
    cout<<"YES"<<endl<<a*b;
}
if(a==d&&a<b&&a<c&&d<b&&d<c&&b==c)
{
    cout<<"YES"<<endl<<a*b;
}
    cout<<endl;
    return 0;
}
