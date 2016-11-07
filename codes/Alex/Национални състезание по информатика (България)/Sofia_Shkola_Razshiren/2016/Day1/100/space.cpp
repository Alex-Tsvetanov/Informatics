#include <iostream>
#include <cmath>
#define int int64_t
using namespace std;

int check (int a, int b, int d, int w, int h)
{
	int v1 = (w / (a + 2 * d)) * (h / (b + 2 * d));
	int v2 = (w / (b + 2 * d)) * (h / (a + 2 * d));
	return max (v1, v2);
}

int32_t main ()
{
	int n, a, b, w, h;
	cin >> n >> a >> b >> w >> h;
	int up = 1e18, down = 0;
	while (up - down > 1)
	{
		int mid = (up + down) / 2;
		if (check (a, b, mid, w, h) >= n)
			down = mid;
		else
			up = mid;
	}
	cout << down << "\n";
}
