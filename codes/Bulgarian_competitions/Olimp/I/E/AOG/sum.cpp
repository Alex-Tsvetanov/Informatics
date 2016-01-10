#include <iostream>
using namespace std;
int main () {
long long a;
long long b;
long long A;
long long B;
long long C;
long long A1;
long long B1;
long long C1;
cin>>a>>b;
A=a%10;
B=a/10;
C=a/100;
A1=b%10;
B1=b/10;
C1=b/100;
cout<<(C+C1)<<(B+B1)%10<<(A+A1)%10<<endl;;
cout<<a+b<<endl;
return 0;}
