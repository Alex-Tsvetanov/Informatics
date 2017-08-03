#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

template <typename T = long long>
struct point
{
	T x, y;
	point (long long _x = 0, long long _y = 0) : x (_x), y (_y)
	{

	}

	explicit operator long double () const
	{
		return x * x + y * y;
	}
};


struct line  // ax + b
{
	long long a, b;
	line (long long _k = 0, long long _b = 0) : a (_k), b (_b)
	{
	
	}
};

template<typename T>
point<long double> operator | (point<T> A, line B)
{
	if (B.a != 0)
	{
		point<long double> B_;
		B_.x = (long double)(B.a * (A.y + (long double)(A.x) / B.a - B.b)) / (B.a * B.a + 1);
		point<long double> A1;
		A1.x = (B.a * A.y - B.a * B.a * A.x - B.a * B.b) / (long double)(B.a * B.a + 1);
		A1.y = (long double)(A1.x - B_.x + abs(B_.x - A.x) + A.y * B.a) / B.a;
		return A1;
	}
	else
	{
		return point<long double> (A.x, -A.y);
	}
}

template<typename A, typename B>
point<long double> operator - (point<A> a, point<B> b)
{
	return point<long double> (a.x - b.x, a.y - b.y);
}

int main ()
{
	long long a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	line y (a, b);
	//point<long long> A (c, d), B (e, f);
	point<long long> B (c, d), A (e, f);
	point<long double> B1 = B | y;
	point<long double> A1 = A | y;
	//cout << B1.x << " " << B1.y << endl;
	//B1 = B1 | y;
	//cout << B1.x << " " << B1.y << endl;

	//long double ans2 = min ((long double)(A - B), min ((long double) (A - B1), min ((long double) (A1 - B1), (long double) (B - A1))));
	long double ans2 = min ((long double)(A - B), (long double) (A - B1));

	cout << fixed << setprecision(6) << sqrt (ans2) << endl;
}
