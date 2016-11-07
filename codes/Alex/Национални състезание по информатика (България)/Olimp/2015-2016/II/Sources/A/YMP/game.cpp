#include <iostream>
using namespace std;
struct okrujnost
{
    int a,b,c,d;
};
struct men
{
    int k,l;
};
int n,m,q,s[10001];
okrujnost o[10001];
men me[16];
void read()
{
    int i,x,y,z;
    cin>>n>>m>>q;
    for(i=1;i<=n;i++)
    {
        cin>>x>>y>>z;
        o[i].a=x-z;
        o[i].b=y-z;
        o[i].c=x+z;
        o[i].d=y+z;
    }
    for(i=1;i<=m;i++)
    {
        cin>>x>>y;
        me[i].k=x;
        me[i].l=y;
    }
    for(i=1;i<=q;i++)
    {
        cin>>s[i];
    }
}
void solve()
{
    int i,p,j,pl,br,ans=0,kappa=0;
    okrujnost t[16];
    for(i=1;i<=q;i++)
    {
        p=s[i];
        if(kappa)p*=2;
        for(j=1;j<=m;j++)
        {
            t[j].a=me[j].k-p;
            t[j].b=me[j].l-p;
            t[j].c=me[j].k+p;
            t[j].d=me[j].l+p;
        }
        br=0;
        for(pl=1;pl<=m;pl++)
        {
            for(j=1;j<=n;j++)
            {
                if(t[pl].a<o[j].a&&t[pl].b<o[j].b&&t[pl].c>o[j].c&&t[pl].d>o[j].d)br++;
            }
        }
        ans+=br;
        if(br%2==0)kappa=1;
        else kappa=0;
    }
    cout<<ans<<endl;
}
int main()
{
read();
solve();
return 0;
}
/*
4 1 3
2 2 1
3 5 2
6 2 3
8 8 1
4 4
4 3 3
*/
