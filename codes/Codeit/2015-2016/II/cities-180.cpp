#include <fstream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector < int > ln [1<<14];
bool visited [1<<14];

int bfs (int a, int b)
{
	queue < pair < int, int > > q;
	q.push ({a, 1});
	while (!q.empty ())
	{
		auto f = q.front (); q.pop ();
		visited [f.first] = true;
		if (f.first == b)
			return f.second;
		for (auto& x : ln [f.first])
			if (!visited [x])
				q.push ({x, f.second + 1});
	}
	return -1;
}

int main ()
{
	ifstream fin ("cities.in");
	ofstream fout ("cities.out");
	int n, m;
	int A, B;
	fin >> n >> m >> A >> B;
	A --;
	B --;
	for (int i = 0 ; i < m ; i ++)
	{
		int a, b;
		fin >> a >> b;
		a --; b --;
		ln [a].push_back (b);
		ln [b].push_back (a);
	}
	fout << bfs (A, B) << "\n";
}
