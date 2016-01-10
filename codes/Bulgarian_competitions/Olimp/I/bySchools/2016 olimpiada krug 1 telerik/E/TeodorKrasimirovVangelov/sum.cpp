#include <iostream>
using namespace std;
int main (){
long A,B,c,c1,b,b1;
cin>>A>>B;
cout<<endl;

b=A/10;
b=b%10;

c=A%100;

b1=B/10;
b1=b1%10;

c1=B%100;

if(c+c1>=10){cout<<A-10+B<<endl;}
if(b+b1>=10){cout<<A-100+B<<endl;}

cout<<A+B<<endl;
return 0;
}
