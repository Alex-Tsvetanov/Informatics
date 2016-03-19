#include<iostream>
using namespace std;
long long ans=0;
long long p[10000000][5];
int main ()
{
    long long k,t;
    cin>>k;
    long long mn=1;
    while (1)
    {
        if (2*mn*(mn+1)>k+2*mn) {break;}
        t=(mn-1)*2+1;
        if ((k+t-mn)%(1+2*mn)==0) {p[ans][1]=(k+t-mn)/(1+2*mn); p[ans][2]=mn; ans++;}
        t++;
        if ((k+t-mn)%(1+2*mn)==0) {p[ans][1]=mn; p[ans][2]=(k+t-mn)/(1+2*mn); ans++;}
        mn++;
    }
    cout<<ans<<endl;
    for (int i=0; i<ans; i++)
    {
        cout<<p[i][1]<<" "<<p[i][2]<<endl;
    }
    return 0;
}
