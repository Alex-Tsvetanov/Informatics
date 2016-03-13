#include <iostream>
#include "graph.h"
#include "../../../C++_To_C-Sharp/System.cpp"

using namespace std;

int main ()
{
	G <int> g;
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		vector < string > input = ConsoleReadLine ().Split ();
		for (int j = 0 ; j < (int)input.size () ; j ++)
			g.addEdge (i, atoi (input [j].c_str ()));	
	}
	g.dfs ([](unsigned long long a, unsigned long long b){cout << a << " " << b << "\n";});
	
}
