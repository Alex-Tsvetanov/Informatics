#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

const double eps = 1e-6;

struct point 
{
	double x, y;
};

struct line
{
	point s, e;
	double len () const
	{
		double x = e.x - s.x;
		double y = e.y - s.y;
		return sqrt (x * x + y * y);
	}
};

double orientationFace (double dX0, double dY0, double dX1, double dY1, double dX2, double dY2)
{
    double dorientationFace = (dX0 + dX1) * (dY0 - dY1) + (dX1 + dX2) * (dY1 - dY2) + (dX0 + dX2) * (dY2 - dY0);
    return dorientationFace;
}

double p_to_l (point a, line l)
{
	double f = fabs (orientationFace (a.x, a.y, l.s.x, l.s.y, l.e.x, l.e.y));
	f /= l.len ()*2;
	return f;
}

vector <point> poly;
double FACEPOLY = 0.0;
double facePoly ()
{
	double ans = 0.0;
	for (int i = 0 ; i < poly.size () ; i ++)
	{
		int a = i;
		int b = (i + 1) % poly.size ();
		int c = (i + 2) % poly.size ();
		ans += fabs (orientationFace (poly [a].x, poly [a].y, poly [b].x, poly [b].y, poly [c].x, poly [c].y));
	}
	return ans;
}

bool check (point p)
{
	double ans = 0;
	for (int i = 0 ; i < poly.size () ; i ++)
	{
		int a = i;
		int b = (i + 1) % poly.size ();
		int c = (i + 2) % poly.size ();
		ans += fabs (orientationFace (poly [a].x, poly [a].y, poly [b].x, poly [b].y, poly [c].x, poly [c].y));
	}
	return fabs (ans - FACEPOLY) <= eps;
}

int main ()
{
////cout << p_to_l ({5, 4},{{0,0},{10,0}}) << "\n"; 
    cin.tie (nullptr);
    ios::sync_with_stdio (false);
    int n, m;
    cin >> n >> m;
	for (int i = 0 ; i < n ; i ++)
	{
		double a, b;
		cin >> a >> b;
		poly.push_back ({a, b});
	}
	FACEPOLY = facePoly ();
	double total = 0;
	for (int i = 0 ; i < m ; i ++)
	{
		double a, b;
		cin >> a >> b;
		if (check ({a, b}))
		{
			double Min = 1e10;
			for (int i = 0 ; i < poly.size () ; i ++)
			{
				int a1 = i;
				int b1 = (i + 1) % poly.size ();
				Min = ((Min - p_to_l ({a, b}, {poly [a1], poly [b1]}) > eps)?p_to_l ({a,b},{poly [a1], poly[b1]}):Min);
			}
			total += Min;
		}
	}

    printf ("%f\n", total);
}
