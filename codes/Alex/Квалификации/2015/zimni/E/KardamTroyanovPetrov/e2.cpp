#include<iostream>
using namespace std;
int main(){
int T1,T2,T3,N;
///N=Tn
cin>>T1>>T2>>T3>>N;
///T1+T2+T3=N
N=T1-1+T2-2+T3+3;
T1,T2,T3=2000000000;
N<=20;
///Tn=Tn-1+Tn-2+Tn-3;Tn=Tn*3-6
cout<<N;
return 0;
}
