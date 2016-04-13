#include<iostream>
#include<algorithm>
using namespace std;
long long a,b,N,i=0,z[1000000],h[1000000],y[1000000];
int main(){
    cin>>N;
for(i=1;i<N+1;i++){
    if(N%i==0){
        h[i]=N/i;
    }
}

for(i=1;i<N+1;i++){
        if(h[i]==0){
            y[i]=0;
        }else{
   y[i]=h[i]*2+i*2;}
}
long long nai_maluk;
nai_maluk=10000;
for(i=1;i<N+1;i++){
        if(y[i]>0){
        if(y[i]<nai_maluk){
            nai_maluk=y[i];
        }
        }
}
cout<<nai_maluk;
cout<<endl;
return 0;
}
