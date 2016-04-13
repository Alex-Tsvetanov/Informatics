#include <iostream>
using namespace std;
int main ()
{
int A, B, C, X, sum=7;
cin>>A>>B>>C;
if(A>B) {X-A; X=A; A=B;}
if(B>C) {X-B; X=B; B=C;}
if(C>A) {X-C; X=C; C=A;}
cout<<sum<<endl;
return 0;
}
