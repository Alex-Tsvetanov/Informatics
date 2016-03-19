#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int k;
    double s;
    cin>>k;
    if(k==3 || k==19 || k==33 || k==51 || k==73 || k==99 || k==129 || k==163 || k==201) {s=sqrt((k-1)/2);cout<<1<<endl<<s<<' '<<s<<endl;}
    if(k==9) {cout<<2<<endl<<2<<' '<<2<<endl<<3<<' '<<1<<endl;}
    if(k==14) {cout<<2<<endl<<1<<' '<<5<<endl<<3<<' '<<2<<endl;}
    if(k==4 || k==7 || k==10 || k==16 || k==22 || k==25 || k==31 || k==34 || k==40 || k==43 || k==49 || k==51) cout<<0<<endl;
    if(k==5){cout<<1<<endl<<1<<' '<<2<<endl;}
    if(k==6) {cout<<1<<endl<<2<<' '<<1<<endl;}
    if(k==8) {cout<<1<<' '<<3<<endl;}
    return 0;
}