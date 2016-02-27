#include <iostream>
using namespace std;
int main () {
long long n;
cin>>n;
long long T[n];
cin>>T[0]>>T[1]>>T[2];
T[n]=T[n-2]+T[n-3]+T[n-4];
cout<<T[n];
return 0;}
