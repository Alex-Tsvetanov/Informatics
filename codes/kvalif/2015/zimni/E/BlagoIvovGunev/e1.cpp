#include<iostream>
using namespace std;
int main(){
    long long x,y,d,a,b,sm,ednodve,deldve;
    cin>>x>>y>>d;
    while(x>999999999 or y>999999999 or d>999999999){
        cin>>x>>y>>d;
    }
    sm=x*100+y;
    ednodve=sm/2;
    deldve=(ednodve-d)/2;
    a=deldve;
    b=deldve+d;
    cout<<b/100<<" "<<b%100<<"\n"<<a/100<<" "<<a%100;
return 0;
}
