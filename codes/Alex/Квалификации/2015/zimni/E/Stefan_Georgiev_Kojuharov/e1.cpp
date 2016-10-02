#include <iostream>
using namespace std;
int main()
{
long long x,y,d,a,IIb,obikolkavcm,obikolka,am,bm,acm,bcm,b;
cin>>x>>y>>d;
obikolkavcm=(x*100)+y;
obikolka=obikolkavcm-d*2;
IIb=obikolka/2;
a=(IIb+d*2)/2;
b=IIb/2;
am=a/100;
bm=b/100;
acm=a%100;
bcm=b%100;
cout<<am<<" "<<acm<<endl;
cout<<bm<<" "<<bcm<<endl;
cout<<endl;
return 0;
}
