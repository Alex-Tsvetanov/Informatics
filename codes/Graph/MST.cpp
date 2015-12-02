#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
 
struct Edge
{
    int src, dest, weight;
};
 
struct Graph
{
    int V, E;
 
    Edge* edge;
};
 
Graph* createGraph(int V, int E)
{
    Graph* graph = (Graph*) malloc( sizeof(Graph) );
    graph->V = V;
    graph->E = E;
 
    graph->edge = (Edge*) malloc( graph->E * sizeof( Edge ) );
 
    return graph;
}
 
struct subset
{
    int parent;
    int rank;
};
 
int find(subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
 
void Union(subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
 
int myComp(const void* a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}
 
Edge* KruskalMST(Graph* graph)
{
    int V = graph->V;
    Edge* result = new Edge [V];
    int e = 0;
    int i = 0;
 
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
 
    subset *subsets =
        (subset*) malloc( V * sizeof(subset) );
 
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    
    while (e < V - 1)
    {
        Edge next_edge = graph->edge[i++];
 
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
 
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
 
    return result;
}
 
int main()
{
    int V;
  
    int E;

    cin >> V >> E;
   
    Graph* graph = createGraph(V, E);
    
    for (int i = 0 ; i < E ; i ++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph->edge [i].src = a;
        graph->edge [i].dest = b;
        graph->edge [i].weight = -c;
    }
    
    Edge* MST  = KruskalMST (graph);

    int Max = MST [0].weight;
    for (int i = 1 ; i < V ; i ++)
        if (Max < MST [i].weight)
            Max = MST [i].weight;
    delete[] MST;
    cout << Max << "\n";
 
    return 0;
}
