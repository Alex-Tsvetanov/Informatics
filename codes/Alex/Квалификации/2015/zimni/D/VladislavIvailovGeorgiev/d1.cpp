#include<iostream>
using namespace std;
int main(){
    long long t, t1, t2, t3, n;
    cin>>t1>>t2>>t3>>n;
    n-=3;
    while(n>0){
        t=t1+t2+t3;
        t1=t2;
        t2=t3;
        t3=t;
        n--;
    }
    cout<<t<<endl;
    return 0;
}
