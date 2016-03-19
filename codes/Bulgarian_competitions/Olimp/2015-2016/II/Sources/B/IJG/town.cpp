#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, a, b, p, q, used[200010], par[200010], dist[200010], x, ok, br, ok1, y, ans, k;
queue <int> q1;
vector <int> v[200010];
vector <int> v1[200010];
pair <int, int> paths[200010];
void bfs (int xx)
{
    used[xx]=1;
    q1.push(xx);
    par[xx]=0;
    dist[xx]=0;
    for (; !q1.empty();)
    {
        x=q1.front();
        q1.pop();
        for (int i=0; i<v[x].size(); i++)
        {
            if (used[v[x][i]]==0)
            {
                used[v[x][i]]=1;
                par[v[x][i]]=x;
                dist[v[x][i]]=dist[x]+1;
                q1.push(v[x][i]);
            }
        }
    }
}
void bfs1 (int xx)
{
    for (int i=1; i<=n; i++)
    {
        used[i]=0;
        par[i]=0;
        dist[i]=0;
    }
    used[xx]=1;
    q1.push(xx);
    par[xx]=0;
    dist[xx]=0;
    for (; !q1.empty();)
    {
        x=q1.front();
        q1.pop();
        for (int i=0; i<v1[x].size(); i++)
        {
            if (used[v1[x][i]]==0)
            {
                used[v1[x][i]]=1;
                par[v1[x][i]]=x;
                dist[v1[x][i]]=dist[x]+1;
                q1.push(v1[x][i]);
            }
        }
    }
}
int main ()
{
    scanf("%d%d%d", &n, &a, &b);
    for (; cin>>p>>q ;)
    {
        v[p].push_back(q);
        v1[p].push_back(q);
        v1[q].push_back(p);
    }
    bfs(a);
    if (dist[b]==0) ok=1;
    if (dist[b]!=0)
    {
        cout<<0<<endl;
        return 0;
    }
    bfs1(a);
    if (dist[b]==0) ok1=1;
    if (ok+ok1==2)
    {
        cout<<"X"<<endl;
        return 0;
    }
    if (ok==1)
    {
        paths[1].first=par[b];
        paths[1].second=b;
        x=par[b];
        br=1;
        for (int i=n; ; i--)
        {
            if (i==x)
            {
                br++;
                paths[br].first=par[i];
                paths[br].second=x;
                x=par[i];
                i=n;
            }
            if (x==a) break;
        }
        for (int i=br; i>=1; i--)
        {
            x=paths[i].first;
            y=paths[i].second;
            if (v[x].size()>=1)
            {
                for (int j=0; j<=v[x].size(); j++)
                {
                    if (v[x][j]==y) k++;
                }
            }
            else
            {
                ans++;
                k=1;
            }
            if (k==0) ans++;
            else k=0;
        }
        cout<<ans<<endl;
        return 0;
    }

    return 0;
}
