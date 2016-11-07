#include<iostream>
using namespace std;
int main(){
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    if((a==b and c==d)or(a==c and b==d)or(a==d and b==c)){
        cout<<"YES"<<endl;
    if(a==b or a==d){
        cout<<a*c;
    }else{
        if(a==c){
            cout<<a*b;
        }
    }
    }else{
        cout<<"NO"<<endl<<a+b+c+d;
    }
    cout<<endl;
return 0;
}
