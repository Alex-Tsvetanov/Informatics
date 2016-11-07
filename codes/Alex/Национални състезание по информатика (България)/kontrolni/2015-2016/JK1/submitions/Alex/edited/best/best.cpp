#include <map>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int n, m, v1, v2;
double p1, p2;

struct 
{
	map < string, int > names;

	void to_lowercase (string& a)
	{
		for (auto& x : a)
			if ('A' <= x and x <= 'Z')
				x = x - 'A' + 'a';
	}

	int get_id (const string& a)
	{
		const int size = names.size ();
		if (names.find (a) != names.end ())
			return names [a];
		return (names [a] = size);
	}

	void read (vector < int >* ln)
	{
		cin >> n >> m >> p1 >> v1 >> p2 >> v2;
		for (int i = 0 ; i < m ; i ++)
		{
			string a, b;
			cin >> a >> b;
			to_lowercase (a);
			to_lowercase (b);
			int id1 = get_id (a);
			int id2 = get_id (b);
			ln [id1].push_back (id2);
			ln [id2].push_back (id1);
		}
	}
} input_data;

struct
{
	vector < int > ln [1<<14];
	vector < int > components;

	int bfs (int s, vector <bool>& visited)
	{
		int answer = 0;
		queue < int > q;
		q.push (s);
		while (not q.empty ())
		{
			int front = q.front (); q.pop ();
			if (not visited [front])
			{
				answer ++;
				visited [front] = true;
				for (auto& x : ln [front])
					if (not visited [x])
						q.push (x);
			}
		}
		return answer;
	}

	void make_components ()
	{
		//cout << "Start components" << std::endl;
		vector <bool> visited (n, false);
		for (int i = 0 ; i < n ; i ++)
			if (not visited [i])
				components.push_back (bfs (i, visited));
		//cout << "End components" << std::endl;
	}

	vector <bool> knapsack ()
	{
		//I have baggages with volumes equal to elements of __components__
		//   and knapsack with volume __v1__
		vector <bool> possible (v1 + 1, false);
		possible [0] = true;
		for (auto& baggage : components)
		{
			for (int i = v1 ; i >= 0 ; i --)
				if (possible [i] and i + baggage <= v1)
					possible [i + baggage] = true;
		}
		return move (possible);
	}

	void solve ()
	{
		make_components ();
		//cout << "Made components" << std::endl;
		vector <bool> possible = knapsack ();
		//cout << "Made possible" << std::endl;
		const double inf = 1234567890.00;
		double ans = inf;
		for (int i = 0 ; i <= v1 ; i ++)
			if (possible [i] and i <= v1 and n - i <= v2)
				ans = min (ans, i * p1 + (n - i) * p2);
		//cout << "Made possible" << std::endl;
		if (ans == inf) cout << "Impossible\n";
		else printf ("%.2lf\n", ans);
	}
} calculate;

int main (int agrv, char** args)
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	input_data.read (calculate.ln);
	//cout << n << " " << m << "\n" << v1 << " " << v2 << "\n" << p1 << " " << p2 << "\n";
	calculate.solve ();
}
