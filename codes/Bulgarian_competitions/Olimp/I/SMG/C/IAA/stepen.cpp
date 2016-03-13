#include<iostream>
using namespace std;
int main(){

long long X;
long long a,b,c,d;
cin>>X;
a=0;
b=1;
c=X;
while(c>0){
    if(X/c==c){

    b++;
    X=X/c;
    if(X/c==1){
            a=c;
    cout<<b<<" "<<a<<"\n";

    }
    }



    c=c-1;
}



return 0;
}
