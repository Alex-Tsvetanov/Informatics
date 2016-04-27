#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct point
{
	int x; int y;
	point (int a = 0, int b = 0) : x (a), y (b)
	{

	}
};

uint64_t dist2 (point a)
{
	return a.x * a.x + a.y * a.y;
}

bool comp (point a, point b)
{
	return dist2 (a) > dist2 (b);
}

ifstream fin ("ring.in");
ofstream fout ("ring.out");

int main ()
{
	int n, k;
	fin >> n >> k;
	vector < point > points;
	for (int i = 0 ; i < n ; i ++)
	{
		int x, y;
		fin >> x >> y;
		points.push_back (point (x, y));
		//cout << x << " " << y << "\n";
	}
	sort (points.begin (), points.end (), comp);
	uint64_t min_ans = 2000000000000ull;
////for (int i = 0 ; i < n ; i ++)
////	cout << points [i].x << " " << points [i].y << "\n";
	for (int i = 0 ; i <= n - k ; i ++)
	{
		uint64_t max_rad = ceil (sqrt (dist2 (points [i])));
		uint64_t min_rad = sqrt (dist2 (points [i + k - 1]));
		if (min_rad * min_rad == dist2 (points [i + k - 1]))
			min_rad --;
		if (i + k < n)
		{
			uint64_t min_rad2 = sqrt (dist2 (points [i + k]));
			//cout << min_ans << " \t " << min_rad << " < " << min_rad2 << " <= " << max_rad << "\n";
			if (min_rad < min_rad2 and min_rad2 <= max_rad)
			{
				//cout << "\tTrue\n";
				continue;
			}
			else 
				min_ans = min (min_ans, max_rad * max_rad - min_rad * min_rad);
		}
		else if (i - 1 > -1)
		{
			uint64_t min_rad2 = sqrt (dist2 (points [i - 1]));
			//cout << min_ans << " \t " << min_rad << " < " << min_rad2 << " <= " << max_rad << "\n";
			if (min_rad < min_rad2 and min_rad2 <= max_rad)
			{
				//cout << "\tTrue\n";
				continue;
			}
			else 
				min_ans = min (min_ans, max_rad * max_rad - min_rad * min_rad);
		}
		else 
			min_ans = min (min_ans, max_rad * max_rad - min_rad * min_rad);
	}
	fout << min_ans << "\n";
}
