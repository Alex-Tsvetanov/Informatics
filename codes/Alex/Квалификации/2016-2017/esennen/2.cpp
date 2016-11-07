#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct project 
{
	int a, b, c;
	project (int _a, int _b, int _c)
	{
		a = _a;
		b = _b;
		c = _c;
	}
};

const double eps = 1e-4;

bool operator < (project a, project b)
{
	if (a.a == b.a)
	{
		double x1 = (((double)(a.c))/(a.b - a.a));
		double x2 = (((double)(b.c))/(b.b - b.a));
		if (fabs (x1 - x2) < eps)
			return a.b < b.b;
		else
			return x1 > x2;
	}
	else 
		return a.a < b.a;
}

vector <project> projects;

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a > b)
			swap (a, b);

		projects.push_back (project (a, b, c));
	}

	sort (projects.begin (), projects.end ());
	
////for (int i = 0 ; i < n ; i ++)
////	cout 
////		<< projects [i].a << " "
////		<< projects [i].b << " "
////		<< projects [i].c << "\n";

	int end = 0;
	int ans = 0;
	for (int i = 0 ; i < projects.size () ; i ++)
	{
		if (projects [i].a < end)
			continue;

		ans += projects [i].c;
		end = projects [i].b;
	}

	cout << ans << "\n";
}
