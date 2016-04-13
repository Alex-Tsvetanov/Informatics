#include <iostream>
#include <cstdlib>
#include <climits>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;

struct dijkstra
{
    int to, len;
    inline dijkstra(int to, int len)
    {
        this->to=to;
        this->len=len;
    }

    inline bool operator < (const dijkstra &that)const
    {
        return len > that.len;
    }
};

vector<vector<int> > gr1, gr2;
int n, a, b;

void read()
{
    cin>>n>>a>>b;
    gr1.resize(n+1);
    gr2.resize(n+1);
    for(int x, y;!cin.eof();)
    {
        cin>>x>>y;
        gr1[x].push_back(y);
        gr2[y].push_back(x);
    }
}

void solve()
{
    vector<int> minTo(n+1, INT_MAX);
    priority_queue<dijkstra> q;

    q.push(dijkstra(a, 0));
    minTo[a]=0;

    while(!q.empty())
    {
        dijkstra cp=q.top();
        q.pop();

        if(minTo[cp.to]!=cp.len)continue;

        for(unsigned int i=0;i<gr1[cp.to].size();i++)
        {
            int newLen=cp.len,   newTo=gr1[cp.to][i];
            if(newLen<minTo[newTo])
            {
                minTo[newTo]=newLen;
                q.push(dijkstra(newTo, newLen));
            }
        }

        for(unsigned int i=0;i<gr2[cp.to].size();i++)
        {
            int newLen=cp.len+1, newTo=gr2[cp.to][i];
            if(newLen<minTo[newTo])
            {
                minTo[newTo]=newLen;
                q.push(dijkstra(newTo, newLen));
            }
        }
    }

    if(minTo[b]==INT_MAX)puts("X");
    else printf("%d\n", minTo[b]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    read();
    solve();
    return 0;
}
/*
4 1 4
4 3
3 2
1 2
4 2
        _ 1


4 1 4
4 3
3 2
4 2
        _ X

10 1 10
1 2
3 2
3 4
5 4
5 6
7 6
7 8
9 8
9 10
        _ 4

10 1 10
2 1
2 3
4 3
4 5
6 5
6 7
8 7
8 9
10 9
        _ 5

4 1 2
1 4
2 4
3 1
3 2
4 3
        _ 0

4 1 2
1 4
2 4
3 1
3 2
        _ 1
*/
