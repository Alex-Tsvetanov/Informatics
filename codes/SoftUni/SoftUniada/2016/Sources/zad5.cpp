#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

struct Point
{
	double x, y;
	Point (double a, double b) : x (a), y (b)
	{}
	Point () : x (0), y (0)
	{}
};

bool operator < (Point a, Point b)
{
	return ((a.x == b.x)?(a.y < b.y):(a.x < b.x));
}

struct rect
{
	Point Top, Bottom;
	Point A, B, C, D;
	void calc ()
	{
		A = Top;
		B = Point (Bottom.x, Top.y);
		C = Point (Top.x, Bottom.y);
		D = Bottom;
	}
	double area ()
	{
		return abs ((Bottom.x - Top.x) * (Bottom.y - Top.y));
	}
};


struct circle
{
	Point O;
	double R;
};


double dist2 (Point a, Point b)
{
	return (b.x - a.x)*(b.x - a.x) + (b.y-a.y)*(b.y-a.y);
}

double areaOfTriangle (Point A, Point B, Point C)
{
	double a = sqrt (dist2 (C, B)); 
	double b = sqrt (dist2 (C, A)); 
	double c = sqrt (dist2 (A, B)); 
	double s = (a + b + c) / 2;

	return sqrt (s * (s - a) * (s - b) * (s - c));
}

bool PointIsinRect (Point a, rect r)
{
	r.calc ();
	Point A = r.A;
	Point B = r.B;
	Point C = r.C;
	Point D = r.D;
	return !(areaOfTriangle (A,a,D) + areaOfTriangle (D,a,C) + areaOfTriangle (C,a,B) + areaOfTriangle (a,B,A) > r.area ());
}

