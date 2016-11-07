#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
long long ans, x, y;
bool isPal(long long x)
{
   long long res=0, y=x;
    while(x!=0)
    {
        res=res*2+x%2;
        x/=2;
    }
    if (res==y)return true;
    else return false;
}
int main()
{
    cin>>x>>y;
    if(x%2==0) x++;
    for (long long i=x; i<=y; i+=2)
    {
        if (isPal(i))
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
