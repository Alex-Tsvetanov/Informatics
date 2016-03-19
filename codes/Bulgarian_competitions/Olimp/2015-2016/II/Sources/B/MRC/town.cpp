#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

struct point
{
    int x;
    int t;
};

bool operator<(point a, point b)
{
    return a.t>b.t;
}

int n;
int s,f;
int dist[500007];
vector<point> v[500007];
priority_queue<point> q;

void read()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s >> f;
    s--;
    f--;
    int a,b,c;
    point p;
    while(cin >> a)
    {
        a--;
        cin >> b;
        b--;
        p.x=b;
        p.t=0;
        v[a].push_back(p);
        p.x=a;
        p.t=1;
        v[b].push_back(p);
    }
}

void solve()
{
    int i;
    point p;
    for(i=0;i<n;i++)
    {
        if(i==s) continue;
        dist[i]=10000000;
    }
    for(i=0;i<v[s].size();i++)
    {
        dist[v[s][i].x]=v[s][i].t;
        q.push(v[s][i]);
    }
    while(!q.empty())
    {
        p=q.top();
        q.pop();

        for(i=0;i<v[p.x].size();i++)
        {
            if(dist[v[p.x][i].x]>dist[p.x]+v[p.x][i].t)
            {
                dist[v[p.x][i].x]=dist[p.x]+v[p.x][i].t;
                q.push(v[p.x][i]);
            }
        }
    }
    if(dist[f]!=10000000) printf("%d\n",dist[f]);
    else printf("X\n");
}

int main()
{
    read();
    solve();
    return 0;
}
