#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::cin;
using std::sort;
using std::pair;

struct edge : public pair < int, pair < int, int > > 
{ 
	edge (int from, int to, int weight)
	{
		this->first = weight;
		this->second.first = from;
		this->second.second = to;
	}
	
	const int from () const 
	{ return this->second.first; } 
	
	const int to () const 
	{ return this->second.second; } 
	
	const int weight () const 
	{ return this->first; } 
};

vector < edge > edges;
vector <int> parent;

int Find (int x)
{
	return ((parent [x] == x) ? x : (parent [x] = Find (parent [x]))); 
}

bool connected (int x, int y)
{
	return (Find (x) == Find (y));
}

int Union (int x, int y)
{
	return (parent [x] = Find (y));
}

int main ()
{
	int n, m;
	cin >> n >> m;
	
	for (int i = 0 ; i < n ; i ++)
		parent.push_back (i);

	for (int i = 0 ; i < m ; i ++)
	{
		int a, b, c;

		cin >> a >> b >> c;
		edges.push_back (edge (b, a, c));
		edges.push_back (edge (a, b, c));
	}

	sort (edges.begin (), edges.end ());

	for (auto& x : edges)
	{
		if (not connected (x.from (), x.to ()))
		{
			Union (x.from (), x.to ());
			cout << x.weight () << " " << x.from () << ", " << x.to () << "\n";
		}
	}
}
