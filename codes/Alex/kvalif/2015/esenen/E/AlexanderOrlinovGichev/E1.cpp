#include <iostream>
using namespace std;
int main () {
long long a;
long long b;
long long c;
cin>>a;
cin>>b;
cin>>c;
if((a+b==c)and(a*b==c)and(a-b==c))cout<<"*";
if((a+b==c)and(a*b==c)and(a-b!=c))cout<<"+";
if((a+b==c)and(a*b!=c)and(a-b==c))cout<<"-";
if((a+b!=c)and(a*b==c)and(a-b==c))cout<<"*";
if((a+b==c)and(a*b!=c)and(a-b!=c))cout<<"+";
if((a+b!=c)and(a*b==c)and(a-b!=c))cout<<"*";
if((a+b!=c)and(a*b!=c)and(a-b==c))cout<<"-";
if((a+b!=c)and(a*b!=c)and (a-b!=c))cout<<"0";
return 0;}
