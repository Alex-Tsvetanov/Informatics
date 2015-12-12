#include<iostream>
using namespace std;
int main(){
    long long chas1,min1,chas2,min2;
    long long otgChas,otgMin;
    char znak;
    cin>>chas1>>znak>>min1;
    cin>>chas2>>znak>>min2;
    min1=min1+chas1*60;
    min2=min2+chas2*60;
    if(min2<min1){
        min2+=1440;
    }
    otgMin=min2-min1;
    otgChas=otgMin/60;
    otgMin%=60;
    if(otgChas<10){
        cout<<"0";
    }
    cout<<otgChas<<":";
    if(otgMin<10){
        cout<<"0";
    }
    cout<<otgMin<<"\n";
    return 0;
}
