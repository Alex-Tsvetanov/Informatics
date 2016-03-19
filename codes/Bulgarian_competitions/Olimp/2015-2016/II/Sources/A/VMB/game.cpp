#include<iostream>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;
map<long long,long long>o;
long long cx,cy;
struct circle
{
    long long x;
    long long y;
    long long r;
    long long wu;
}a[10101];
bool cmp(circle b,circle c)
{
    return b.wu<c.wu;
}
long long x[20],y[20],s[20201],os[20201];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,m,q,i,cq,j,h,k;
    cin>>n>>m>>q;
    for(i=0;i<n;++i)
        cin>>a[i].x>>a[i].y>>a[i].r;
    for(i=0;i<m;++i)
        cin>>x[i]>>y[i];
    for(i=0;i<q;++i)
    {
        cin>>s[i*2];
        s[i*2+1]=s[i*2]*2;
        os[i]=s[i*2];
    }
    sort(s,s+q*2);
    cq=unique(s,s+q*2)-s;
    for(i=0;i<m;++i)
    {
        cx=x[i];
        cy=y[i];
        for(j=0;j<n;++j)
        {
            a[j].wu=(a[j].x-cx)*(a[j].x-cx)+(a[j].y-cy)*(a[j].y-cy);
            h=sqrt(a[j].wu);
            if(h*h!=a[j].wu)a[j].wu=h+1+a[j].r;
            else a[j].wu=h+a[j].r;
        }
        sort(a,a+n,cmp);
        j=0;
        a[n].wu=s[cq-1]+1;
        for(k=0;k<cq;++k)
        {
            while(a[j].wu<=s[k])
                ++j;
            o[s[k]]+=j;
        }
    }
    long long ans=0,l=1;
    for(i=0;i<q;++i)
    {
        if(l&1)l=o[os[i]];
        else l=o[os[i]*2];
        ans+=l;
    }
    cout<<ans<<'\n';
}
