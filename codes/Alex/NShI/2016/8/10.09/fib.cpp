#include <iostream>
#include <limits>

using namespace std;

constexpr uint64_t fib (const size_t n)
{
	if (n < 2)
		return 1;
	else
		return fib (n - 1) + fib (n - 2);
}

constexpr uint64_t fibonacci (uint64_t i) 
{
	if (arr [i] != 0) return arr [i];
	else return arr [i] = fibonacci (i - 1) + fibonacci (i - 2);
}

int main ()
{
	uint64_t lol = fibonacci (100);
	cout << lol << endl;

	for (uint64_t i = 0 ; i <= 100 ; i ++)
		cout << arr [i] << endl;

	cout << "---------------------------------------\n";	

	uint64_t lol2 = fib (100);
	cout << lol2 << endl;

	for (uint64_t i = 0 ; i <= 100 ; i ++)
		cout << fib (i) << endl;
}
