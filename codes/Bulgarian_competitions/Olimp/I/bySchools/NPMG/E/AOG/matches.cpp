#include <iostream>
using namespace std;
int main () {
long long a;
long long b;
long long c;
long long d;
cin>>a>>b>>c>>d;
if(a==b and c==d or a==c and d==b or a==d and b==c){
cout<<"YES"<<endl;
if(a==b==c==d){
cout<<a*a;
}
if(a==b and d==c and a!=c and a!=d){
cout<<a*d;
}
if(a==c and d==b and a!=d and a!=b){
cout<<a*d;}
if(a==d and c==b and a!=c and a!=b){
cout<<a*c;
}
}
else{cout<<"NO"<<endl<<a+b+c+d;}
return 0;}
