#include "graph.h"

int main ()
{
	G <int> a;
	a.add2Edges (0, 1, 1);
	a.add2Edges (0, 2, 1);
	a.add2Edges (1, 2, 3);
	a.make_non_changeable ();
	a.MST (G <int>::printMST);
}
