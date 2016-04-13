#include<iostream>
using namespace std;
int main(){
    long long t1,t2,t3,tn,N,minavaniq;
    cin>>t1>>t2>>t3>>N;
    long long t[N];
    t[0]=t1;
    t[1]=t2;
    t[2]=t3;
    for(minavaniq=3;minavaniq<N;minavaniq=minavaniq+1){
        t[minavaniq]=t[minavaniq-1]+t[minavaniq-2]+t[minavaniq-3];
    }
    cout<<t[N-1];
return 0;
}
