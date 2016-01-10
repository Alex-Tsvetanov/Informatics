#include <iostream>
using namespace std;
int main()
{
int a,b,a1,a2,a3,b1,b2,b3,c;
char plas;
cin>>a>>plas>>b;
a1=a/100;
a2=(a%100)/10;
a3=(a%100)%10;
b1=b/100;
b2=(b%100)/10;
b3=(b%100)%10;
c=a+b;
if(a1+b1<10&&a2+b2<10&&a3+b3>10)
{
    cout<<c-10<<endl;
    cout<<c<<endl;
}
if(a1+b1<10&&a2+b2>10&&a3+b3<10)
{
    cout<<c-100<<endl;
    cout<<c;
}
    cout<<endl;
    return 0;
}
