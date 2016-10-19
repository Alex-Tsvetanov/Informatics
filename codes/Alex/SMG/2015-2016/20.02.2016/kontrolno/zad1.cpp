#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point
{
	int x, y;
	point (int _x, int _y) : x (_x), y (_y)
	{}
};

vector < point > points;

const int Clock = 1;
const int Counter_clock = 2;
const int on1line = 0;

int orientation (point p, point q, point r)
{
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

	if (val == 0) return on1line;  

	return (val > 0)? Clock : Counter_clock;
}

int face (point p, point q, point r)
{
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

	return (val);
}

int main ()
{
	int n, m;
	cin >> n;
	uint64_t ans = 0;
	for (int i = 0 ; i < n ; i ++)
	{
		points.clear ();
		cin >> m;
		point A (0, 0);
		for (int i = 0 ; i < m ; i ++)
		{
			int x, y;
			cin >> x >> y;
			if (i == 0)
				A = point (x, y);
			else
				points.push_back (point (x, y));
		}
		uint64_t subans_face = 0;
		for (int i = 0 ; i < points.size () - 1 ; i ++)
			subans_face += abs (face (A, points [i], points [i + 1]));
		ans += subans_face;
	}
	cout << ((double)((double)ans/(double)2)) << "\n";
}
