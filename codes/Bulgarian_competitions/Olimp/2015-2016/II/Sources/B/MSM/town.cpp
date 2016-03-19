#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF=40000002;
const int MAXN=400002;
#define pp pair<int,int>

vector<int> g[MAXN];
int d[MAXN],d2[MAXN],prev[MAXN];
bool used[MAXN];
int n,a,b,p,k;
priority_queue<pp> q;

void Dijkstra(int s)
{
    for(int i=0;i<n;i++)
    {
        d[i]=INF;
        used[i]=0;
    }

    d[s]=0;
    q.push(pp(0,s));
    while(!q.empty())
    {
        int u=q.top().second;
        int cur_d=-q.top().first;

        q.pop();

        if(cur_d>d[u]) continue;
        used[u]=1;

        int z=g[u].size();
        for(int i=0;i<z;i++)
        {
            int v=g[u][i];

            if(used[v]==0 && d[v]>d[u]+1)
            {
                d[v]=d[u]+1;

                q.push(pp(-d[v],v));
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>a>>b;
    a--;
    b--;

    while(cin>>p>>k)
    {
        p--;
        k--;
        g[p].push_back(k);
    }

    Dijkstra(b);

    for(int i=0;i<n;i++)
        d2[i]=d[i];

    Dijkstra(a);

    if(d[b]!=INF)
    {
        cout<<0<<endl;
        return 0;
    }

    int ans=INF;

    for(int i=0;i<n;i++)
        if(d[i]!=INF && d[i]!=0 && d2[i]!=INF && d2[i]!=0 && d2[i]<ans) ans=d2[i];

    if(ans==INF) cout<<"X"<<endl;
    else cout<<ans<<endl;

    return 0;
}
