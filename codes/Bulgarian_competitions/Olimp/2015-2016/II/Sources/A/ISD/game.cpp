#include<iostream>
#include<map>
#include<cmath>
#include<cstdio>
using namespace std;
struct pnt
{
    int x,y;
};
struct circ
{
    int x,y;
    int r;
} c[10001];
pnt p[10001];
int n,m,q;
int a[10001];
int cnt[11][20021];
long long ans=0;
int check(pnt aa,circ bb)
{
    double xx,yy;
    double cx,cy,ra;
    xx=double(aa.x);yy=double(aa.y);
    cx=double(bb.x);cy=double(bb.y);ra=double(bb.r);
    double len=sqrt((xx-cx)*(xx-cx)+(yy-cy)*(yy-cy))+ra;
    int ll=int(len);
    //double lol=double(ll);
  //  cout<<lol<<" "<<len<<endl;
    //return ll;
    return ll+1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   // freopen("a.txt","r",stdin);
    cin>>n>>m>>q;
    for(int i=0;i<n;i++)
    {
        cin>>c[i].x>>c[i].y>>c[i].r;
    }
    for(int i=0;i<m;i++)
    {
        cin>>p[i].x>>p[i].y;
    }
    for(int i=0;i<q;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
        for(int j=0;j<=20020;j++)cnt[i][j]=0;
  //  for(int i=0;i<q;i++)cin>>a[i];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int res=check(p[i],c[j]);
           if(res<=20020) cnt[i][res]++;
        }
    }
    for(int i=0;i<m;i++)
    {
        int crr=0;
        for(int j=0;j<=20020;j++)
        {
            if(cnt[i][j])crr+=cnt[i][j],cnt[i][j]=crr;
            else cnt[i][j]=crr;
        }
    }
    int prev=-1;
    for(int i=0;i<q;i++)
    {
        int crr=0;
        int tg=a[i];
        if(prev%2==0)tg*=2;
        for(int j=0;j<m;j++)
            crr+=cnt[j][tg];
        prev=crr;
        ans+=crr;
    }
    cout<<ans<<endl;
    return 0;
}


