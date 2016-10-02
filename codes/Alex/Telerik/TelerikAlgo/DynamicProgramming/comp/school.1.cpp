#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int X, Y;
struct Edge
{
	int src, dest, weight;
};

struct Graph
{
	int V, E;

	struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = 
		(struct Graph*) malloc( sizeof(struct Graph) );
	graph->V = V;
	graph->E = E;

	graph->edge = 
		(struct Edge*) malloc( graph->E * sizeof( struct Edge ) );

	return graph;
}

void printArr(int dist[], int n)
{
	cout << dist [Y] << "\n";
}

void BellmanFord(struct Graph* graph, int src)
{
	int V = graph->V;
	int E = graph->E;
	int dist[V];

	for (int i = 0; i < V; i++)
		dist[i]   = INT_MIN;
	dist[src] = 0;

	for (int i = 1; i <= V-1; i++)
	{
		for (int j = 0; j < E; j++)
		{
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if (dist[u] != INT_MIN && dist[u] + weight > dist[v])
				dist[v] = dist[u] + weight;
		}
	}
	
	for (int i = 0; i < E; i++)
	{
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if (dist[u] != INT_MIN && dist[u] + weight > dist[v])
			cout << ("Graph contains negative weight cycle");
			//exit (127);
	}

	printArr(dist, V);

	return;
}

int main()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	int V, E;
	cin >> V >> E >> X >> Y;
	struct Graph* graph = createGraph(V, E);

	for (int i = 0 ; i < E ; i ++)
	{
		cin >> graph->edge[i].src >> graph->edge[i].dest >> graph->edge[i].weight;
	}

	BellmanFord(graph, X);

	return 0;
}
