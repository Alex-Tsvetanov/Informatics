#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >v[200010];
int start,to,n;
long long level[200010];
int bla;
void alg(int x)
{
    priority_queue<pair<int,int> >pq;
    pq.push(make_pair(0,x));
    level[x]=0;
    while(pq.size()!=0)
    {
        int now=pq.top().second;
        pq.pop();
        for(int i=0;i<v[now].size();i++)
        {
            int next=v[now][i].first;
            int dist=v[now][i].second;
            if(dist+level[now]<level[next] || level[next]==-1)
            {
                level[next]=level[now]+dist;
                pq.push(make_pair(-dist,next));
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0;i<200010;i++)
        level[i]=-1;
    cin>>n>>start>>to;
    int a,b;
    while(cin>>a>>b)
    {
        v[a].push_back(make_pair(b,0));
        v[b].push_back(make_pair(a,1));
    }
    alg(start);
    long long now=level[to];
    if(now==-1)cout<<"X"<<endl;
    else cout<<now<<endl;
    return 0;
}
