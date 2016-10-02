#include <iostream>
#define x(NUM) fib(NUM); y (NUM - 1);
#define y(NUM) fib(NUM); x (NUM - 1);
#define x(NUM) fib(NUM); y (NUM - 1);
using namespace std;

constexpr uint64_t fact (size_t n)
{
	return (n <= 1) ? 1 : fact (n - 1) * n;
}

constexpr uint64_t fib (size_t n)
{
	if (n < 2)
		return 1;
	else
		return fib (n - 2) + fib (n - 1);
}

int main ()
{
	cout << fact (1000) << "\n";
	for (int i = 0 ; i < 1000 ; i ++)
		cout << fact (i) << "\n";
	x(1000);
}
