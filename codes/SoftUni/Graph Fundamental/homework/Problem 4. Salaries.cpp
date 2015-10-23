////GRAPH.H
#include <vector>  // vector
#include <utility> // pair

using namespace std;

using vertexType = size_t;
using N = vector < vector < vertexType > >;

template < typename W> class M:public vector < vector < pair < W, bool > > >
{
public:
	M () 
	{
		
	}
	void add (vertexType a, vertexType b, W c)
	{
		if (this -> size () < a)
			this -> resize (a + 1, vector < pair < W, bool > > ());
		if ((*this)[0].size () < b)
			for (vertexType i = 0 ; i < (*this).size () ; i ++)
				(*this)[i].resize (b + 1, pair < W, bool > (-1, false));
		(*this)[a][b] = make_pair (c, true);
	}
};

template < typename W > struct G
{
	vertexType size;
	void addEdge (size_t a, size_t b, W c = W ())
	{
		size_t Max = max (a, b);
		if (Max >= n.size ())
		{
			n.resize (Max + 1, vector <vertexType> ());
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
	bool edge(vertexType i, vertexType j) const
	{
		return (w[i][j].second);
	}
	W f(vertexType i, vertexType j) const
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
		n.resize (Size + 1, vector < vertexType > ());
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
		for (vertexType i = 0 ; i < w.size () ; i ++)
			for (vertexType j = 0 ; j < w [i].size () ; j ++)
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

template <typename T>void dfs (const G <T>& graph, int64_t* cost, vertexType s = 0ull)
{
	if (graph.n [s].size () == 0)
		cost [s] = 1;
	else
		for (auto& x : graph.n [s])
		{
			if (cost [x] == 0)
				dfs (graph, cost, x);
			cost [s] += cost [x];
		}
	return ;
}

int main ()
{
	int n;
	cin >> n;
	G < int64_t > graph (n);
	for (int i = 0 ; i < n ; i ++)
		for (int j = 0 ; j < n ; j ++)
		{
			char a;
			cin >> a;
			if (a == 'Y')
				graph.addEdge (i, j, 1);
		}
	int64_t* costs = new int64_t [n];
	for (int i = 0 ; i < n ; i ++)
		if (costs [i] == 0)
			dfs (graph, costs, i);
	int64_t sum = 0;
	for (int i = 0 ; i < n ; i ++)
		sum += costs [i];
	cout << sum << "\n";
	delete[] costs;
}
