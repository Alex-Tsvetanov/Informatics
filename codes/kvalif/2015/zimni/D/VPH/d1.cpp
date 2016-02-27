#include<iostream>
using namespace std;
int main(){
long long t1,t2,t3,n,t[100000],d=0;
cin>>t[0]>>t[1]>>t[2]>>n;

for(int i=3
    ; i<n; i++){
    t[i]=t[i-1]+t[i-2]+t[i-3];
}
cout<<t[n-1]<<endl;
return 0;
}
