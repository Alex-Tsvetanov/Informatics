#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

int n, a, b, x, y, dist[200001], currdist, currv, sus, w;
vector<pair<int, int> > v[200001];
bool used[200001];
priority_queue<pair<int, int> > q;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>a>>b;
    while(cin)
    {
        cin>>x>>y;
        v[x].push_back(make_pair(y, 0));
        v[y].push_back(make_pair(x, 1));
    }
    for(int i=1;i<=n;++i)
    {
        dist[i]=INT_MAX;
    }
    dist[a]=0;
    q.push(make_pair(0, a));
    while(!q.empty())
    {
        currv=q.top().second;
        currdist=-q.top().first;
        q.pop();
        used[currv]=1;
        if(currdist>dist[currv])
        {
            continue;
        }
        for(int i=0;i<v[currv].size();++i)
        {
            sus=v[currv][i].first;
            w=v[currv][i].second;
            if(!used[sus] && dist[sus]>dist[currv]+w)
            {
                dist[sus]=dist[currv]+w;
                //printf("%d\n", dist[sus]);
                q.push(make_pair(-dist[sus], sus));
            }
        }
    }
    if(dist[b]==INT_MAX)
    {
        cout<<"X\n";
    }
    else
    {
        cout<<dist[b]<<"\n";
    }
    return 0;
}
/*
4 1 4
4 3
3 2
1 2
4 2
-----
4 1 4
4 3
3 2
4 2
*/