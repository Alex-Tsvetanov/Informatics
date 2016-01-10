#include<iostream>
using namespace std;
int main(){
long int N,i=0,min=1000001,max=-1,maxc=0,minc=0;
cin>>N;
long int a[20000];
for(i=0;i<N;i++){
cin>>a[i];
}
for(i=0;i<N;i++){
if(a[i]<min){
min=a[i];
minc=i;
}
if(a[i]>=max){
max=a[i];
maxc=i;
}
}
cout<<minc+1<<" "<<maxc+1;
return 0;
}
