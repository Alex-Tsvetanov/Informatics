#include <iostream>
#include "graph.h"

using namespace std;

int main ()
{
	G <int>	graph;
	graph
		 .add2Edges (0, 3, 9)
		 .add2Edges (0, 5, 4)
		 .add2Edges (0, 8, 5)
		 .add2Edges (1, 4, 8)
		 .add2Edges (1, 7, 7)
		 .add2Edges (2, 6, 12)
		 .add2Edges (3, 5, 2)
		 .add2Edges (3, 6, 8)
		 .add2Edges (3, 8, 20)
		 .add2Edges (4, 7, 10)
		 .add2Edges (6, 8, 7)
	;
	cout << "TEST" << endl;
	graph.dijikstra (
						[](vertexType a, int b)
						{
							cout << a << " -> " << b << endl;
						}
					);
	cout << "TEST" << endl;
	graph.MST (
					[](vertexType a, vertexType b)
					{
						cout << a << " -> " << b << endl;
					}
			  );
}
