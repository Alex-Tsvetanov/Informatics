#include<iostream>
using namespace std;
int main () {
long long a,b,c;
cin>>a>>b>>c;
if(c==a+b){
    cout<<"+";
}else{
if(c==a-b){
    cout<<"-";
}else{
if(c==a*b){
    cout<<"*";
}else{
cout<<"0";
}
}
}

return 0;
}
