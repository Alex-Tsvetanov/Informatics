#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

constexpr __uint128_t fact (int n)
{
	return (n <= 1)?1:(fact (n - 1) * n);
}

string print (__uint128_t x, int f = 0)
{
	uint64_t mod = 1e18;
	uint64_t b = x % mod;
	uint64_t a = x / mod;
	stringstream ss;
	if (a != 0)
		ss << a << setw (18) << setfill ('0') << b;
	else
		ss << b;
	int y = (f - ss.str ().size ());
	if (y < 0)
		y = 0;

	return string (y, '0') + ss.str ();

}

int main ()
{
	__uint128_t X = fact (100);
	int n, k, p;
	cin >> n >> k >> p;
	//n ++;
	__uint128_t number = 
	(n - 1) * (100 - p) * k * p * (fact (n - 1 + k) / (fact (n - 1) * fact (k)));
	__uint128_t mod = 100;
	cout << print (number / mod) << "." << print (number % mod, 2).substr (0, 2);
}
