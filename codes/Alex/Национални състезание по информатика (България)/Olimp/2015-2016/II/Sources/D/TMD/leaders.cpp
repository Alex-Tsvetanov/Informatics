#include<iostream>
using namespace std;
long long n,a[1000000],i,i2,pn;
int main(){
bool l=1;
cin>>n;
for(i=0;i<n;i++){
cin>>a[i];
}
for(i=0;i<n-1;i++){
for(i2=i+1;i2<n and l==1;i2++){
if(a[i]<a[i2] or a[i]<pn){
l=0;
if(a[i]>pn){
pn=a[i];
}
}
}
if(l==1){
cout<<a[i]<<" ";
}
l=1;
}
cout<<a[n-1]<<endl;
return 0;
}
