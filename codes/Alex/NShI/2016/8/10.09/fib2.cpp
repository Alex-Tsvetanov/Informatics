#include <iostream>
using namespace std;
#define NUM 500

//template <unsigned int N>
//struct Fibonacci {
//	enum { value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value };
//};
//
//template <>
//struct Fibonacci<1> {
//	enum { value = 1 };
//};
//
//template <>
//struct Fibonacci<0> {
//	enum { value = 1 };
//};

constexpr unsigned int fib (unsigned int n)
{
	return (n > 1 ? fib (n - 1) + fib (n - 2) : 1);
}

enum {i = fib(NUM)};
constexpr unsigned int fib_arr (unsigned int n)
{
	for (int i = n ; i >= 0 ; i --)
		(fib (i));        // run time :-?
	return 5;
}

int main()
{

//	cout << "Meta_fib(NUM)      : " << Fibonacci <NUM> :: value << endl; // compile time :)
	fib_arr (NUM);
	for (int i = NUM ; i >= 0 ; i --)
		cout << (fib (i)) << "\n";        // run time :-?
	return 0;
}
