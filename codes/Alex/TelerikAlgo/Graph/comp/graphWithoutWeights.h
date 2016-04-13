namespace Graph
{
	using namespace std;

	struct none
	{

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
}