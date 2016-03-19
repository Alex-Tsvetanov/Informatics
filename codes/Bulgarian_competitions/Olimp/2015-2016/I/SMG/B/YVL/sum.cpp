#include<iostream>
using namespace std;
long long a[7000];
long long res(int n){
    n--;
    a[0]=1;
    a[1]=2;
    a[2]=2;
    a[3]=4;
    a[4]=4;
    a[5]=6;
    a[6]=6;
    int sz=7, crntSz=7;
    for(;sz<n+1;){
        for(int i=sz/2;i<sz&&sz<n+1;i++){
            a[crntSz]=a[i]+a[crntSz-1];
            a[crntSz+1]=a[i]+a[crntSz-1];
            crntSz+=2;
            sz=crntSz;
        }
    }
    return a[n];
}
int main(){
    int n;
    cin>>n;
    cout<<res(n)<<"\n";
    return 0;
}
