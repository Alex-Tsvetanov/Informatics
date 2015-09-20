//Not Ready
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

struct point
{
	int x, y;

	point () : x (0), y (0)
	{}
	point (int a, int b)
	{
		x = a;
		y = b;
	}
};

point operator * (point a, int k)
{
	return point (a.x * k, a.y * k);
}

point operator + (point a, point k)
{
	return point (a.x + k.x, a.y + k.y);
}

bool operator < (point a, point b)
{
	if (a.y == b.y)
		return (a.x < b.x);
	return (a.y < b.y);
}

set < point > points;

void addAllPoints (point down_left, int L)
{
	//cout << "(" << down_left.x << ", " << down_left.y << ") " << L << endl;
	point up_left = point (0, 1), up_right = point (1, 1), down_right = point (1, 0);
	up_left = up_left * L + down_left;
	down_right = down_right * L + down_left;
	up_right = up_right * L + down_left;
	
	//cout << "(" << down_right.x << ", " << down_right.y << ")" << endl;
	//cout << "(" << up_left.x << ", " << up_left.y << ")" << endl;
	//cout << "(" << up_right.x << ", " << up_right.y << ")" << endl;

	points.insert (down_left);
	points.insert (down_right);
	points.insert (up_right);
	points.insert (up_left);
}

bool findAllPoints (point down_left, int L)
{
	point up_left = point (0, 1), up_right = point (1, 1), down_right = point (1, 0);
	up_left = up_left * L + down_left;
	down_right = down_right * L + down_left;
	up_right = up_right * L + down_left;

	bool ans = points.find (down_left) != points.end () and 
	points.find (up_right) != points.end () and 
	points.find (down_right) != points.end () and 
	points.find (up_left) != points.end (); 
	if (ans)
		cout << "(" << down_left.x << ", " << down_left.y << ") " << L << " ==== " << ans << "\n";
	return ans;
}

int main ()
{
	int n;
	cin >> n;

	for (int i = 0 ; i < n ; i ++)
	{
		int x, y, l;
		cin >> x >> y >> l;
		addAllPoints (point (x, y), l);
	}
	auto begIt = points.begin ();
	auto endIt = points.end ();
	endIt --;
	int maxL = max (
			(endIt->x) - (begIt->x), 
			(endIt->y) - (begIt->y)); 
	int ans = 0;
	for (auto& x : points)
	{
		cout << x.x << " " << x.y << "\n";
		for (int l = 1 ; l <= maxL ; l ++)
			ans += findAllPoints (x, l);
	}
	cout << ans << "\n";
}
