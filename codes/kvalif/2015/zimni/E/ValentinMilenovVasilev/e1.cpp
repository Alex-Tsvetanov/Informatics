#include<iostream>
using namespace std;
int main () {
long long x, y , d, a ,b, obikolka, a1, b1;
cin>>x>>y>>d;
obikolka=x*100+y;
a=obikolka/4;
b=obikolka/4;
a1=a+(d/2);
b1=b-(d/2);
cout<<a1<<endl;
cout<<b1<<endl;
return 0;
}
