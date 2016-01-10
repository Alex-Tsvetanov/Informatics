#include <iostream>
using namespace std;
int main () {
long a,b,c,d;
cin>>a>>b>>c>>d;
cout<<endl;

if(a==b && c==d){cout<<"YES"<<endl;cout<<a*d<<endl;}
else{if(a==c && b==d){cout<<"YES"<<endl;cout<<a*b<<endl;}
     if(a==d && b==c){cout<<"YES"<<endl;cout<<a*b<<endl;}
     else{cout<<"NO"<<endl;cout<<a+b+c+d<<endl;}}

return 0;
}
