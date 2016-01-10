#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d,h,p;
    cin>>a>>b>>c>>d;
    h=a*d;
    p=a+b+c+d;
    if(a == b && c == d)cout<<"YES"<<"\n"<<h;

    if(c != d  && a != d)cout<<"NO"<<"\n"<<p;









    return 0;
}
