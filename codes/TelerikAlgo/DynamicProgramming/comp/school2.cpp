using namespace std;
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>



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
		static const W NOT_CREATED = (1<<30);
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
		W dijikstra(vertexType e = 0ll,
				vertexType s = 0ll) const
		{
			set < pair < W *, vertexType >, fun2 > T_;
			W* d = new W [Size];
			for (vertexType i = 0; i < Size; i++)
				d[i] = f (s, i);
			d [s] = 0;
			for (vertexType i = 0; i < Size; i++)
				if (edge (s, i))
					T_.insert (make_pair (&d[i], i));
			while (T_.size () > 0)
			{
				vertexType j = T_.begin ()->second;

				T_.erase (T_.begin());
				for (typename set < pair < W *, vertexType >, fun2 >::iterator it = T_.begin (); it != T_.end (); it ++)
				{
					vertexType i = it->second;
					if (edge (j, i))
						if (d [i] == NOT_CREATED or d [i] > (d [j] + f (j, i)))
						{
							d [i] = (d [j] + f (j, i));
							it = T_.erase (it);
							it --;
							T_.insert ({&(d [i]), i});
						}
				}
			}
			int a = d [e];
			delete[] d;
			return a;
		}
	};

#include <iostream>

int main ()
{
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	x --;
	y --;
	G < int > graph;
	for (int i = 0 ; i < m ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a --;
		b --;
		graph.add2Edges (a, b, -c);
	}
	graph.make_non_changeable ();
	cout << -graph.dijikstra (y, x) << endl;
}
