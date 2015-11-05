#include <iostream>

using namespace std;

#include "/home/alex/GIT/informaticsGit/codes/TelerikKids/25.10.2015/graph.h"

void print (vertexType i, vertexType j, int w)
{
	cout << "\t" << i << " " << j << " " << w << "\n";
}

int main ()
{
	int n, m;
	cin >> n >> m;
	G <int> graph;
	for (int i = 0 ; i < m ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph.add2Edges (a, b, c);
	}
	cout << "End" << endl;
	graph.MST (print);
}
