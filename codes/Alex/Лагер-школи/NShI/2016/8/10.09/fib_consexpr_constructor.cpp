#include <iostream>

template <size_t x>
struct fib
{
	static fib_t <x - 1> prev;
	static fib_t <x - 2> pprev;
	constexpr static uint64_t get ()
	{
		return prev.get () + pprev.get ();
	}
	constexpr static uint64_t get (const size_t& n)
	{
		if (n == x)
			return get ();
		if (n == x - 1)
			return prev.get ();
		if (n == x - 2)
			return pprev.get ();
		else
			return pprev.get (n);
	}

};

template <>
struct fib <1>
{
	constexpr static uint64_t get ()
	{
		return 1;
	}
	constexpr static uint64_t get (const size_t& n)
	{
		if (n == 1)
			return 1;
		return 1;
	}
};

template <>
struct fib <2>
{
	constexpr static uint64_t get ()
	{
		return 1;
	}
	constexpr static uint64_t get (const size_t& n)
	{
		if (n == 2)
			return 1;
		return 1;
	}
};

int main ()
{
	std::cout << fib<901>::get () << "\n";
	std::cout << fib<901>::get (3) << "\n";
	for (int i = 0 ; i < 900 ; i ++)
		std::cout << fib<901>::get (i + 1) << "\n";
}
