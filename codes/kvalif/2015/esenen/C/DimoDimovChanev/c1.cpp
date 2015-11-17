#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> poznanstva;
vector<bool> obhodeni;
queue<int> Q;

void bfs(int x)
{
    Q.push(x);
    while(!Q.empty())
    {
        int sq = Q.front();
        Q.pop();
        obhodeni[sq] = true;
        for(auto &x:poznanstva[sq])
        {
            if(!obhodeni[x])
            {
                Q.push(x);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    poznanstva.resize(n);
    for(int i = 0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        poznanstva[a-1].push_back(b-1);
        poznanstva[b-1].push_back(a-1);
    }
    obhodeni.resize(n);
    int res = 0;
    for(int i = 0; i<n; i++)
    {
        if(!obhodeni[i])
        {
            res++;
            bfs(i);
        }
    }
    cout<<res<<'\n';
    return 0;
}
