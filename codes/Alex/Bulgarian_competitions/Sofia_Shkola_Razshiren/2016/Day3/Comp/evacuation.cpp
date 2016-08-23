#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <string.h>

using namespace std;

int exits [100000];
int visited [100000];
vector <int> ln [100000];
int path [100000];

int bfs (int s)
{
	memset (visited, 0, sizeof (visited));
	queue <pair < int, int > > q;
	q.push ({s, 0});
	while (!q.empty ())
	{
		auto front = q.front (); q.pop ();
		path [front.first] = min (front.second, path [front.first]);
		visited [front.first] = 1;
		for (auto& x : ln [front.first])
		{
			if (!visited [x])
				q.push ({x, front.second + 1});
		}
	}
	return -1;
}

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	int n, k;
	cin >> n >> k;
	vector <int> bla;
	for (int i = 0 ; i < k ; i ++)
	{
		int a;
		cin >> a;
		a --;
		exits [a] = 1;
		bla.push_back (a);
	}
	int m;
	cin >> m;
	for (int i = 0 ; i < m ; i ++)
	{
		int a, b;
		cin >> a >> b;
		a --;
		b --;
		ln [a].push_back (b);
		ln [b].push_back (a);
	}
	memset (path, 1e6, sizeof (path));
	for (auto& x : bla)
	{
		bfs (x);
	}
	for (int i = 0 ; i < n ; i ++)
	{
		cout << path [i] << " ";
	}
	cout << "\n";
}
