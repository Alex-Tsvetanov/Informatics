#include<iostream>
using namespace std;
int main(){
    long long a1, a2, a3, n, poredno;
    cin>>a1>>a2>>a3>>n;
   // a1=2000000;
   // a2=2000000;
   // a3=2000000;
   // n=20;
    n-=3;
    for(int i=0;i<n;i++){
        poredno=a1+a2+a3;
        a1=a2;
        a2=a3;
        a3=poredno;
    }
    cout<<poredno<<endl;
return 0;
}
