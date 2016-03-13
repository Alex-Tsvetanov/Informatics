#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long d[15];
int s[15],g[30];
int main()
{
    long long n;
    int p=0;
    cin>>n;
    while(n%2==0)
    {
        n/=2;
        d[0]=2;
        s[0]++;
        p=1;
    }
    for(int i=3;n!=1;i+=2)
    {
        if(n%i==0)
        {
            d[p]=i;
        }
        while(n%i==0)
        {
            s[p]++;
            n/=i;
            if(n%i!=0)
            {
                p++;
            }
        }
    }
    int nod;
    if(p>0) nod=s[0];
    for(int i=1;i<p;i++)
    {
        nod=__gcd(nod,s[i]);
    }
    if(nod<2)
    {
        cout<<"0";
        return 0;
    }
    int f=0;
    for(int i=2;i<=nod;i++)
    {
        if(nod%i==0)
        {
            g[f]=i;
            f++;
        }
    }
    cout<<f<<"\n";
    int osn;
    for(int i=0;i<f;i++)
    {
        osn=1;
        for(int j=0;j<p;j++)
        {
            osn*=pow(d[j],s[j]/g[i]);
        }
        cout<<osn<<" "<<g[i]<<"\n";
    }
    return 0;
}
