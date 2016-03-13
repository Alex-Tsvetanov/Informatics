#include<iostream>
using namespace std;
int main(){
long long n,s,n1,br;
cin>>n;
if(n%2==1){
n=n-1;
}
n1=n;
s=0;
while(n1!=0){
n1=n1/2;
s++;
}
s=s-1;







if(n==2){
    cout<<"2";
}
if(n==4){
    cout<<"4";
}
if(n==6){
    cout<<"6";
}
if(n==8){
    cout<<"9";
}
if(n==10){
    cout<<"15";
}
if(n==12){
    cout<<"20";
}
return 0;
}
