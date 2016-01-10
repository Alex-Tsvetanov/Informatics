#include<iostream>
using namespace std;

int main ()
{
int a,b,c,d,y,n;
cin>>a >>b >>c >>d ;



 if (a==c && b==d && c>b|| b>c || c==b) {
  cout<<"YES"<<endl;
  cout<<c*b<<endl;

}
 if (a==b && d==b && d>b|| b>d || d==b){
  cout<<"YES"<<endl;
  cout<<d*b<<endl;

 if  (d==a && b==c && a>b|| b>a || a==b){
  cout<<"YES"<<endl;
  cout<<a*b<<endl;

}
if (b==a && c==d && c>a|| a>c || c==a) {
  cout<<"YES"<<endl;
  cout<<c*a<<endl;

}
if (a==c && b==d && c>b|| b>c || c==b) {
  cout<<"YES"<<endl;
  cout<<c*b<<endl;

}
if (a==c && d==b && c>d|| d>c || c==d) {
  cout<<"YES"<<endl;
  cout<<c*d<<endl;

}
if (b==d && a==c && d>a|| a>d || d==a) {
  cout<<"YES"<<endl;
  cout<<d*a<<endl;

}
if (a==d && b==c && d>b|| b>d || d==b){
  cout<<"YES"<<endl;
  cout<<d*b<<endl;

}
 if (a==c && d==b && c>d || d>c || c==d){
  cout<<"YES"<<endl;
  cout<<c*d<<endl;

 }
}
if ( d>b || a>b || c>b && b>c || a>c || d>c && a>d || b>d || c>d) {
  cout<<"NO"<<endl;
  cout<<a+b+c+d<<endl;



}
return 0;
}






















