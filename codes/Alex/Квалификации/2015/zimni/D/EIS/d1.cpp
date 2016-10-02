#include<iostream>
using namespace std;
int main (){
    long long n,t[100],i;
    cin>>t[0]>>t[1]>>t[2]>>n;
    for(i=3; i<n; i++){
        t[i]=t[i-1]+t[i-2]+t[i-3];

    }
cout<<t[n-1];
cout<<endl;
return 0;
}
