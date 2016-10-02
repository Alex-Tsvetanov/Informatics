#include <iostream>

const unsigned a = 257, m = 1e9 + 7;

unsigned hash (const std::string& s)
{
	unsigned h = 0;
	for (size_t i = 0 ; i < s.size () ; i ++)
		h = ((((unsigned long long)h * a) % m) + s [i]) % m;
	return h;
}

int main ()
{
	std::cout << hash ("1234") << "\n";
}
