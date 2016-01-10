#include <iostream>
using namespace std;
int main(){
long int N,i=0,minc=1000001,maxc=-1,ngch=0,nmch=0;
cin>>N;
long int a[20000];
for(i=0;i<N;i++){
cin>>a[i];
}
for(i=0;i<N;i++){
if(a[i]<minc){
minc=a[i];
nmch=i;
}
if(a[i]>=maxc){
maxc=a[i];
ngch=i;
}
}
cout<<nmch+1<<" "<<ngch+1;
return 0;
}


