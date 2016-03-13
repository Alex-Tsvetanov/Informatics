#include <iostream>
using namespace std;
int main ()
{
int b,c,x,y,d,bm,bcm,cm,ccm;
cin>>x >>y;
cin>>d;

c=((x*100+y)-2*d)/4;
b>c;
b=c+d;

bm=b/100;
bcm=b%100;

cm=c/100;
ccm=c%100;

cout<<bm<<" "<<bcm<<endl;
cout<<cm<<" "<<ccm<<endl;
}
