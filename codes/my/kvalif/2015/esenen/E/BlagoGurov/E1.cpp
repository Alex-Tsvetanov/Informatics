#include<iostream>
using namespace std;
int main (){
long long a, b, c;
cin>>a;
cin>>b;
cin>>c;
if(a+b==c){
    cout<<"+";
    return 0;
}
if(a-b==c){
    cout<<"-";
    return 0;
}
if(a*b==c){
    cout<<"*";
    return 0;
}
cout<<"0";
return 0;
}
