#include <iostream>

int main ()
{
	short a, b;
	std::cin >> a >> b;
	if (b < a) std::swap (a, b);
	std::cout << (a + b) * (b - a + 1) / 2;
	return 0;
}
