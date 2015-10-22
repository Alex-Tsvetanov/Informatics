////GRAPH.H
#include <vector>  // vector
#include <utility> // pair
#include <set>     // set
#include <list>    // list
#include <stack>   // stack
#include <queue>   // queue

using namespace std;

using vertexType = unsigned long long;
typedef vector < vector < unsigned long long > > N;

template < typename W> class M:public vector < vector < pair < W, bool > > >
{
public:
	M () 
	{
		
	}
	void add (unsigned long long a, unsigned long long b, W c)
	{
		if (this -> size () < a)
			this -> resize (a + 1, vector < pair < W, bool > > ());
		if ((*this)[0].size () < b)
			for (unsigned long long i = 0 ; i < (*this).size () ; i ++)
				(*this)[i].resize (b + 1, pair < W, bool > (-1, false));
		(*this)[a][b] = make_pair (c, true);
	}
};

template < typename W > struct G
{
	unsigned long long size;
	void addEdge (size_t a, size_t b, W c = W ())
	{
		size_t Max = max (a, b);
		if (Max >= n.size ())
		{
			n.resize (Max + 1, vector <unsigned long long> ());
			w.resize (Max + 1);
			for (size_t i = 0 ; i < Max + 1 ; i ++)
			{
				w [i].resize (Max + 1);
			}
		}
		n [a].push_back (b);
		w [a][b] = make_pair (c, true);
		this->size = Max;
	}
	typedef M <W> T;
	N n;
	T w;
	bool edge(unsigned long long i, unsigned long long j) const
	{
		return (w[i][j].second);
	}
	W f(unsigned long long i, unsigned long long j) const
	{
		return w[i][j].first;
	}
	W f(pair <unsigned long long, unsigned long long> j) const
	{
		return w[j.first][j.second].first;
	}
	G(size_t Size)
	{
		size = Size;
		n.resize (Size + 1, vector < unsigned long long > ());
		w.resize (Size + 1);
		for (size_t i = 0 ; i < Size + 1 ; i ++)
			w [i].resize (Size + 1, make_pair (W (), true));
	}
	G()
	{
		size = 0;
	}
	
	void convert ()
	{
		for (unsigned long long i = 0 ; i < w.size () ; i ++)
			for (unsigned long long j = 0 ; j < w [i].size () ; j ++)
			{
				if (w [i][j].second)
				{
					n [i].push_back (j);
				}
			}
	}
	G (N n, T w)
	{
		this -> n = n;
		this -> w = w;
		size = n.size ();
	}
	G (T w)
	{
		this -> w = w;
		convert ();	
		size = n.size ();
	}
};
////GRAPH.H
#include <iostream>

void dfs (const G <int>& graph, int* cost, unsigned long long s = 0ull, bool* visited = nullptr)
{
	bool SetUpVisited = false;
	if (visited == nullptr)
	{
		SetUpVisited = true;
		visited = new bool [graph.n.size ()];
	}
	visited [s] = 1;
	int ans = 0;
	for (auto& x : graph.n [s])
	{
		if (visited [x] == 0)
			dfs (graph, cost, x, visited);
		ans += cost [x];
	}
	if (SetUpVisited)
		delete[] visited;
	if (ans == 0)
		ans = 1;
	cost [s] = ans;
	return ;
}

int main ()
{
	int n;
	cin >> n;
	G < int > graph (n);
	for (int i = 0 ; i < n ; i ++)
		for (int j = 0 ; j < n ; j ++)
		{
			char a;
			cin >> a;
			if (a == 'Y')
				graph.addEdge (i, j, 1);
		}
	int* costs = new int [n];
	bool* visited = new bool [n];
	for (int i = 0 ; i < n ; i ++)
		if (visited [i] == 0)
			dfs (graph, costs, i, visited);
	int sum = 0;
	for (int i = 0 ; i < n; i ++)
		sum += costs [i];
	cout << sum << "\n";
	delete[] costs;
	delete[] visited;
}
