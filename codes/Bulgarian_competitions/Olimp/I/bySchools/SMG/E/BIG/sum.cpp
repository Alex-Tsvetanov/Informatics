#include<iostream>
using namespace std;
int main(){
    long long ch1,ch2,izhod;
    cin>>ch1>>ch2;
    while(ch1<100 or ch1>999 or ch2<100 or ch2>999){
        cin>>ch1>>ch2;
    }
    izhod=(ch1%10+ch2%10)%10+(ch1%100/10*10+ch2%100/10*10)%100+(ch1/100*100+ch2/100*100);
    cout<<izhod<<"\n";
    izhod=ch1+ch2;
    cout<<izhod;
return 0;
}
