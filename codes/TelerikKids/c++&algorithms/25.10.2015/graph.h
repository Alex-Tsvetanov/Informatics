#include <vector>    // vector
#include <utility>   // pair
#include <set>       // set
#include <list>      // list
#include <stack>     // stack
#include <queue>     // queue
#include <algorithm> // sort

using namespace std;

using vertexType = size_t;
typedef vector < vector < vertexType > > N;

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
	static const W NOT_CREATED = -1;
protected:
	size_t Size;
public:

	inline G <W>& add2Edges (vertexType a, vertexType b, W c = W ())
	{
		return this->addEdge (a, b, c).addEdge (b, a, c);
	}

	G <W>& addEdge (vertexType a, vertexType b, W c = W ())
	{
		vertexType Max = max (a, b);
		if (Max < n.size ())
		{
			n [a].push_back (b);
			w [a][b] = make_pair (c, true);
		}
		else
		{
			n.resize (Max + 1, vector <vertexType> ());
			w.resize (Max + 1);
			for (vertexType i = 0 ; i < Max + 1 ; i ++)
			{
				w [i].resize (Max);
			}
		}
		this->Size = Max + 1;
		return *this;
	}

	typedef M <W> T;
	N n;
	T w;

	inline bool edge(vertexType i, vertexType j) const
	{
		return (w[i][j].second);
	}

	G <W>& eraseEdge (vertexType a, vertexType b)
	{
		if (edge (a, b))
		{
			for (vector <vertexType>::iterator it = n [a].begin () ; it != n [a].end () ; it ++)
				if (*it == b)
				{
					n [a].erase (it);
					break;
				}
			w [a][b] = make_pair (W(), false);
		}
		return *this;
	}

	inline G <W>& erase2Edges (vertexType a, vertexType b)
	{
		return this->eraseEdge (a, b).eraseEdge (b, a);
	}

	inline W f(vertexType i, vertexType j) const
	{
		if (w[i][j].second == false)
			return NOT_CREATED;
		return w[i][j].first;
	}

	inline W f(pair <vertexType, vertexType> j) const
	{
		return f (j.first, j.second);
	}

	G ()
	{
		Size = 0;
	}

	~G ()
	{
		n.~vector ();
		w.~M ();
	}

	void convertTtoN ()
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
		Size = n.size ();
	}

	G (T w)
	{
		this -> w = w;
		convertTtoN ();
		Size = n.size ();
	}

	bool topological_sort (void func (vertexType), vector <vertexType> s = vector <vertexType> ()) const
	{
		if (s.size () == n.size ())
		{
			for (vertexType i = 0 ; i < s.size () ; i ++)
				func (i);
			return 1;
		}
		if (s.size () == 0)
			for (vertexType i = 0 ; i < n.size () ; i ++)
			{
				s.push_back (i);
				if (topological_sort (func, s))
				{
					return 1;
				}
				s.pop_back ();
			}
		else
			for (vertexType i = 0 ; i < n [s [s.size () - 1]].size () ; i ++)
			{
				s.push_back (n [s [s.size () - 1]][i]);
				if (topological_sort (func, s))
				{
					return 1;
				}
				s.pop_back ();
			}
	}

	int* dfs (vertexType s = 0ull, vertexType level = 0ull, bool* visited = nullptr) const
	{
		bool Set = (visited == nullptr);
		if (visited == nullptr)
			visited = new bool [n.size ()];
		int* levels = new int [n.size ()];
		for (size_t i = 0 ; i < n.size () ; i ++)
			levels [i] = -1;
		stack < pair < vertexType, vertexType > > st;
		st.push ({s, level});
		while (!st.empty ())
		{
			auto f = st.top (); st.pop ();
			levels [f.first] = f.second;
			for (auto& x : n [f.first])
				if (levels [x] == -1)
					st.push ({x, f.second + 1});
		}
		if (Set)
			delete[] visited;
		return levels;
	}

	size_t components () const
	{
		size_t ans = 0;
		bool* visited = new bool [n.size ()];
		for (size_t i = 0 ; i < n.size () ; i ++)
			if (!visited [i])
			{
				dfs (i, 0, visited);
				ans ++;
			}
		delete[] visited;
		return ans;
	}

	int* bfs (vertexType s = 0ull, vertexType level = 0ull) const
	{
		int* levels = new int [n.size ()];
		for (size_t i = 0 ; i < n.size () ; i ++)
			levels [i] = -1;
		queue < pair < vertexType, vertexType > > q;
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
		vertexType NO_PREVIOUS = -1;
		bool* visited = new bool [n.size ()];
		queue < pair < vertexType, vertexType > > q;
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
private:
	/*inline */vertexType Find_root (vertexType i, vertexType* parent) const
	{
		if (parent [i] == i)
		{
			cout << i << endl;
			return i;
		}
		else
			return (parent [i] = Find_root (parent [i], parent));
		/*vector < vertexType > children;
		while (parent [i] != i)
		{
			children.push_back (i);
			i = parent [i];
		}
		for (auto& x : children)
			parent [x] = i;
		children.~vector ();
		return i;*/
	}
	inline void Union (vertexType i, vertexType j, vertexType* parent) const
	{
		vertexType a, b;
		parent [a = Find_root (i, parent)] = (b = Find_root (j, parent));
	}
public:
	void MST(void func(vertexType, vertexType, W))
	{
		Size = n.size ();
		vertexType* parent = new vertexType [Size];
		for (size_t i = 0 ; i < Size ; i ++)
			parent [i] = i;
		vector < pair < W, pair < vertexType, vertexType > > > edges;
		for (vertexType i = 0 ; i < Size ; i ++)
			for (auto& x : n [i])
				if (edge (i, x))
					edges.push_back ({f (i, x), {i, x}});
		sort (edges.begin (), edges.end ());
		for (size_t i = 0 ; i < edges.size () ; i ++)
		{
			auto edge = edges [i];
			if (Find_root (edge.second.first, parent) != Find_root (edge.second.second, parent))
			{
				func (edge.second.first, edge.second.second, edge.first);
				Union (edge.second.first, edge.second.second, parent);
			}
		}
		delete[] parent;
	}

private:

	struct fun2
	{
		bool operator () (pair < W *, unsigned long long >i, pair < W *, unsigned long long >j)
		{
			if (*(i.first) == *(j.first))
				return i.second > j.second;
			return *(i.first) > *(j.first);
		}
	};

public:
	void dijikstra(
			void func (vertexType, W),
			vertexType s = 0ll) const
	{
		set < pair < W *, vertexType >, fun2 > T_;
		W* d = new W [Size];
		for (vertexType i = 0; i < Size; i++)
			d[i] = f (s, i);
		d [s] = 0;
		for (vertexType i = 0; i < Size; i++)
			T_.insert (make_pair (&d[i], i));
		while (T_.size () > 0)
		{
			//for (size_t i = 0 ; i < Size ; i ++)
			//	cout << d [i] << " ";
			//cout << endl;
			//for (auto& x : T_)
			//	cout << *(x.first) << " ";
			//cout << endl;

			vertexType j = T_.begin ()->second;

			T_.erase (T_.begin());
			for (typename set < pair < W *, vertexType >, fun2 >::iterator it = T_.begin (); it != T_.end (); it ++)
			{
				vertexType i = it->second;
				if (edge (j, i))
					if (d [i] == NOT_CREATED or d [i] < (d [j] + f (j, i)))
					{
						d [i] = (d [j] + f (j, i));
						it = T_.erase (it);
						it --;
						T_.insert ({&(d [i]), i});
					}
			}
		}
		for (size_t i = 0; i < Size; i++)
			if (i != s)
				func (i, d [i]);
			else
				func (s, 0);
		delete[] d;
	}
};

