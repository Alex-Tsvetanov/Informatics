#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <set>
#include <map>

using namespace std;

using cost_t = int64_t;
using number_t = size_t;
using vertex_t = size_t;

		number_t N;
		cost_t U, D;
		cost_t Input, Output;
		vector < vector < vertex_t > > lifts;
		number_t L;

void input ()
{
	cin >> N >> U >> D >> Input >> Output >> L;
	lifts.resize (L);
	for (number_t i = 0 ; i < L ; i ++)
	{
		number_t n;
		cin >> n;
		for (number_t j = 0 ; j < n ; j ++)
		{
			vertex_t x;
			cin >> x;
			lifts [i].push_back (x);
		}
	}
}

vector < vector < pair < vertex_t, cost_t > > > ln;
map <vertex_t, vertex_t> code;

void create_graph ()
{
	set <int> s;
	ln.resize (N + 1);
	/* // up_down { for (number_t i = 1 ; i < N ; i ++) { ln [i].push_back ({i + 1, U}); ln [i + 1].push_back ({i, D}); } }*/
	//lift
	{
		for (number_t i = 0 ; i < L ; i ++)
			for (number_t j = 0 ; j < lifts [i].size () ; j ++)
			{
				s.insert (lifts [i][j]);
				for (number_t k = j + 1 ; k < lifts [i].size () ; k ++)
				{
					ln [lifts[i][j]].push_back ({lifts[i][k], Input+Output});
					ln [lifts[i][k]].push_back ({lifts[i][j], Input+Output});
				}
			}
	}
	
}

cost_t dijkstra (vertex_t s, vertex_t e)
{
	vector <bool> visited (N + 1, false);
	priority_queue < pair < cost_t, vertex_t > > q;
	q.push ({0, s});
	while (!q.empty ())
	{
		auto front = q.top (); q.pop ();
		//cout << front.second << " -> " << front.first << "\n";
		visited [front.second] = true;
		if (front.second == e)
			return -front.first;
		for (auto& x : ln [front.second])
		{
			if (visited [x.first])
				continue;
			q.push ({front.first - x.second, x.first});
		}
    	if (front.second != N and !visited [front.second + 1])
    		q.push ({front.first - U, front.second + 1});
    	if (front.second != 0 and !visited [front.second - 1])
    		q.push ({front.first - D, front.second - 1});
	}
	return -1;
}

int main ()
{
	input ();
    cout << "input" << std::endl;
	create_graph ();/*
	for (number_t i = 0 ; i < ln.size () ; i ++)
	{
		cout << i << " -> \n";
		for (auto& x : ln [i])
		{
			cout << "\t{" << x.first << ", " << x.second << "}\n";
		}
	}*/
    cout << "create_graph" << std::endl;
	cout << dijkstra (1, N) << "\n";
    cout << "dijkstra" << std::endl;
}
