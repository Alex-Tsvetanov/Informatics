//Game - Dimitar Karev
#include<iostream>
#include<cmath>
#include<iomanip>
#include<climits>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

#define lli long long
using namespace std;

struct Circle
{
    int x,y,r;
}a[20000];

int Dist(int X,int Y, int X1,int Y1)
{
    lli D,p;
    D= (long long)(X-X1)*(X-X1)+(Y-Y1)*(Y-Y1) ;
    p=sqrt(D);

    if(p*p>=D)return p;
    return p+1;
}

vector<int>b[20];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,Q,X,Y,d;
    cin>>n>>m>>Q;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y>>a[i].r;
    }

    for(int i=1;i<=m;i++)
    {
        cin>>X>>Y;
        for(int j=1;j<=n;j++)
        {
            d=Dist(X,Y,a[j].x,a[j].y);
            b[i].push_back(d+a[j].r);
        }
        b[i].push_back(0);
        sort(b[i].begin(),b[i].end());
    }

    int s,Left,Right,Mid,l=0,sum=0,ans=0;
    for(int i=1;i<=Q;i++)
    {
        cin>>s;
        if(l)s*=2;

        l=0;sum=0;
        for(int i=1;i<=m;i++)
        {
            Left=0;
            Right=b[i].size();
            while(Left+1!=Right)
            {
                Mid=(Left+Right)/2;
                if(b[i][Mid]<=s)Left=Mid;
                else Right=Mid;

            }
            sum+=Left;
        }
        ans+=sum;
        if(sum%2==0)l=1;

    }
    cout<<ans<<"\n";
    return 0;
}
/*
4 2 4
2 2 1
3 5 2
6 2 3
8 8 1
4 4
0 0
4 3 3 200
*/
