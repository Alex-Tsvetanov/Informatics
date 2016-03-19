#include<iostream>
#include<cmath>
using namespace std;
long long fast_pow(long long a,long long b){
    if(a==0 || a==1)    return a;
    if(b==0)    return 1;
    if(b==1)    return a;
    if(b==2)    return a*a;
    return fast_pow(a*a,b/2)*fast_pow(a,b%2);
}
int main(){
    long long x;
    cin>>x;
    long long log=roundl(log2(x));
    long long a,how=0;
    string ans="\n";
    long long osn[30],ste[30];
    for(double i=2;i<=log+1;i++){
        a=roundl(pow(x,(double)(1/i)));
        if(fast_pow(a,i)==x){
            osn[how]=a;
            ste[how]=i;
            how++;
        }
    }
    cout<<how<<endl;
    for(long long i=0;i<how;i++){
        cout<<osn[i]<<" "<<ste[i]<<(i==how-1?"":"\n");
    }
}
