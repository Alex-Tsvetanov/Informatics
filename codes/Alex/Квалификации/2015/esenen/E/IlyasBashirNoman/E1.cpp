#include<iostream>
using namespace std;
int main (){
long long a,b,c,d;
d=1;
cin>>a>>b>>c;
if(a+b==c){
    if(d==1){
        cout<<"+";
        d=d-1;
    }
}
if(a-b==c){
    if(d==1){
        cout<<"-";
        d=d-1;
    }
}
if(a*b==c){
    if(d==1){
        cout<<"*";
        d=d-1;
    }
}
if(d==1){
    cout<<"0";
}
return 0;
}
