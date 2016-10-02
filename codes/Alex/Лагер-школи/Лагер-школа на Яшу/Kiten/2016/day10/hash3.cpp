#include <iostream>

const unsigned a = 257, m = 1e9 + 7;

unsigned long long max_pow = 1;

unsigned hash (const std::string& s)
{
	unsigned h = 0;
	for (size_t i = 0 ; i < s.size () - 1 ; i ++)
		max_pow *= a;
	for (size_t i = 0 ; i < s.size () ; i ++)
		h = (((h * a) % m) + s [i]) % m;
	return h;
}

unsigned roll (char rem, unsigned hash, char add)
{
	hash += m;
	hash -= (rem * max_pow) % m;
	hash %= m;
	hash *= a;
	hash %= m;
	hash += add;
	hash %= m;
	return hash;
}

int main ()
{
	unsigned my_hash = hash ("12345");
	std::cout << my_hash << "\n";
	my_hash = roll ('1', my_hash, '6');
	std::cout << my_hash << "\n";
}
