#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d,y,n;
    char YES,NO;
    cin>>a>>b>>c>>d;

    y=a*b*c*d;
    n=a+b+c+d;
    if (a != b != c != d)  cout<<"NO"<<endl;
    cout<<n<<endl;
    if (a = b = c = d)  cout<<"YES"<<endl;
    cout<<y<<endl;

    return 0;
}
