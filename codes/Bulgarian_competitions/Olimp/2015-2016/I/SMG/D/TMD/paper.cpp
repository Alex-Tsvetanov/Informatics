#include<iostream>
using namespace std;
int main(){
long long m,n,i,sb=0;
cin>>m>>n;
for(i=0;m>1;i++){
m=m/2+m%2;
}
sb+=i;
for(i=0;n>1;i++){
n=n/2+n%2;
}
cout<<sb+i<<endl;
return 0;
}
