#include <iostream>

int main ()
{
	std::cin.tie (nullptr);
	std::ios::sync_with_stdio (false);
	std::string s;
	std::cin >> s;
	unsigned k;
	std::cin >> k;
	for (unsigned i = 0 ; i < k ; i ++)
	{
		unsigned len;
		std::cin >> len;
		unsigned long long n = 0;
		for (unsigned j = 0 ; j < s.size () - len ; j ++)
		{
			for (unsigned a = j + 1 ; a < s.size () - len ; a ++)
				n += (s.substr (j, len) == s.substr (a, len));
		}
		std::cout << n << "\n";
	}
}
