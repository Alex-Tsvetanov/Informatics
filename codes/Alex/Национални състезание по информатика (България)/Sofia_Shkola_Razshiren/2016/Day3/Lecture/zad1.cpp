#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <stdio.h>
#define uint64_t unsigned long long
using namespace std;

/*abstract*/ class function
{
public:
	vector <double> v;
	virtual double f (double x) = 0;
};

class square_function : function
{
public:
	double a, b, c;
	square_function (double a1, double b1, double c1)
	{
		if (a1 == 0)
			throw "Not square function";
		v = {a1, b1, c1};
		a = v [0];
		b = v [1];
		c = v [2];
	}
	double f (double x)
	{
		double ans = 0;
		for (auto& a : v)
			ans = ans * x + a;
		return ans;
	}
	double max_value ()
	{
		return (v [2] - v [1] * v [1] / (4 * v [0])); 
	}
	double max_value_x ()
	{
		double D = -16*a*a*b*(4*a-b);
		if (D < 0)
			throw "Compex root";
		return sqrt (D) / (8*a*a); 
	}
	bool in (double x, double y)
	{
		return y < f (x);
	}
};

const double a = -1, b = 4, c = 10;

square_function f (a, b, c);

const double range_y = f.max_value (); 
const double range_x = f.max_value_x () * 2;
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> dis(0, range_x);

double Random ()
{
    return dis(gen);
}

int main ()
{
	printf ("Area: %.1f\n", range_y * range_x);
	double avarage = 0;
	uint64_t Count;
	cin >> Count;
	uint64_t br = 0;
	for (uint64_t steps = Count ; steps <= Count ; steps ++)
	{
		br ++;
		uint64_t percentage = 0;
		for (uint64_t i = 0 ; i < steps ; i ++)
		{
			int x, y;
			x = Random ();
			y = Random ();
			percentage += f.in (x, y);
		}
		double curr = percentage * range_y * range_x / steps;
		avarage += curr;
		printf ("%llu/%llu ===== %.1f -> %.1f\n", percentage, steps, curr, avarage / br);
	}
	printf ("%.1f\n", avarage / br);
}
