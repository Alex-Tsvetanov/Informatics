#include<bits/stdc++.h>
using namespace std;
long long n,a,b,x,y;
vector<int> v[200010];
queue<int> q;
bool used[200010];
long long usedb[200010];

void dfs(int i)
{
    used[i]=true;
    for(int j=0;j<v[i].size();j++)
    {
        if(v[i][j]==b)
        {
            cout<<0<<"\n";
            exit(0);
        }
        if(!used[v[i][j]])
        {
            dfs(v[i][j]);
        }
    }
}
void bfs(int i)
{
    q.push(i);
    usedb[i]=true;
    long long tp;
    while(!q.empty())
    {
        tp=q.front();
        q.pop();
        for(int j=0;j<v[tp].size();j++)
        {
            if(used[v[tp][j]])
            {
                cout<<usedb[tp]<<"\n";
                exit(0);
            }
            if(!usedb[v[tp][j]])
            {
                q.push(v[tp][j]);
                usedb[v[tp][j]]=(usedb[tp]+1);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>a>>b;
    while(cin)
    {
        cin>>x>>y;
        v[x].push_back(y);
    }
    dfs(a);
    bfs(b);
    cout<<"X\n";
    return 0;
}
