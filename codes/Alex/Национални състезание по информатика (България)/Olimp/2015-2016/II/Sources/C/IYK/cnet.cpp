#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 3005;

struct node
{
    int current_node, current_time;

    node(){}
    node(int current_node, int current_time)
    {
        this->current_node = current_node;
        this->current_time = current_time;
    }
};

int n, m, cnt_visited, min_time, current_min_time = INT_MAX, visited[maxN];
vector<int> graph[maxN], ans;

void bfs(int start_node)
{
    queue<node> q;
    q.push(node(start_node, 0));

    while(!q.empty())
    {
        int current_node = q.front().current_node, current_time = q.front().current_time;
        q.pop();


        if(visited[current_node] == start_node) continue;

        if(current_time > current_min_time)
        {
            min_time = current_min_time + 1;
            break;
        }
        visited[current_node] = start_node;
        cnt_visited++;
        if(current_time > min_time) min_time = current_time;

        for(int i = 0; i < graph[current_node].size(); i++)
        {
            int next_node = graph[current_node][i];
            if(visited[next_node] != start_node) q.push(node(next_node, current_time + 1));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
    }

    memset(visited, -1, sizeof(visited));
    for(int i = 0; i < n; i++)
    {
        cnt_visited = 0;
        min_time = 0;
        bfs(i);

        if(cnt_visited == n)
        {
            if(min_time == current_min_time) ans.push_back(i);
            else if(min_time < current_min_time)
            {
                ans.erase(ans.begin(), ans.end());
                ans.push_back(i);
                current_min_time = min_time;
            }
        }
    }

    cout<<ans.size()<<endl;
    if(ans.size() != 0) cout<<ans[0];
    for(int i = 1; i < ans.size(); i++)
    {
        cout<<" "<<ans[i];
    }
    cout<<endl;

    return 0;
}

