#include <iostream>
#include <vector>
using namespace std;

vector<int> g[3072], l[3072], res;
int used[3072][3072], visited[3072];
int n, m, k=0;

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int x, y;
    cin>>n>>m;
    for (int i=0; i<m; i++)
    {
        cin>>x>>y;
        g[x].push_back(y);
    }
}

void dfs(int v)
{
    if (used[v][k]!=0) return;
    else used[v][k]=1;

    l[k].push_back(v);

    int len=g[v].size();
    for (int i=0; i<len; i++)
    {
        int u=g[v][i];
        dfs(u);
    }
}

void Print()
{
    int len=res.size();
    cout<<len<<endl;
    if (len!=0) cout<<res[0];
    for (int i=1; i<len; i++)
    {
        cout<<' '<<res[i];
    }
    if (len!=0) cout<<endl;
}

int main()
{
    Init();
    for (int i=0; i<n; i++)
    {
        if (visited[i]==0)
        {
            dfs(i);
            if (l[k].size()==n) res.push_back(i);
            else
            {
                int len=l[k].size();
                for (int j=0; j<len; j++)
                {
                    visited[l[k][j]]=1;
                }
            }
            k++;
        }
    }
    Print();
    return 0;
}
