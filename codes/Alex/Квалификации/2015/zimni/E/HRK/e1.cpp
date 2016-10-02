#include<iostream>
using namespace std;
int main(){
    long long x,y,d,sf,sfx,sfy,ss,ssx,ssy,sbor,sbord,sborc;
    cin>>x>>y;
    cin>>d;
    sbor=x*100+y;
    sbord=sbor-d*2;
    sf=sbord/4;
    sfy=sf%100;
    sfx=sf/100;
    sbord=sbor-sf*2;
    sborc=sbord/2;
    ssx=sborc/100;
    ssy=sborc%100;
    cout<<ssx<<" "<<ssy<<endl;
    cout<<sfx<<" "<<sfy;

    return 0;
}
