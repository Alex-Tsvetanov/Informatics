#include "graph.h"
#include <iostream>

using namespace std;

int main ()
{
	G < int > graph;
	int n, m;
	cin >> n >> m;
	for (int i = 0 ; i < m ; i ++)
	{
		vertexType a, b;
		const int c = 1;
		cin >> a >> b;
		graph.addEdge (a, b, c);
	}
	int q;
	cin >> q;
	for (int i = 0 ; i < q ; i ++)
	{
		int a, b;
		cin >> a >> b;
		cout << graph.bfs (a) [b] << "\n";
	}
}
