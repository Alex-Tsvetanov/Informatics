#include <iostream>
using namespace std;
int main(){
long long a, b, c, d;
0<a, b, c, d;
a, b, c, d<100000000;
cin>>a>>b>>c>>d;
if(a==b or a==c or a==d ){
    if(a!=b and b==c or b==d){
        cout<<"YES"<<"\n";
        if(a==b){
            cout<<a*c;
        }else{
            cout<<a*b;
        }
    }else{
        cout<<"NO"<<"\n"<<a+b+c+d;
    }
}else{
    cout<<"NO"<<"\n"<<a+b+c+d;
}

return 0;
}
