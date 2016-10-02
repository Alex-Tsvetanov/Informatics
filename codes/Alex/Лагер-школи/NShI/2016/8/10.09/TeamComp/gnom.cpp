#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> ln [200005];
int level1      [200005];
int level2      [200005];
int n;
/*
void bfs1 (int s)
{
	vector <bool> used;
	used.resize (n, false);
	queue <pair <int, int> > bfs2;
	bfs2.push (s);
	used [s] = 1;
	while (not bfs2.empty ())
	{
		int front = bfs2.front ().first;
		level1 [front] = bfs2.front ().second; bfs2.pop ();
		for (auto& x : ln [front])
			if (not used [x])
			{
				bfs2.push ({x, level1 [front] + 1});
				used [x] = 1;
			}
	}
}

void bfs2 (int s)
{
	vector <bool> used;
	used.resize (n, false);
	queue <pair <int, int> > bfs;
	bfs2.push (s);
	used [s] = 1;
	while (not bfs2.empty ())
	{
		int front = bfs.front ().first;
		level1 [front] = bfs.front ().second; bfs.pop ();
		for (auto& x : ln [front])
			if (not used [x])
			{
				bfs.push ({x, level1 [front] + 1});
				used [x] = 1;
			}
	}
}
*/
int main ()
{
	cin >> n;
	for (int i = 0 ; i < n - 1 ; i ++)
	{
		int a, b;
		cin >> a >> b;
		a --; b --;
		ln [a].push_back (b);
		ln [b].push_back (a);
	}
	int a, b;
	cin >> a >> b;
	a --; b --;
	
	{
		vector <bool> used;
		used.resize (n, false);
		queue <pair <int, int> > bfs1;
		queue <pair <int, int> > bfs2;
		bfs1.push ({a, 1});
		bfs2.push ({b, 1});
		used [a] = 1;
		used [b] = 1;
		while (not bfs1.empty () and not bfs2.empty ())
		{
			int front1 = bfs1.front ().first;
			int front2 = bfs2.front ().first;
			level1 [front1] = bfs1.front ().second;
			level2 [front2] = bfs2.front ().second;
			bfs1.pop (); bfs2.pop ();
			{
				for (auto& x : ln [front1])
					if (not used [x])
					{
						bfs1.push ({x, level1 [front1] + 1});
						used [x] = 1;
					}
			}
			if (front1 != front2)
			{
				for (auto& x : ln [front2])
					if (not used [x])
					{
						bfs2.push ({x, level2 [front2] + 1});
						used [x] = 1;
					}
			}
		}
	}
	int ans1 = min (*max_element (level1, level1 + n), *max_element (level2, level2 + n));
	{
		vector <bool> used;
		used.resize (n, false);
		queue <pair <int, int> > bfs1;
		queue <pair <int, int> > bfs2;
		bfs1.push ({a, 1});
		bfs2.push ({b, 1});
		used [a] = 1;
		used [b] = 1;
		while (not bfs1.empty () and not bfs2.empty ())
		{
			int front1 = bfs1.front ().first;
			int front2 = bfs2.front ().first;
			level1 [front1] = bfs1.front ().second;
			level2 [front2] = bfs2.front ().second;
			bfs1.pop (); bfs2.pop ();
			if (front1 != front2)
			{
				for (auto& x : ln [front1])
					if (not used [x])
					{
						bfs1.push ({x, level1 [front1] + 1});
						used [x] = 1;
					}
			}
			{
				for (auto& x : ln [front2])
					if (not used [x])
					{
						bfs2.push ({x, level2 [front2] + 1});
						used [x] = 1;
					}
			}
		}
	}
	int ans2 = min (*max_element (level1, level1 + n), *max_element (level2, level2 + n));
	cout << max (ans1, ans2) << "\n";
}
