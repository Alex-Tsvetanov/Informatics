#include<iostream>
using namespace std;
int main(){
long long a,b,c,d,plosht,obikolka,mojeLi;
cin>>a>>b>>c>>d;
plosht=a*b;
obikolka=a+b+c+d;

if(a==c and b==d){
    mojeLi=true;
}
if(a!=c or b!=d){
    mojeLi=false;
}
if(mojeLi==true){
    cout<<"YES"<<"\n";
    cout<<plosht;
}
if(mojeLi==false){
    cout<<"NO"<<"\n";
    cout<<obikolka;
}
return 0;
}
