#include <fstream>
#include <vector>    // vector
#include <utility>   // pair
#include <set>       // set
#include <list>      // list
#include <stack>     // stack
#include <queue>     // queue
#include <algorithm> // sort

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

		void make_non_changeable ()
		{
			for (size_t i = 0 ; i < Size ; i ++)
				sort (n [i].begin (), n [i].end ());
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
				for (auto& x : n [s [s.size () - 1]])
				{
					s.push_back (x);
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
		vertexType Find_root (vertexType i, vertexType* parent) const
		{
			if (parent [i] == i)
			{
				return i;
			}
			else
			{
				vertexType k = parent [i];
				parent [i] = (Find_root (k, parent));
				return parent [i];
			}
		}
		inline void Union (vertexType i, vertexType j, vertexType* parent) const
		{
			vertexType a, b;
			parent [a = Find_root (i, parent)] = (b = Find_root (j, parent));
		}
	public:
		static inline void printMST (vertexType a, vertexType b, W c)
		{
//			cout << "Edge " << a << " " << b << " -> " << c << "\n";
		}
	public:
		W MST()
		{
			W MSTcost = 0;
			Size = n.size ();
			vector <vertexType> parent;
			parent.reserve (Size);

			for (size_t i = 0 ; i < Size ; i ++)
				parent [i] = i;
	//-------------------------INIT-----------------------------------------------		
			vector < pair < W, pair < vertexType, vertexType > > > edges;
			for (vertexType i = 0 ; i < Size ; i ++)
				for (auto& x : n [i])
					edges.push_back ({f (i, x), {i, x}});
			sort (edges.begin (), edges.end ());
			size_t number_of_connections = 0;
			for (size_t i = 0 ; number_of_connections < Size - 1 and i < edges.size () ; i ++)
			{
				auto edge = edges [i];
				vertexType first = Find_root (edge.second.first, parent.data ());
				vertexType second = Find_root (edge.second.second, parent.data ());
				if (first != second)
				{
					MSTcost += edge.first;
					Union (edge.second.first, edge.second.second, parent.data ());
					number_of_connections ++;
				}
				else
					continue;
			}
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

int dist2 (pair < int, int > a, pair <int, int> b)
{
	return (a.first - b.first) * (a.second - b.second) * (a.first - b.first) * (a.second - b.second);
}

char intersection(float p0_x, float p0_y, float p1_x, float p1_y, 
		float p2_x, float p2_y, float p3_x, float p3_y, float *i_x, float *i_y)
{
	float s1_x, s1_y, s2_x, s2_y, sn, tn, sd, td, t;
	s1_x = p1_x - p0_x;     s1_y = p1_y - p0_y;
	s2_x = p3_x - p2_x;     s2_y = p3_y - p2_y;

	sn = -s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y);
	sd = -s2_x * s1_y + s1_x * s2_y;
	tn =  s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x);
	td = -s2_x * s1_y + s1_x * s2_y;

	if (sn >= 0 && sn <= sd && tn >= 0 && tn <= td)
	{
		// Collision detected
		t = tn / td;
		if (i_x != NULL)
			*i_x = p0_x + (tn * s1_x);
		if (i_y != NULL)
			*i_y = p0_y + (tn * s1_y);
		return 1;
	}

	return 0; // No collision
}

int main () 
{
	ifstream cin ("electricity.in");
	ofstream cout ("electricity.out");
	int n, m;
	cin >> n >> m;

	vector < pair < int, pair <int, int> > > coords;
	for (int i = 0 ; i < n ; i ++)
	{
		int a, b;
		cin >> a >> b;
		coords.push_back ({i, {a, b}});
	}
	vector < pair <int, int > > input;
	for (int i = 0 ; i < m ; i ++)
	{
		int a, b;
		cin >> a >> b;
		a --;
		b --;
		input.push_back ({a, b});
	}

	int mstMinCost = 1e9;
	vector < pair < int, pair < int, int > > > ans;

	do
	{
		int cost = 0;
		for (int i = 0 ; i < m ; i ++)
		{
			cost += dist2 (coords [input [i].first].second, coords [input [i].second].second);
			for (int j = i + 1 ; j < m ; j ++)
				if (intersect (
		}

		if (cost <= mstMinCost)
			ans = coords;
	} while (next_permutation (coords.begin (), coords.end ()));

	cout << ans.size () << "\n";
	for (int i = 0 ; i < n ; i ++)
		cout << i + 1 << " " << ans [i].second.first << " " << ans [i].second.second << " " << ans [i].first + 1 << "\n";
}