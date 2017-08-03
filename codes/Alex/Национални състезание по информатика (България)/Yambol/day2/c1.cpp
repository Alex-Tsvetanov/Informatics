#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct point : pair < double, double >
{
	point (double x, double y) : pair <double, double> (x, y)
	{}

	double x () const
	{
		return this->first;
	}
	double y () const
	{
		return this->second;
	}
};

vector < point > v [100];

int main ()
{
	int n;
	double r;
	cin >> n >> r;
	for (int i = 0 ; i < n ; i ++)
	{
		double a;
		cin >> a;
		v [0].push_back (point (a, 1));
	}
	sort (v [0].begin (), v [0].end ());
	for (int _ = 0 ; _ < n - 1 ; _ ++)
	{
		for (int i = 1 ; i < v [_].size () ; i ++)
		{
			v [_ + 1].push_back (point ((v [_][i].x () + v [_][i - 1].x ()) / 2, v [_][i].y () + sqrt (4 * r * r - (v [_][i].x() - v[_][i - 1].x())*(v [_][i].x() - v[_][i - 1].x()) / 4)));
		}
	}
	printf ("%.4f %.4f\n", v [n - 1][0].x (), v [n - 1][0].y () + r);
}
