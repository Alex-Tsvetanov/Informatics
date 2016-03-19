# include<iostream>
# include<vector>
# include<utility>
# include<queue>
# include<cstring>
using namespace std;


const int INF=5000;

vector<int> g[3001];
int t[3001],minma[3001],k;
int used[3001];
int n,m;
queue<pair<int,int> > q;
void deix(int u)
{
    for(int i=0; i<g[u].size(); i++) q.push(make_pair(g[u][i],u));
    used[u]=1;
    while(!q.empty())
    {
        pair<int,int> p=q.front();
        q.pop();
        used[p.first]=1;
       // cout<<q.size()<<" "<<p.first<<" "<<p.second<<endl;
        if(t[p.first]>t[p.second]+1 || t[p.first]==-1)
        {
            t[p.first]=t[p.second]+1;
            for(int i=0; i<g[p.first].size(); i++)
            {
                if(used[g[p.first][i]]==0)
                q.push(make_pair(g[p.first][i],p.first));
            }
        }
    }

}

int main()
{
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }


    /*for(int i=0; i<n; i++)
    {
        cout<<i<<": ";
        for(int j=0; j<g[i].size(); j++) cout<<g[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;*/

    int mint=INF;
    for(int i=0; i<n; i++)
    {
        //for(int j=0; j<n; j++) t[j]=INF;
        memset(t,-1,sizeof(t));
        t[i]=0;
        deix(i);
        memset(used,0,sizeof(used));
        for(int j=0; j<n; j++) if(t[j]==-1) {minma[i]=INF; break;}else if(minma[i]<t[j]) minma[i]=t[j];
        if(minma[i]<mint) mint=minma[i];
        //for(int j=0; j<n; j++) cout<<t[j]<<" ";
        //cout<<endl;
    }

    int ans[3001];
    int j=0;
    //cout<<mint<<endl;
    if(mint==INF) {cout<<0<<endl; return 0;}
    for(int i=0; i<n; i++)
    {
        if(minma[i]==mint) ans[j++]=i;
    }
    cout<<j<<endl;
    for(int i=0; i<j; i++) cout<<ans[i]<<" ";
    cout<<endl;
    /*
    8 13
    0 1
    0 2
    1 3
    3 0
    7 1
    3 5
    4 1
    4 5
    7 5
    5 2
    5 6
    4 7
    7 4
    */

}
