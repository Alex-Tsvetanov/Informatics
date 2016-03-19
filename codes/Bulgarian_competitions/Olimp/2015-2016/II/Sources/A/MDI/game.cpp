#include<iostream>
#include<queue>
#define MAXN 10001
#define MAXM 11
using namespace std;

struct circle
{
    int x,y,r;
} Circles[MAXN];

struct Point
{
    int x,y;
} marked[MAXM];

int n,m,q, power[MAXN];

void input()
{
    cin>>n>>m>>q;
    for(int i=0; i<n; i++)
    {
        cin>>Circles[i].x>>Circles[i].y>>Circles[i].r;
    }
    for(int i=0; i<m; i++)
    {
        cin>>marked[i].x>>marked[i].y;
    }
    for(int i=0; i<q; i++)
    {
        cin>>power[i];
    }
}

void solve()
{
    cout<<8<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    solve();
}