int main ()
{
	int n;
	cin >> n;
	string v;
	getline (cin, v);
	for (int i = 0 ; i < n ; i ++)
	{
		string A, B;
		getline (cin, A);
		getline (cin, B);
		rect R;
		circle C;
		if (A.find ("rectangle(") != string::npos and B.find ("circle(") != string::npos)
		{
			{
				stringstream ss;
				A.erase (0, 10);
				A.erase (A.size () - 1, 1);
				ss << A;
				char t;
				ss >> R.Top.x >> t >> R.Top.y >> t >> R.Bottom.x >> t >> R.Bottom.y;
			}
			{
				stringstream ss;
				B.erase (0, 7);
				B.erase (B.size () - 1, 1);
				ss << B;
				char t;
				ss >> C.O.x >> t >> C.O.y >> t >> C.R;
			}
		}
		else
		{
			swap (A, B);
			
			{
				stringstream ss;
				A.erase (0, (string ("rectangle(").size ()));
				A.erase (A.size () - 1, 1);
				ss << A;
				char t;
				ss >> R.Top.x >> t >> R.Top.y >> t >> R.Bottom.x >> t >> R.Bottom.y;
			}
			{
				stringstream ss;
				B.erase (0, (string ("circle(").size ()));
				B.erase (B.size () - 1, 1);
				ss << B;
				char t;
				ss >> C.O.x >> t >> C.O.y >> t >> C.R;
			}	
		}
		R.calc ();
				auto aX = R.Top.x;
				auto aY = R.Top.y;
				auto bX = R.Bottom.x;
				auto bY = R.Bottom.y;
				auto rX = C.O.x;
				auto rY = C.O.y;
				auto r = C.R;
				if ((sqrt ((aX - rX) * (aX - rX) + (aY - rY) * (aY - rY)) <= r) || (sqrt((bX-rX)*(bX-rX) + (bY-rY)*(bY-rY))<=r) || (sqrt((aX-rX)*(aX-rX) + (bY-rY)*(bY-rY))<=r) || (sqrt((bX- rX) * (bX - rX) + (aY-rY)*(aY-rY))<=r))
//				if((sqrt ((R.Top.x - C.O.x)*(R.Top.x - C.O.x) + (-R.Top.y + C.O.y) * (R.Top.y - C.O.y)) <= C.R) or (sqrt ((R.Bottom.x - C.O.x) * (R.Bottom.x - C.O.x) + (R.Bottom.y - C.O.y) * (R.Bottom.y - C.O.y)) <= C.R) or (sqrt ((R.Top.x - C.O.x)*(R.Top.x - C.O.x) + (R.Bottom.y - C.O.y) * (R.Bottom.y - C.O.y)) <= C.R) or (sqrt ((R.Bottom.x - C.O.x) * (R.Bottom.x - C.O.x) + (R.Top.y - C.O.y) * (R.Top.y-C.O.y)) <= C.R))
				{
					cout << "Rectangle and circle cross\n";
				}
				else
				{
					cout << "Rectangle and circle do not cross\n";
				}
		if (PointIsinRect (C.O, R))
		{
			double perp1 = abs (C.O.x - R.Top.x);
			double perp2 = abs (R.Bottom.y - C.O.y);
			double perp3 = abs (R.Bottom.x - C.O.x);
			double perp4 = abs (C.O.y - R.Top.y);
			double OA    = sqrt (dist2 (C.O, R.A));
			double OB    = sqrt (dist2 (C.O, R.B));
			double OC    = sqrt (dist2 (C.O, R.C));
			double OD    = sqrt (dist2 (C.O, R.D));

cout << perp1 << " "; 
cout << perp2 << " "; 
cout << perp3 << " "; 
cout << perp4 << "\n"; 
cout << OA << " " << OB << " " << OC << " " << OD << "\n";
                                  
			if (                  
				perp1 < C.R and 
				perp2 < C.R and 
				perp3 < C.R and 
				perp4 < C.R and 
				OA <= C.R and
				OB <= C.R and
				OC <= C.R and
				OD <= C.R)
			{
				cout << "Rectangle inside circle\n";
			}
			else if (
				perp1 >= C.R and 
				perp2 >= C.R and 
				perp3 >= C.R and 
				perp4 >= C.R and 
				OA > C.R and
				OB > C.R and
				OC > C.R and
				OD > C.R)
			{
				cout << "Circle inside rectangle\n";
			}
			else // cross or don't cross
			{
			}

		}
		else
		{
			R.calc ();
			double OA    = sqrt (dist2 (C.O, R.A));
			double OB    = sqrt (dist2 (C.O, R.B));
			double OC    = sqrt (dist2 (C.O, R.C));
			double OD    = sqrt (dist2 (C.O, R.D));

			pair < double, Point > arr [] = {
				{OA, R.A},
				{OB, R.B},
				{OC, R.C},
				{OD, R.D}};
			sort (arr, arr + 4);
			
			Point _1 = arr [0].second, _2 = arr [1].second;
			double MIN = arr [0].first;

			if (_1.x == _2.x)
			{

				if (
						(C.O.y <= _2.y and C.O.y >= _1.y) or
						(C.O.y > _2.y and C.O.y < _1.y)
				   )
				{
					if (MIN <= C.R or _1.x <= C.R)
						cout << "Rectangle and circle cross\n";
					else
						cout << "Rectangle and circle do not cross\n";
				}
				else
				{
					if ( MIN <= C.R )
						cout << "Rectangle and circle cross\n";
					else
						cout << "Rectangle and circle do not cross\n";
				}
			}

			if (_1.y == _2.y)
			{

				if (
						(C.O.x <= _2.x and C.O.x >= _1.x) or
						(C.O.x > _2.x and C.O.x < _1.x)
				   )
				{
					if (MIN <= C.R or _1.y <= C.R)
						cout << "Rectangle and circle cross\n";
					else
						cout << "Rectangle and circle do not cross\n";
				}
				else
				{
					if ( MIN <= C.R )
						cout << "Rectangle and circle cross\n";
					else
						cout << "Rectangle and circle do not cross\n";
				}
			}
		}
	}
}
