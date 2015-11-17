#include<iostream>
using namespace std;
int main (){
long long m,c,k,c2,c3,c4;
cin>>m>>c>>k;
c3=c*k/100;
c4=c3;
c4=c4*100;
c2=c*k;
c=c2-c4;
cout<<m*k+c3<<c;
return 0;
}
