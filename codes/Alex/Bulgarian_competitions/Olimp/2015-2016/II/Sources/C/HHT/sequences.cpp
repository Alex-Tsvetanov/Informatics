#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long p,n,s,powpn;
    powpn=pow(p,n);
    cin>>p>>n>>s;
    if((p-1)*n<s) cout<<pow(p,n);
    if((p-1)*n==s) cout<<pow(p,n)-1;
    if((p-1)*n==s+1) cout<<pow(p,n)-(n+1);
    if((p-1)*n==s+2 and p>2) cout<<pow(p,n)-((n*(n-1)/2+n)+n+1);
    if((p-1)*n==s+2 and p<=2) cout<<pow(p,n)-((n*(n-1)/2)+n+1);
    if((p-1)*n==s+3 and p>3) cout<<pow(p,n)-((n*(n-1)*(n-2)/6+n*(n-1)+n)+(n*(n-1)/2+n)+n+1);
    if((p-1)*n==s+3 and p==3) cout<<pow(p,n)-((n*(n-1)*(n-2)/6+n*(n-1))+(n*(n-1)/2+n)+n+1);
    if((p-1)*n==s+3 and p<3) cout<<pow(p,n)-(n*(n-1)+n+1);
    cout<<endl;
return 0;
}
