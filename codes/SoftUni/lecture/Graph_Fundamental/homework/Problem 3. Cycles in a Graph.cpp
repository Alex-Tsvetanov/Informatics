#include "graph.h"
#include <iostream>
#include <map>

using namespace std;

int main ()
{
	G < int > graph;
	map < char, int > vertexes;
	int number_of_vertexes = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 0 ; i < m ; i ++)
	{
		char a, b;
		const int c = 1;
		cin >> a >> b;
		if (vertexes.find (a) == vertexes.end ())
			vertexes [a] = number_of_vertexes ++;
		if (vertexes.find (b) == vertexes.end ())
			vertexes [b] = number_of_vertexes ++;
		graph.addEdge (vertexes [a], vertexes [b], c);
	}
	cout << "Acyclic: " << boolalpha << !graph.cycle () << "\n";
}
