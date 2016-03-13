#include <vector>  // vector
#include <utility> // pair
#include <set>     // set
#include <list>    // list
#include <queue>   // queue
#include <stack>   // stack

using namespace std;

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
	void add2Edges (size_t a, size_t b, W c = W ())
	{
		addEdge (a, b, c);
		addEdge (b, a, c);
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
		this->size = n.size ();
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
	void MST(void func(unsigned long long, unsigned long long))const //O (n + m.log2(n)) = speed + inicializacion
	{                                                                //O (m.log2(n)) = speed of algorithm
		//unsigned long long steps = 0;
		unsigned long long colornum [size];
		unsigned long long* color [size];
		list < pair <unsigned long long*, vector < unsigned long long > > > diffColor;
		list < pair <unsigned long long*, vector < unsigned long long > > >::iterator itColor [size];
		list<pair<unsigned long long*,vector < unsigned long long > > >::iterator curr;
		for (unsigned long long i = 0 ; i < size ; i ++)
		{
			colornum [i] = i;
			color [i] = colornum + i;
			diffColor.push_back (pair <unsigned long long*, vector <unsigned long long> > (color [i], {i}));
			if (i == 0) curr = diffColor.begin ();
			else        curr ++;
			itColor [i] = curr;
			//steps ++;
		}
		while (diffColor.size () > 1)
		{
			//bool Break = true;
			//while (Break == true and diffColor.size () > 2)
			//{
				//Break = false;
				for (list < pair <unsigned long long*, vector < unsigned long long > > >::iterator it = diffColor.begin () ; it != diffColor.end () ; it ++)
				{
					const unsigned long long Size = it -> second.size ();
					for (unsigned long long i = 0 ; i < Size ; i ++)
					{
						unsigned long long v, Min, b = 0;
						cout << "Choose between: " << endl;
						for (unsigned long long j = 0 ; j < n [it -> second [i]].size () ; j ++)
						{
							//steps ++;
							if (*color [it->second [i]] != *color [n [it -> second [i]][j]])
							{
								cout << "(" << it->second [i] << ", " << n [it->second [i]][j] << ")" << endl;
								if (b == 0)
								{
									v = n [it->second[i]][j];
									Min = f (it->second [i], n [it -> second [i]][j]);
									b = 1;
								}
								else
								{
									unsigned long long h = f (it->second [i], n [it -> second [i]][j]);
									if (Min > h)
									{
										Min = h;
										v = n [it->second[i]][j];
									}
								}
							}
						}
						if (b and *color [v] != *color [it->second [i]])
						{
							func (it->second [i], v);
							for (unsigned long long j = 0 ; j < itColor [*color [v]]->second.size () ; j ++)
							{
								//steps++;
								it->second.push_back (itColor [*color [v]]->second [j]);
							}
							diffColor.erase (itColor [*color [v]]);
							itColor [*color [v]] = itColor [*color [it->second [i]]];
							color [v] = color [it->second [i]];
							//Break = 1;
							break;
						}
					}
				}
			//}
		}
		//cout << "Steps: " << steps << "\nM: " << e.size () << "\nN: " << n.size () << "\n";				
	}
private:
	struct fun2
	{
		bool operator () (pair < W *, unsigned long long >i, pair < W *, unsigned long long >j)
		{
			return *(i.first) > *(j.first);
		}
	};
public:
	void dijikstra(void func (unsigned long long, W), unsigned long long s = 0ll) const
	{
		set < pair < W *, unsigned long long >, fun2 > T_;
		W* d = new W [size];
		for (unsigned long long i = 0; i < size; i++)
			d[i] = f (s, i);
		for (unsigned long long i = 0; i < size; i++)
			if (i != s)
				T_.insert (make_pair (&d[i], i));
		while (T_.size () > 0 and * T_.begin ()->first != -1)
		{
			unsigned long long j = T_.begin ()->second;
			if (n [j].size() > 0)
			{
				T_.erase (T_.begin());
				for (typename set < pair < W *, unsigned long long >, fun2 >::iterator it = T_.begin (); it != T_.end (); it++)
				{
					unsigned long long i = it->second;
					if (edge (j, i))
						d [i] = (d [i] < (d [j] + f (j, i))) ? d [i] : (d [j] + f (j, i));
				}
			}
		}
		for (unsigned long long i = 0; i < size; i++)
			if (i != s)
				cout << i << " " << d [i] << "\n";
			else
				cout << s << " " << 0 << "\n";
	}
	void dfs (void func (unsigned long long, unsigned long long), unsigned long long s = 0ull, unsigned long long level = 0ull) const
	{
		bool* visited = new bool [n.size ()];
		unsigned long long* levels = new unsigned long long [n.size ()];
		levels [s] = level;
		stack < pair < unsigned long long, unsigned long long > > st;
		st.push ({s, levels [s]});
		while (!st.empty ())
		{
			auto f = st.top (); st.pop ();
			levels [f.first] = f.second;
			for (auto& x : n [f.first])
				if (levels [x] == -1)
					st.push ({x, f.second + 1});
		}
		for (int i = 0 ; i < n.size () ; i ++)
			func (i, levels [i]);
		delete[] visited;
	}
	void bfs (void func (unsigned long long, unsigned long long), unsigned long long s = 0ull, unsigned long long level = 0ull, bool* visited = nullptr) const
	{
		if (visited == nullptr)
			visited = new bool [n.size ()];
		unsigned long long* levels = new unsigned long long [n.size ()];
		levels [s] = level;
		queue < pair < unsigned long long, unsigned long long > > q;
		q.push ({s, levels [s]});
		while (!q.empty ())
		{
			auto f = q.front (); q.pop ();
			levels [f.first] = f.second;
			for (auto& x : n [f.first])
				if (levels [x] == -1)
					q.push ({x, f.second + 1});
		}
		for (int i = 0 ; i < n.size () ; i ++)
			func (i, levels [i]);
		delete[] visited;
	}
};
