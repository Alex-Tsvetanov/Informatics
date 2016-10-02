#include <iostream>
#include <set>
#include <stack>

using namespace std;
 
class Graph
{
public:
    int V;
 
    set <int, less <int>, allocator <int> > *adj;
 
    void topologicalSortUtil (int v, bool visited[], stack<int> &Stack);
    Graph (int V);
 
    void addEdge (int v, int w);
 
    void topologicalSort ();
};
 
Graph::Graph (int V)
{
    this->V = V;
    adj = new set<int, less <int>, allocator <int> > [V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].insert (w);
}
 
void Graph::topologicalSortUtil (int v, bool visited [], stack <int> &Stack)
{
    visited [v] = true;
 
    auto i = adj [v].rbegin ();
    for ( ; i != adj [v].rend() ; ++ i)
        if (!visited [*i])
            topologicalSortUtil (*i, visited, Stack);
 
    Stack.push (v);
}
 
void Graph::topologicalSort()
{
    stack<int> Stack;
 
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    for (int i = V - 1; i >= 0; i--)
      if (visited[i] == false)
        topologicalSortUtil(i, visited, Stack);

    delete[] visited;
 
    while (Stack.empty() == false)
    {
        cout << Stack.top() << "\n";
        Stack.pop();
    }
}

int main ()
{
    int n, m;
    cin >> n >> m;
    Graph g (n);
    for (int i = 0 ; i < m ; i ++)
    {
        int a, b;
        cin >> a >> b;
        g.addEdge (a, b);
    }
    g.topologicalSort ();
 
    return 0;
}
