#include<iostream>
#include<cmath>
using namespace std;
int maxrast=0,mqsmin=0,mqsmax=0;
int maxrastoqnie(int mesta[],int mqstonamax,int p,int n,int maxrast)
{
    int i,k;
    for(i=0;i<p;i++)
    {
        k=abs(mesta[i]-mqstonamax);
        if(maxrast<k)
        {
            maxrast=k;
            mqsmin=mesta[i];
            mqsmax=mqstonamax;
        }
    }
    return maxrast;
}
int main()
{
    int n,p=0,i,minn=1000001,maxx=0,mqstonamax;
    cin>>n;
    int a[n],mesta[n];

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        if(minn>a[i])
        {
            minn=a[i];
        }
        if(maxx<a[i])
        {
            maxx=a[i];
        }
    }
    for(i=0;i<n;i++)
    {
        if(a[i]==minn)
        {
            mesta[p]=i;
            p++;
        }
    }
    int srav;
    for(i=0;i<n;i++)
    {
        if(a[i]==maxx)
        {
            mqstonamax=i;
            srav=maxrastoqnie(mesta,mqstonamax,p,n,maxrast);
        }
    }
    cout<</*maxx<<" "<<minn<<" "<<srav<<" "<<*/mqsmin+1<<" "<<mqsmax+1;
    return 0;
}
