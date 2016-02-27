#include <iostream>
using namespace std;
int main () {
long long x, y, d, P, a, b;
cin>>x>>y>>d;
P=x*100+y;
b=(P-d*2)/4;
a=b+d;
cout<<endl<<a/100<<" "<<a-(a/100*100)<<endl<<b/100<<" "<<b-(b/100*100);
return 0;}
