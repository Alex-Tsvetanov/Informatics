#include<iostream>
using namespace std;
int main () {
long long T1, T2, T3, n, broqch=3, zbor;
cin>>T1>>T2>>T3>>n;
if(n==1){
   cout<<T1;
}
if(n==2){
    cout<<T2;
}
if(n==3){
    cout<<T3;
}

if(n==4){
    cout<<T3+T2+T1;
}

if(n==5){
    cout<<T1+2*T2+2*T3;
}

if(n==6){
    cout<<2*T1+3*T2+4*T3;

}

if(n==7){
    cout<<5*T1+7*T2+9*T3;
}

if(n==8){
    cout<<8*T1+12*T2+15*T3;
}

if(n==9){
    cout<<15*T1+22*T2+28*T3;
}

if(n==10){
    cout<<28*T1+41*T2+52*T3;
}
return 0;
}
