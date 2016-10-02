#include "vector2d.hpp"
#include <iostream>

using namespace std;

int main ()
{
	vector2d v1, v2;
	double x, y;
	
	cin >> x >> y;
	v1 = vector2d (x, y);
	
	cin >> x >> y;
	v2 = vector2d (x, y);
	
	cout << v1.X () << " " << v1.Y () << ", " << v2.X () << " " << v2.Y () << "\n";
	vector2d p = v1 + v2;
	vector2d m = v1 - v2;
	double d = dot_product (v1, v2);
	double c = cross_product (v1, v2);
	cout << p.X () << " " << p.Y () << "\n";
	cout << m.X () << " " << m.Y () << "\n";
	cout << d << "\n";
	cout << c << "\n";
	cout.flush ();
}
