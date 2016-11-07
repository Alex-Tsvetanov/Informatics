#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;
bool used[200010],used1[200010];
vector<pair<long long,bool> >v[200010];
priority_queue<pair<long long,long long> > q;
long long n,a,b,ans=INT_MAX,rt,dist[200010];
void DFS(long long x)
{
    used[x]=1;
    for(long long i=0;i<v[x].size();i++)
    {
        long long next=v[x][i].first;
        if(!used[next])
        {
            DFS(next);
        }
    }
}
bool check()
{
    if(!used[a]||!used[b])
        return 0;
    return 1;
}
long long solve(long long x)
{
    for(long long i=1;i<=n;i++)
        dist[i]=INT_MAX;
    q.push(make_pair(0,x));
    dist[x]=0;
    used1[x]=1;
    for(;!q.empty();)
    {
        long long current=q.top().second;
        q.pop();
        for(long long i=0;i<v[current].size();i++)
        {
            long long next=v[current][i].first;
            dist[next]=min(dist[next],dist[current]+v[current][i].second);
            if(!used1[next])
            {
             used1[next]=1;
             q.push(make_pair(-dist[next],next));
            }
        }
    }
    return dist[b];
}
int main()
{
    cin>>n>>a>>b;
    long long x,y;
    for(;cin>>x>>y;)
    {
       v[x].push_back(make_pair(y,0));
       v[y].push_back(make_pair(x,1));
    }
    DFS(a);
    if(!check())
    {
       cout<<"X"<<endl;
       return 0;
    }
    ;
    cout<<solve(a)<<endl;
    return 0;
}
