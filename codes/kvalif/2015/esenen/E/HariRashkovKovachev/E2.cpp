#include<iostream>
using namespace std;
int main(){
long long m,c,k;
cin>>m>>c>>k;
m=m*k;
c=c*k;
while(c>=100){
    m=m+1;
    c=c-100;
}
cout<<m<<" "<<c;
return 0;
}
