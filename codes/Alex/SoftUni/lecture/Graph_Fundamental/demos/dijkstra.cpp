#include <iostream>
#include "graph.h"

using namespace std;

int main ()
{
	G <int> g;
	int n, m;
	cin >> n >> m;
	for (int i = 0 ; i < m ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g.addEdge (a, b, c);	
	}
	g.dijikstra ([](unsigned long long a, int b){cout << a << " -> " << b << "\n";});
	cout << flush;
	
}
