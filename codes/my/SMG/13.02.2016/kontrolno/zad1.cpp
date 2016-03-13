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

bool is_in_triangle (int a, int b, int c, int k)
{
	return
		orientation (points [a], points [k], points [b]) == orientation (points [a], points [c], points [b]) and
		orientation (points [a], points [c], points [k]) == orientation (points [a], points [c], points [b]) and
		orientation (points [k], points [c], points [b]) == orientation (points [a], points [c], points [b]);
}

int main ()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0 ; i < n ; i ++)
	{
		int x, y;
		cin >> x >> y;
		points.push_back (point (x, y));
	}
	vector < uint64_t > ans;
	for (int i = 0 ; i < n ; i ++)
		for (int j = i + 1 ; j < n ; j ++)
			for (int k = j + 1 ; k < n ; k ++)
			{
				uint64_t in_triangle = 0;
				for (int l = 0 ; l < n ; l ++)
				{
					in_triangle += is_in_triangle (i, j, k, l);
				}
				ans.push_back (in_triangle);
			}
	sort (ans.begin (), ans.end ());
	uint64_t sum = 0;
	for (int i = n - k ; i < n ; i ++)
		sum += ans [i];
	cout << sum << "\n";
}
