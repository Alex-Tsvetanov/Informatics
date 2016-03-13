#include<iostream>
using namespace std;
int main(){
unsigned int n,br=2;
unsigned long long brvarianti[30000];
cin>>n;
brvarianti[1]=1;
brvarianti[2]=2;
brvarianti[3]=2;
brvarianti[4]=4;
brvarianti[5]=4;
for(int i=6;i<30000;i=i+2){
    brvarianti[i]=brvarianti[i-2]+br;
    brvarianti[i+1]=brvarianti[i];
    br=br+2;
    if(i==n&&(i+1)==n){
        break;
    }
}
cout<<brvarianti[n]<<endl;
return 0;
}
