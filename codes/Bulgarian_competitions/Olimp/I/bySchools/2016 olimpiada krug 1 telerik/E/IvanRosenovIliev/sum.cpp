#include<iostream>
using namespace std;
int main() {
long long a, b, vqrnaSuma, greshnaSuma=0;
long long ediniciA=0, ediniciB=0;
long long deseticiA=0, deseticiB=0;
char znak = '+', znak2 = ' ';
cin>>a>>znak>>b;
vqrnaSuma=a+b;
greshnaSuma=vqrnaSuma;
deseticiA = a%100;
deseticiB = b%100;
ediniciA = deseticiA%10;
deseticiA = deseticiA-ediniciA;
ediniciB = deseticiB%10;
deseticiB = deseticiB-ediniciB;
if(ediniciA+ediniciB>10){
    greshnaSuma=greshnaSuma-10;
}
if(deseticiA+deseticiB>100){
    greshnaSuma=greshnaSuma-100;
}
cout<<greshnaSuma<<endl;
cout<<vqrnaSuma;
return 0;
}
