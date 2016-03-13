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
};

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#include <stdio.h>
#include <exception>
#include <sstream>

G <int> graph;
bool* visited = nullptr; vector <int> path = vector <int> ();
set < string > output;
bool no_result = true;
void DFS (unsigned long long s = 0ull, unsigned long long level = 0ull)
{
	if (level == 3)
	{
		no_result = false;
		stringstream ss;
		ss << "{";
		for (int i = 0 ; i < (int)path.size () - 1 ; i ++)
			ss << path [i] << " -> ";
		ss << path [path.size () - 1] << "}" << endl;
		output.insert (ss.str ());
		return ;
	}
	for (auto& x : graph.n [s])
	{
		if (!visited [x])
		{
			visited [x] = true;
			path.push_back (x);
			DFS (x, level + 1);
			path.pop_back ();
			visited [x] = false;
		}
	}
}

std::vector <string> Split (std::string line, std::string sep = " \t\n")
{
	    std::string str = line;
		std::string curr;
	    vector < string > ans;
	    for (size_t i = 0 ; i < str.size () ; i ++)
		if (sep.find (str [i]) != string::npos)
		{
		    if (curr != "")
		    {
				    ans.push_back (string (curr)); curr = "";
			    }
		}
		else
		    curr += str [i];
	    if (curr.size () > 0)
		ans.push_back (curr);
	    return ans;
}

std::logic_error NotImplementedException ()
{
    return std::logic_error ("Function not yet implemented.");
}

char ConsoleReadKey ()
{
    try
    {
		throw NotImplementedException ();
		return cin.get ();
    }
    catch (std::exception& e)
    {
		throw e;
    }
}
char ConsoleRead ()
{
    try
    {
	char out;
	cin >> out;
	return out;
    }
    catch (std::exception& e)
    {
	throw e;
    }
}
string ConsoleReadLine ()
{
    try
    {
	string out;
	getline (cin, out);
	return out;
    }
    catch (std::exception& e)
    {
	throw e;
    }
}

int main ()
{
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		string line = ConsoleReadLine ();
		if (line == "")
		    line = ConsoleReadLine ();
		vector <string> splitted = vector <string> (Split (line, " ->"));
		int from = atoi (splitted [0].c_str ());
		for (int i = 1 ; i < (int)splitted.size () ; i ++)
		{
			int to = atoi (splitted [i].c_str ());
			graph.addEdge (from, to, 0);
		}
	}
	visited = new bool [n];
	for (int i = 0 ; i < n ; i ++)
		DFS (i);
	if (no_result)
		cout << "No cycles found\n";
	else
	    for (auto& x : output)
		cout << x;
	delete[] visited;
}
