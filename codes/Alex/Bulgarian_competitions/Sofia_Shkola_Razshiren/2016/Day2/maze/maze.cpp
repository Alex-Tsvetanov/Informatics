#include <iostream>
#include <vector>
#include <queue>

using namespace std;

string table [1024];
vector <bool> visited [1024];
int x1, x2, y1, y2;

int bfs ()
{
	queue <pair <int, pair < char, pair <int, int> > > > q;
	q.push ({0, {'f', {x1, y1}}});
	while (!q.empty ())
	{
		auto front = q.front (); q.pop ();
		auto point = front.second.second;
		if (!(point.first >= 0 and point.second >= 0 and point.second < 1024 and point.first < (int)table [point.second].size ()))
			continue;
		if (visited [point.first][point.second])
			continue;
		visited [point.first][point.second] = 1;

		if (point.first == x2 and point.second == y2)
		{
			return front.first;
		}
		for (int i = -1 ; i <= 1 ; i ++)
			for (int j = -1 ; j <= 1 ; j ++)
			{
				if (i != j)
					if (front.second.first == 'f' or table [point.second + j][point.first + i * 2] + front.second.first == 'w' + 'b')
						q.push ({point.first + 1, {table [point.second + j][point.first + i * 2], {point.first + i, point.second + 2 * j}}});
			}
	}
	return 1e6;
}

int main ()
{
	int w, h;
	cin >> w >> h;
	cin >> x1 >> y1 >> x2 >> y2;
	y1 *= 2;
	y2 *= 2;
	for (int i = 0 ; i < 2 * h + 1 ; i ++)
	{
		cin >> table [i];
		visited [i].resize (table [i].size (), false);
	}
	cout << "OK...\n"; cout.flush ();
	cout << bfs () << "\n";
}
