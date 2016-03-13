#include<iostream>
using namespace std;
int main(){
    long long tf,ts,tt,n,chis=0,i;
    cin>>tf>>ts>>tt>>n;
    for(i=3;i<n;i++){
        chis=tf+ts+tt;
        tf=ts;
        ts=tt;
        tt=chis;
    }
    if(n==1){
        chis=tf;

    }
    if(n==2){
        chis=ts;

    }
    if(n==3){
        chis=tt;

    }
    cout<<chis;

    return 0;
}
