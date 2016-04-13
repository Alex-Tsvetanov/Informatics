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
	void eraseEdge (size_t a, size_t b)
	{
		for (vector <unsigned long long>::iterator it = n [a].begin () ; it != n [a].end () ; it ++)
			if (*it == b)
			{
				n [a].erase (it);
				break;
			}
		w [a][b] = make_pair (W(), false);
	}
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
	bool topological_sort (void func (unsigned long long), vector <unsigned long long> s = vector <unsigned long long> ()) const
	{
		if (s.size () == n.size ())
		{
			for (unsigned long long i = 0 ; i < s.size () ; i ++)
				func (i);
			return 1;
		}
		if (s.size () == 0)
			for (unsigned long long i = 0 ; i < n.size () ; i ++)
			{
				s.push_back (i);
				if (topological_sort (func, s))
				{
					return 1;
				}
				s.pop_back ();
			}
		else
			for (unsigned long long i = 0 ; i < n [s [s.size () - 1]].size () ; i ++)
			{
				s.push_back (n [s [s.size () - 1]][i]);
				if (topological_sort (func, s))
				{
					return 1;
				}
				s.pop_back ();
			}
	}
	int* dfs (unsigned long long s = 0ull, unsigned long long level = 0ull) const
	{
		bool* visited = new bool [n.size ()];
		int* levels = new int [n.size ()];
		for (size_t i = 0 ; i < n.size () ; i ++)
			levels [i] = -1;
		stack < pair < unsigned long long, unsigned long long > > st;
		st.push ({s, level});
		while (!st.empty ())
		{
			auto f = st.top (); st.pop ();
			levels [f.first] = f.second;
			for (auto& x : n [f.first])
				if (levels [x] == -1)
					st.push ({x, f.second + 1});
		}
		delete[] visited;
		return levels;
	}
	int* bfs (unsigned long long s = 0ull, unsigned long long level = 0ull) const
	{
		int* levels = new int [n.size ()];
		for (size_t i = 0 ; i < n.size () ; i ++)
			levels [i] = -1;
		queue < pair < unsigned long long, unsigned long long > > q;
		q.push ({s, level});
		while (!q.empty ())
		{
			auto f = q.front (); q.pop ();
			levels [f.first] = f.second;
			for (auto& x : n [f.first])
				if (levels [x] == -1)
					q.push ({x, f.second + 1});
		}
		return levels;
	}
	bool cycle () const
	{
		unsigned long long NO_PREVIOUS = -1;
		bool* visited = new bool [n.size ()];
		queue < pair < unsigned long long, unsigned long long > > q;
		q.push ({0, NO_PREVIOUS});
		while (!q.empty ())
		{
			auto f = q.front (); q.pop ();
			for (auto& x : n [f.first])
				if (f.second != x)
				{
					if (visited [x] == 0)
						q.push ({x, f.first});
					else
					{
						delete[] visited;
						return true;
					}
				}
		}
		delete[] visited;
		return false;
	}
};
