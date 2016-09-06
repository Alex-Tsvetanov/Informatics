// A C++ program to print topological sorting of a DAG
#include<iostream>
#include <set>
#include <stack>
using namespace std;
 
// Class to represent a graph
class Graph
{
public:
    int V;    // No. of vertices'
 
    // Pointer to an array containing adjacency listsList
    set<int, less <int>, allocator <int> > *adj;
 
    // A function used by topologicalSort
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
    Graph(int V);   // Constructor
 
     // function to add an edge to graph
    void addEdge(int v, int w);
 
    // prints a Topological Sort of the complete graph
    void topologicalSort();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new set<int, less <int>, allocator <int> >[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].insert(w); // Add w to v’s list.
}
 
// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[], 
                                stack<int> &Stack)
{
    // Mark the current node as visited.
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    auto i = adj [v].rbegin ();
    for (; i != adj[v].rend(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
 
    // Push current vertex to stack which stores result
    Stack.push(v);
}
 
// The function to do Topological Sort. It uses recursive 
// topologicalSortUtil()
void Graph::topologicalSort()
{
    stack<int> Stack;
 
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for (int i = V - 1; i >= 0; i--)
      if (visited[i] == false)
        topologicalSortUtil(i, visited, Stack);

    delete[] visited;
 
    // Print contents of stack
    while (Stack.empty() == false)
    {
        cout << Stack.top() << "\n";
        Stack.pop();
    }
}
// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0 ; i < m ; i ++)
    {
        int a, b;
        cin >> a >> b;
        g.addEdge (a, b);
    }
    g.topologicalSort();
 
    return 0;
}
