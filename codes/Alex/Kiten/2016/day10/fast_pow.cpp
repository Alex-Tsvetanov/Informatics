#include <iostream>

unsigned m;

unsigned long long pow (unsigned a, unsigned long long n)
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return a;
	else
	{
		unsigned long long mid = pow (a, n / 2) % m;
		mid = (mid * mid) % m; 
		if (n % 2 == 0)
			return mid;
		else
			return (mid * a) % m;
	}
}

int main ()
{
	unsigned a, n;
	std::cin >> a >> n >> m;
	std::cout << pow (a, n) << "\n";
}
