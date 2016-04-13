#include<iostream>
using namespace std;
int main(){
    long long a,b,c,d,izhod;
    bool MLP=false;
    cin>>a>>b>>c>>d;
    while(a>1000000000 or b>1000000000 or c>1000000000 or d>1000000000){
        cin>>a>>b>>c>>d;
    }
    if(a==b and c==d){
        izhod=a*c;
        MLP=true;
        cout<<"YES\n"<<izhod;
    }
    if(a==c and b==d and !MLP){
        izhod=a*b;
        MLP=true;
        cout<<"YES\n"<<izhod;
    }
    if(a==d and b==c and !MLP){
        izhod=a*b;
        MLP=true;
        cout<<"YES\n"<<izhod;
    }
    if(!MLP){
        cout<<"NO\n";
        cout<<a+b+c+d;
    }
return 0;
}
