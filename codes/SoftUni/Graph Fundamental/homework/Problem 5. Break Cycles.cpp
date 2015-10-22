#include "graph.h"
#include <iostream>
#include <sstream>

using namespace std;

set < string > cycle (G < int > graph)
{
	set < string > ans;
	unsigned long long NO_PREVIOUS = -1;
	bool* visited = new bool [graph.n.size ()];
	for (size_t s = 0 ; s < graph.n.size () ; s ++)
	{
		if (visited [s] == 0)
		{
			queue < pair < unsigned long long, unsigned long long > > q;
			q.push ({s, NO_PREVIOUS});
			while (!q.empty ())
			{
				auto f = q.front (); q.pop ();
				visited [f.first] = 1;
				for (auto& x : graph.n [f.first])
					if (f.second != x)
					{
						if (visited [x] == 0)
							q.push ({x, f.first});
						else
						{
							stringstream ss;
							ss << "Remove Edge " << f.second + 1 << " -> " << f.first + 1 << "\n";
							ans.insert (ss.str ());
							graph.eraseEdge (f.second, f.first);
							goto BREAK;
						}
					}
			}
		}
		BREAK:
		{

		}
	}
	delete[] visited;
	return ans;
}

int main ()
{
	G < int > graph;
	int n, m;
	cin >> n >> m;
	for (int i = 0 ; i < m ; i ++)
	{
		int a, b;
		const int c = 1;
		cin >> a >> b;
		a --;
		b --;
		graph.addEdge (a, b, c);
		graph.addEdge (b, a, c);
	}
	auto a = cycle (graph);
	cout << a.size () << "\n";
	for (auto& x : a)
		cout << x << "\n";
}
/**
8 8
1 2             
2 3
3 5
5 1
1 4
6 7 
7 8
6 8
*/
