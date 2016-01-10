#include <iostream>
using namespace std;
int main(){
long int N,i=0,pav=1000001,pal=-1,par=0,paz=0;
cin>>N;
long int a[20000];
for(i=0;i<N;i++){
cin>>a[i];
}
for(i=0;i<N;i++){
if(a[i]<pav){
pav=a[i];
paz=i;
}
if(a[i]>=pal){
pal=a[i];
par=i;
}
}
cout<<paz+1<<" "<<par+1;
return 0;
}
