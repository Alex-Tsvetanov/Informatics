#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long a[1001],p,n,s,i,j,br=0,sum,ch,k=1;
    cin>>p>>n>>s;
    sum=s-1;
    ch=p-1;
    if(sum==0 || ch==0){cout<<1<<endl;}
    else
    {
        for(i=1; i<=n; i++)
        {
            k=k*i;
        }
        br=k+s-p;
    }
    cout<<br<<endl;
    return 0;
}
