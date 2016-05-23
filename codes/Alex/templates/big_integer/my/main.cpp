#include <iostream>
#include "big_integer.hpp"

using namespace std;

int main ()
{
	big_int a (10);
	big_int b (5);
	{
		a += b;
		a += -7;
		b += +7;
	}
	cout << a << " " << b << " " << big_int(0)-b << "\n";
	a += big_int(0)-b;
	cout << a << " " << b << "\n";
}