struct none {

};

template <> struct G <none>
{
	using W = int;
	static const int NOT_CREATED = -1;
	size_t size;

	inline G <none>& add2Edges (vertexType a, vertexType b)
	{
		return this->addEdge (a, b).addEdge (b, a);
	}

	G <none>& addEdge (vertexType a, vertexType b)
	{
		vertexType Max = max (a, b);
		if (Max < n.size ())
		{
		}
		else
		{
			n.resize (Max + 1, vector <vertexType> ());
			w.resize (Max + 1);
			for (vertexType i = 0 ; i < Max + 1 ; i ++)
				w [i].resize (Max);
		}
		n [a].push_back (b);
		w [a][b] = make_pair (1, true);
		this->size = Max + 1;
		return *this;
	}

	typedef M <W> T;
	N n;
	T w;

	inline bool edge(vertexType i, vertexType j) const
	{
		return (w[i][j].second);
	}

	G <none>& eraseEdge (vertexType a, vertexType b)
	{
		if (edge (a, b))
		{
			for (vector <vertexType>::iterator it = n [a].begin () ; it != n [a].end () ; it ++)
				if (*it == b)
				{
					n [a].erase (it);
					break;
				}
			w [a][b] = make_pair (1, false);
		}
		return *this;
	}

	inline G <none>& erase2Edges (vertexType a, vertexType b)
	{
		return this->eraseEdge (a, b).eraseEdge (b, a);
	}

	W f (vertexType i, vertexType j) const
	{
		if (w[i][j].second == false)
			return NOT_CREATED;
		return w[i][j].first;
	}

	W f (pair <vertexType, vertexType> j) const
	{
		return w[j.first][j.second].first;
	}

	G ()
	{
		size = 0;
	}

	void convertTtoN ()
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
		convertTtoN ();
		size = n.size ();
	}

	bool topological_sort (void func (vertexType), vector <vertexType> s = vector <vertexType> ()) const
	{
		if (s.size () == n.size ())
		{
			for (vertexType i = 0 ; i < s.size () ; i ++)
				func (i);
			return 1;
		}
		if (s.size () == 0)
			for (vertexType i = 0 ; i < n.size () ; i ++)
			{
				s.push_back (i);
				if (topological_sort (func, s))
				{
					return 1;
				}
				s.pop_back ();
			}
		else
			for (vertexType i = 0 ; i < n [s [s.size () - 1]].size () ; i ++)
			{
				s.push_back (n [s [s.size () - 1]][i]);
				if (topological_sort (func, s))
				{
					return 1;
				}
				s.pop_back ();
			}
	}

	int* dfs (vertexType s = 0ull, vertexType level = 0ull, int* levels = nullptr) const
	{
		bool Set = (levels == nullptr);
		if (Set)
		{
			levels = new int [n.size ()];
			for (size_t i = 0 ; i < n.size () ; i ++)
				levels [i] = -1;
		}
		stack < pair < vertexType, vertexType > > st;
		st.push ({s, level});
		while (!st.empty ())
		{
			auto f = st.top (); st.pop ();
			levels [f.first] = f.second;
			for (auto& x : n [f.first])
				if (levels [x] == -1)
					st.push ({x, f.second + 1});
		}
		return levels;
	}

	size_t components () const
	{
		size_t ans = 0;
		int* levels = new int [n.size ()];
		for (size_t i = 0 ; i < n.size () ; i ++)
			levels [i] = -1;
		for (size_t i = 0 ; i < n.size () ; i ++)
			if (levels [i] == -1)
			{
				ans ++;
				dfs (i, 0, levels);
			}
		delete[] levels;
		return ans;
	}

	int* bfs (vertexType s = 0ull, vertexType level = 0ull) const
	{
		int* levels = new int [n.size ()];
		for (size_t i = 0 ; i < n.size () ; i ++)
			levels [i] = -1;
		queue < pair < vertexType, vertexType > > q;
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
		vertexType NO_PREVIOUS = -1;
		bool* visited = new bool [n.size ()];
		queue < pair < vertexType, vertexType > > q;
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
private:
	template <typename T> void help (const G <T>& graph, int u, bool visited[], int disc[], int low[], int parent[], bool ap[])
	{
		static int time = 0;

		int children = 0;
	 
		visited[u] = true;
	 
		disc [u] = low [u] = ++ time;

		for (auto& v : graph.n [u])
		{
			if (!visited[v])
			{
				children++;
				parent[v] = u;
				help (graph, v, visited, disc, low, parent, ap);
	 
				low[u]  = min(low[u], low[v]);
	 
				if (parent[u] == -1 && children > 1)
				   ap[u] = true;
	 
				if (parent[u] != -1 && low[v] >= disc[u])
				   ap[u] = true;
			}
	 
			else if ((int)v != parent[u])
				low[u]  = min(low[u], disc[v]);
		}
	}
public:
	template <typename T> vector <vertexType> GetArticulationPoints ()
	{
		const G <T> graph = *this;
		vector<vertexType> ans;

		bool *visited = new bool[graph.n.size ()];
		int *disc = new int[graph.n.size ()];
		int *low = new int[graph.n.size ()];
		int *parent = new int[graph.n.size ()];
		bool *ap = new bool[graph.n.size ()];

		for (size_t i = 0; i < graph.n.size (); i++)
		{
			parent[i] = -1;
			visited[i] = false;
			ap[i] = false;
		}
	 
		for (size_t i = 0; i < graph.n.size (); i++)
			if (visited[i] == false)
				help (graph, i, visited, disc, low, parent, ap);
	 
		for (size_t i = 0; i < graph.n.size (); i++)
			if (ap[i] == true)
				ans.push_back (i);
		return move (ans);
	}
};

