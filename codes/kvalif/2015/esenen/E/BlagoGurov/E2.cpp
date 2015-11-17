#include<iostream>
using namespace std;
int main (){
    long long m, c, k, kolkoM, kolkoC;
    cin>>m;
    while(m<0){
        cin>>m;
    }
    cin>>c;
    while(c<0){
        cin>>c;
    }
    cin>>k;
    while(k>=100){
        cin>>k;
    }
    kolkoM=m*k;
    kolkoC=c*k;
    while(kolkoC>=100){
        kolkoC=kolkoC-100;
        kolkoM=kolkoM+1;
    }
    cout<<kolkoM<<" "<<kolkoC;
return 0;
}
