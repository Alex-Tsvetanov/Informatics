#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <cmath>

using namespace std;

typedef double coord_t;
typedef double coord2_t;

struct Point
{
    coord_t x, y;

    Point(coord_t x = 0, coord_t y = 0)
    {
	this->x = x;
	this->y = y;
    }

    static double CrossProduct(const Point &a, const Point &b)
    {
	return a.x * b.y - a.y * b.x;
    }

    Point operator + (const Point &other) const
    {
	return Point(this->x + other.x, this->y + other.y);
    }

    Point operator - (const Point &other) const
    {
	return Point(this->x - other.x, this->y - other.y);
    }

    bool operator <(const Point &p) const
    {
	return x < p.x or (x == p.x and y < p.y);
    }
    bool operator >(const Point &p) const
    {
	return x > p.x or (x == p.x and y > p.y);
    }
    bool operator !=(const Point &p) const
    {
	return x != p.x or y != p.y;
    }
    bool operator ==(const Point &p) const
    {
	return x == p.x or y == p.y;
    }
};

typedef vector <Point> polygon;

coord2_t cross (const Point &O, const Point &A, const Point &B)
{
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

pair <bool, Point> get_line_intersection(Point p0, Point p1,
	Point p2, Point p3)
{
    float p0_x = p0.x, p0_y = p0.y;
    float p1_x = p1.x, p1_y = p1.y;
    float p2_x = p2.x, p2_y = p2.y;
    float p3_x = p3.x, p3_y = p3.y;

    pair <bool, Point> ans;

    float s1_x, s1_y, s2_x, s2_y;
    s1_x = p1_x - p0_x;     s1_y = p1_y - p0_y;
    s2_x = p3_x - p2_x;     s2_y = p3_y - p2_y;

    float s, t;
    s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / (-s2_x * s1_y + s1_x * s2_y);
    t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / (-s2_x * s1_y + s1_x * s2_y);

    if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
    {
	ans.first = true;
	ans.second = Point (p0_x + (t * s1_x), p0_y + (t * s1_y));
	return ans;
    }
    ans.first = false;
    ans.second = Point (-1, -1);

    return ans;
}

vector <Point> convex_hull (vector <Point> P)
{
    int n = P.size (), k = 0;
    vector <Point> H (2 * n);

    sort (P.begin (), P.end ());

    for (int i = 0 ; i < n ; ++ i)
    {
	while (k >= 2 and cross (H [k - 2], H [k - 1], P [i]) <= 0)
	    k --;
	H [k ++] = P [i];
    }

    for (int i = n - 2, t = k + 1 ; i >= 0 ; i --)
    {
	while (k >= t and cross (H [k - 2], H [k - 1], P [i]) <= 0)
	    k --;
	H [k ++] = P [i];
    }

    H.resize (k - 1);
    return H;
}

void PrintVector2Container (vector <Point> c)
{
    for(int i = 0 ; i < c.size () ; i ++)
    {
	cout << c [i].x << " " << c [i].y << endl;
    }
}

double CalculateSurface (vector <Point> polyPoints)
{
    Point basePoint = polyPoints [0];

    double surface = 0.0;

    for(int i = 1 ; i < polyPoints.size () - 1 ; i ++)
    {

	Point baseToFirst = polyPoints [i] - basePoint;
	Point baseToSecond = polyPoints [i + 1] - basePoint;

	surface += Point::CrossProduct (baseToFirst, baseToSecond);
    }


    return fabs (surface) / 2;
}

int main ()
{
    //    auto cross_point = get_line_intersection (
    //                                              Point (1 , 3),
    //                                              Point (3 , 3),
    //                                              Point (2 , 2),
    //                                              Point (2 , 4)
    //                                             );
    //    cout << cross_point.first << " " << cross_point.second.x << " " << cross_point.second.y << "\n";
    //    return 0;
    int n;
    cin >> n;

    vector <polygon> poly (n);
    polygon for_surface;
    set <Point> for_surface2;

    for(int i = 0 ; i < n ; i ++)
    {
	double x1, y1;
	double x2, y2;
	double x3, y3;
	double x4, y4;
	cin >> x1 >> y1;
	cin >> x4 >> y4;
	x2 = x1; y2 = y4;
	x3 = x4; y3 = y1;
	poly [i].push_back (Point (x1, y1));
	for_surface2.insert (Point (x1, y1));
	poly [i].push_back (Point (x2, y2));
	for_surface2.insert (Point (x2, y2));
	poly [i].push_back (Point (x4, y4));
	for_surface2.insert (Point (x4, y4));
	poly [i].push_back (Point (x3, y3));
	for_surface2.insert (Point (x3, y3));
    }

    for(int poly1 = 0 ; poly1 < n ; poly1 ++)
    {
	for (int point1 = 0, next_point1 = 1 ; point1 < 4 ; point1 ++, next_point1 = (next_point1 + 1) % 4)
	{
	    for(int poly2 = poly1 + 1 ; poly2 < n ; poly2 ++)
	    {
		for (int point2 = 0, next_point2 = 1 ; point2 < 4 ; point2 ++, next_point2 = (next_point2 + 1) % 4)
		{
		    auto cross_point = get_line_intersection (
			    poly [poly1][point1],
			    poly [poly1][next_point1],
			    poly [poly2][point2],
			    poly [poly2][next_point2]
			    );
		    if (cross_point.first)
		    {
			for_surface2.insert (cross_point.second);
		    }
		}
	    }
	}
    }

    for (auto& x : for_surface2)
    {
	for_surface.push_back (x);
    }

    PrintVector2Container (for_surface);

    PrintVector2Container (convex_hull (for_surface));

    cout << CalculateSurface (convex_hull (for_surface)) << endl;
}
