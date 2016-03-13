#include<iostream>
using namespace std;
int main(){
    unsigned long long n, p=-1;
    cin>>n;
    for(int i=n;i>=1;i--)
        if(n%i==0 and ((n/i)*2+i*2<p or p==-1))p=(n/i)*2+i*2;
    cout<<p<<endl;
    return 0;
}
