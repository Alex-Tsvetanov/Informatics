#include <iostream>
#include <list>
#include <stack>
#include <map>

using namespace std;
 
map < int, int > graph;
map < int, int > ungraph;

set < int > ln [10];
vector < set < int > > ln;

int main()
{
	int n;
	cin >> n; 
	int br = 0;
	for (int i = 0 ; i < n ; i ++)
	{
		int x, y;
		string blq;
		cin >> x >> blq >> blq >> y;
		if (graph.find (x) == graph.end ())
		{
			graph [x] = br ++;
			ungraph [br] = x;
		}
		if (graph.find (y) == graph.end ())
		{
			graph [y] = br ++;
			ungraph [br] = y;
		}
		if (blq == "after")
		{
			g.addEdge (graph[y], graph[x]);
		}
		else
		{
			g.addEdge (graph [x], graph [y]);
		}
	}
	for (auto& x : graph)
		cout << x.first << " " << x.second << "\n";
    g.topologicalSort();
 
    return 0;
}
