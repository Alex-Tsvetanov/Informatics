#include<iostream>
using namespace std;
int main()
{
    int n,m,a[n],b[m],x,y,S,l,z;
    cin>>x>>y;
    n=x+1;
    m=y;
    for (int i;i<m;i++) cin>>b[i];
    for (int k;k<n;k++) cin>>a[k];
    z=x%b[m-1];
    if (z=0)
    {
        z=x%b[m-2];
        l=x-z-1;
        if (a[l+1]=0)
        {
            l=x-b[m-2]-z-1;
        }
        else l=x-z-1;
    }
    else l=x-z-1;
    if (a[l+1]=0)
    {
        l=x-b[m-1]-z-1;
    }
    else l=x-z-1;
    if (a[l+1]=0)
    {
        l=l-2;
    }
    else l=x-z-1;
    if (n<2*b[0])
    {
        S=a[0]+a[b[0]];
    }
    else
        if (n<3*b[0])
        {
            S=a[0]+a[b[0]]+a[2*b[0]];
        }
        else
        if (n<4*b[0])
        {
            S=a[0]+a[2*b[0]]+a[3*b[0]];
        }
        else
            if (n<5*b[0])
        {
            S=a[0]+a[b[0]]+a[2*b[0]]+a[3*b[0]]+a[4*b[0]];
        }
        else S=a[0]+a[b[0]]+a[2*b[0]]+a[3*b[0]]+a[4*b[0]]+a[5*b[0]];
    cout<<S<<" "<<l<<endl;
    return 0;
}
