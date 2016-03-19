#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct st
{
    int x,y,z;
};
int n,m,q;
st a[16384],b[16];
int c[16384];
int p[16][100000];
int SqrtDist(st x,st y)
{
    double x1=(double)(x.x);
    double x2=(double)(y.x);
    double y1=(double)(x.y);
    double y2=(double)(y.y);
   // cout<<x1<<" "<<y1<<'\n';
   // cout<<x2<<" "<<y2<<'\n';
   //cout<<'\n';
    //cout<<(double)(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)))<<'\n';
   // cout<<ceil((double)(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))))<<'\n';
   // cout<<ceil((sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))))<<'\n';
    return ceil((double)(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y>>a[i].z;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i].x>>b[i].y;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            p[j][SqrtDist(a[i],b[j])+a[i].z]++;
        }
    }
    /*for(int i=1;i<=20;i++)
    {
        cout<<p[1][i]<<" ";
    }cout<<'\n';*/
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=40009;j++)
        {
            p[i][j]+=p[i][j-1];
        }
    }

   /*for(int i=1;i<=20;i++)
    {
        cout<<p[1][i]<<" ";
    }cout<<'\n';*/
    int x,br,prev_score=1,ans=0;
    for(int i=1;i<=q;i++)
    {
        cin>>x;
        if(prev_score%2==0)x*=2;
        br=0;
        for(int j=1;j<=m;j++)
        {
            br+=p[j][x];
        }
        prev_score=br;
        ans+=br;
    }
    cout<<ans<<'\n';
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




4 2 8
0 1 1
0 3 1
0 5 1
0 7 1
0 0
0 8
1 2 3 4 1 6 1 8

*/
