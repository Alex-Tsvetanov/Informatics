#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <int> ln [500];

int visited [500];

void bfs (int s, int component_num)
{
	queue <int> q;
	q.push (s);
	while (!q.empty ())
	{
		int f = q.front (); q.pop ();
		visited [f] = component_num;
		for (int i = 0 ; i < ln [f].size () ; i ++)
		{
			if (visited [ln [f][i]] == 0)
				q.push (ln [f][i]);
		}
	}
}

int main ()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0 ; i < m ; i ++)
	{
		int a, b;
		cin >> a >> b;
		a --;
		b --;
		ln [a].push_back (b);
		ln [b].push_back (a);
	}
	int component_num = 1;
	for (int i = 0 ; i < n ; i ++)
		if (visited [i] == 0)
			bfs (i, component_num ++);
	cout << component_num - 1 << endl;
}
