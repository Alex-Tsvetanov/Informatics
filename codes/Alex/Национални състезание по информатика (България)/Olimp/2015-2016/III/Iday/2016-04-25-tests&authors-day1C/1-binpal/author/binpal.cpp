#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
long long x, y;
long long Reverse(long long x)
{
    long long res=0;
    while(x!=0)
    {
        res=res*2+x%2;
        x/=2;
    }
    return res;
}

long long scan(long long x)
{
    long long ans=0;
    long long n=0;
    long long z=x;
    while(z!=0)
    {
        n++;
        z/=2;
    }
    if(n==1) return 1;
    for (int i=1; i<n; i++)
    {
        if (i%2==0)
        {
            ans+=(1ll<<(i/2-1));
        }
        else
        {
            ans+=(1ll<<(i-1)/2);
        }
    }
    if(n%2==0)
    {
        ans+=(x>>(n/2))-(1ll<<(n-1)/2);
        long long temp=x>>(n/2);
        temp*=(1ll<<n/2);
        temp+=Reverse(x>>(n/2));
        if(temp<=x) ans++;
    }
    else
    {
        ans+=((x>>(n+1)/2)-(1ll<<(n-3)/2))*2;
        long long temp=x>>(n+1)/2;
        temp*=(1ll<<(n+1)/2);
        temp+=Reverse(x>>(n+1)/2);
        if(temp<=x) ans++;
        if (temp+(1ll<<(n-1)/2)<=x) ans++;
    }
   return ans;
}
int main()
{
    cin>>x>>y;
    if(x>1)
      cout<<scan(y)-scan(x-1)<<endl;
    else cout<<scan(y)<<endl;
    return 0;
}
