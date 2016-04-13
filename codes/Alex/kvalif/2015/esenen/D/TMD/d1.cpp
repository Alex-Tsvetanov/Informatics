#include<iostream>
using namespace std;
int main(){
long long n,i,minp=3000000;
cin>>n;
for(i=1;i<n/2;i++){
if(n%i==0){
if(minp>i+n/i){
minp=i+n/i;
}
}
}
cout<<minp*2;
return 0;
}
