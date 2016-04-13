#include <iostream>
#include "graph.h"

using namespace std;

template <typename T> void printGraph (G <T> graph)
{
	int ind = 0;
	for (auto& neibors : graph.n)
	{
		cout << ind ++ << ": ";
		for (auto& x : neibors)
			cout << x << " ";
		cout << "\n";
	}
}


template <typename T> vector <vertexType> articulations_vertexes (G <T> graph)
{
	vector <vertexType> ans;
	for (size_t i = 0 ; i < graph.n.size () ; i ++)
	{
		G <T> graph2 = graph;
		for (size_t j = 0 ; j < graph.n.size () ; j ++)
		{
			graph2.erase2Edges (i, j);
		}
		if (graph2.components () - 1 > 1)
			ans.push_back (i);
	}
	return move (ans);
}

template <typename T> void help (const G <T>& graph, int u, bool visited[], int disc[], int low[], int parent[], bool ap[])
{
    static int time = 0;

    int children = 0;
 
    visited[u] = true;
 
    disc [u] = low [u] = ++ time;

    for (auto& v : graph.n [u])
    {
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            help (graph, v, visited, disc, low, parent, ap);
 
            low[u]  = min(low[u], low[v]);
 
            if (parent[u] == -1 && children > 1)
               ap[u] = true;
 
            if (parent[u] != -1 && low[v] >= disc[u])
               ap[u] = true;
        }
 
        else if ((int)v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}

template <typename T> vector <vertexType> GetArticulationPoints (const G <T>& graph)
{
    vector<vertexType> ans;

    bool *visited = new bool[graph.n.size ()];
    int *disc = new int[graph.n.size ()];
    int *low = new int[graph.n.size ()];
    int *parent = new int[graph.n.size ()];
    bool *ap = new bool[graph.n.size ()];

    for (size_t i = 0; i < graph.n.size (); i++)
    {
        parent[i] = -1;
        visited[i] = false;
        ap[i] = false;
    }
 
    for (size_t i = 0; i < graph.n.size (); i++)
        if (visited[i] == false)
            help (graph, i, visited, disc, low, parent, ap);
 
    for (size_t i = 0; i < graph.n.size (); i++)
        if (ap[i] == true)
            ans.push_back (i);
    return move (ans);
}


int main ()
{
	G <none> graph;
	int n, m;
	cin >> n >> m;
	for (int i = 0 ; i < m ; i ++)
	{
		vertexType a, b;
		cin >> a >> b;
		graph.add2Edges (a, b);
	}
	for (auto& x : GetArticulationPoints (graph))
	{
		cout << x << endl;
	}
	for (auto& x : articulations_vertexes (graph))
	{
		cout << x << endl;
	}
}
