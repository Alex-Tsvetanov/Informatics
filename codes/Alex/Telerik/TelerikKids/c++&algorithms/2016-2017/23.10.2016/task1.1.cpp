#include <iostream>
#include <list>
#include <stack>

using std::cin;
using std::cout;
using std::string;
using std::list;
using std::stack;

bool inc [26];
 
class Graph
{
    int V;    
 
    list<int> *adj;
 
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);
 
    void addEdge(int v, int w);
 
    void topologicalSort();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
 
void Graph::topologicalSortUtil(int v, bool visited[], 
                                stack<int> &Stack)
{
    visited[v] = true;
 
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
 
    Stack.push(v);
}
 
void Graph::topologicalSort()
{
    stack<int> Stack;
 
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    for (int i = 0; i < V; i++)
      if (inc [i] and visited[i] == false)
        topologicalSortUtil(i, visited, Stack);
 
    while (Stack.empty() == false)
    {
        cout << (char)(Stack.top() + 'a') << " ";
        Stack.pop();
    }
}
 
int main()
{
    Graph g(26);
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		string a;
		cin >> a;
		for (int _1 = 0 ; _1 < a.size () ; _1 ++)
		{
			inc [a [_1] - 'a'] = true;
			for (int _2 = _1 + 1 ; _2 < a.size () ; _2 ++)
				g.addEdge (a [_1] - 'a', a [_2] - 'a');
		}
	}
 
    g.topologicalSort();
 
    return 0;
}
