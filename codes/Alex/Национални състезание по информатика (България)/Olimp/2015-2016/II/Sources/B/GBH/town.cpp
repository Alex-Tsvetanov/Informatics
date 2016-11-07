#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define INF 1000000000
#define Max 500005
using namespace std;

struct compare
{
   bool operator()(pair<int,int> & l, pair<int,int> & r)
   {
       return l.first >= r.first;
   }
};

int visited[Max], path[Max];
vector< vector < pair < int , int > > > graph;
int n,a,b;

void dij(int v) {
    int countv,moment,weight;
    pair <int, int> p;
    priority_queue < pair < int , int > , vector < pair < int , int > > , compare > q;
    q.push(make_pair(0,v));
    visited[v]=1;
    path[v]=0;
    while (!q.empty())
    {
        p=q.top();
        q.pop();
        visited[p.second]=true;
        countv=graph[p.second].size();
        for (int i=0;i<countv;i++)
        {
            moment=graph[p.second][i].first;
            weight=graph[p.second][i].second;
            if (!visited[moment])
            {
                if (path[moment]>p.first+weight)
                {
                    path[moment]=p.first+weight;
                }
                //cout<<path[moment]<<' '<<moment<<endl;
                q.push(make_pair(path[moment],moment));
            }
        }
    }
}

void Init() {
    vector< pair <int, int> > v;
    int x,y;
    cin>>n>>a>>b;
    for (int i=0;i<=n;i++)
    {
        graph.push_back(v);
        visited[i]=0;
        path[i]=INF;
    }
    while(cin>>x>>y)
    {
        graph[x].push_back(make_pair(y,0));
        graph[y].push_back(make_pair(x,1));
    }
}

int main ()
{
    Init();
    dij(a);
    /*for (int i=1;i<=n;i++)
    {
        cout<<path[i]<<' ';
    }
    cout<<endl;*/
    if(path[b]!=INF) cout<<path[b]<<endl;
    else cout<<"X"<<endl;
    return 0;
}
/*    if(path[b]!=INF) cout<<path[b]<<endl;
    else cout<<"X"<<endl;
    return 0;
}*/
