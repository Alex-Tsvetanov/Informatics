#include <iostream>
#include "graph.h"

using namespace std;

int main ()
{
	G <int> a;
	a.add2Edges (0, 1, 3);
	a.add2Edges (0, 2, 2);
	a.add2Edges (1, 2, 1);
	a.MST (G<int>::printMST);
	cout << "Before \'return 0\'\n";
	return 0;
}
