#include <sstream>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
std::map < int, int > graph;
std::map < int, int > ungraph;
#define MAXN 100
struct topologicalsort
{
	int n;
	int A[MAXN][MAXN];
	int used[MAXN];
	int topsort[MAXN];
	topologicalsort ()
	{
		for (int i = 0 ; i < MAXN ; i ++)
		{
			for (int j = 0 ; j < MAXN ; j ++)
				A [i][j] = 0;
			used [i] = 0;
		}
	}
	std::vector <std::string> a;
	void printSort()
	{ 
		std::stringstream ss;
		int i;
		for (i = 0; i < n; i++) 
			ss << ungraph [topsort[i]];
		a.push_back (ss.str ());
	}
	void fullTopSort(int count)
	{ 
		int i, j, k, saved[MAXN];
		if (count == n) 
		{ 
			printSort(); 
			return; 
		}
		for (i = 0; i < n; i++) 
		{
			if (!used[i]) 
			{
				for (j = 0; j < n; j++)
					if (A[j][i]) 
						break;
				if (j == n) 
				{
					for (k = 0; k < n; k++) 
					{
						saved[k] = A[i][k]; 
						A[i][k] = 0;
					}
					used[i] = 1;
					topsort[count] = i;
					fullTopSort(count + 1);
					used[i] = 0;
					for (k = 0; k < n; k++) 
						A[i][k] = saved[k];
				}
			}
		}
	}
} topological_sort;
int main ()
{
	int n;
	std::cin >> n; 
	int br = 0;
	for (int i = 0 ; i < n ; i ++)
	{
		int x, y;
		std::string blq;
		std::cin >> x >> blq >> blq >> y;
		if (graph.find (x) == graph.end ())
		{
			graph [x] = br;
			ungraph [br] = x;
			br ++;
		}
		if (graph.find (y) == graph.end ())
		{
			graph [y] = br;
			ungraph [br] = y;
			br ++;
		}
		if (blq == "after")
		{
			topological_sort.A [graph [y]][graph[x]] = 1;
		}
		else if (blq == "before")
		{
			topological_sort.A [graph [x]][graph[y]] = 1;
		}
	}
	topological_sort.n = graph.size ();

	topological_sort.fullTopSort(0);
	std::sort (topological_sort.a.begin (), topological_sort.a.end ());
	std::cout << topological_sort.a [0] << std::endl;
	return 0;
}
