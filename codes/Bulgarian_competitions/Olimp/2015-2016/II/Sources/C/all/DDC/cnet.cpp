#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<vector<int>> susedi;
queue<int> q;
vector<int> dist;

int main()
{
    int n, m;
    cin>>n>>m;
    susedi.resize(n);
    dist.resize(n);
    for(int i = 0; i<n; i++)
    {
        dist[i] = false;
    }
    for(int i = 0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        susedi[a].push_back(b);
    }
    for(int i = 0; i<n; i++)
    {
        long long sum = 0;
        for(int j = 0; j<n; j++)
        {
            dist[j] = false;
        }
        q.push(i);
        while(!q.empty())
        {
            int sq = q.front();
            q.pop();
            for(int &x:susedi[sq])
            {
                if(dist[x]==0 && x!=i)
                {
                    q.push(x);
                    dist[x]=dist[sq]+1;
                    sum += dist[x];
                }
            }
        }
        for(int j = 0; i<n; j++)
        {
            if(dist[j]==0 && j!=i)
            {
                goto GO;
            }
        }
        cout<<i<<" -> "<<sum<<endl;
        GO:
            i++;
            i--;
    }
    return 0;
}
