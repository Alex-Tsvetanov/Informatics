#include "gfw.hpp"
#include <iostream>
#include <chrono>

int main ()
{
	gfw::Vec <double, 3> v;
	gfw::Mat <double, 3, 2> m;
	for (int x = 0 ; x < 3 ; x ++, std::cout << "\n")
		for (int y = 0 ; y < 3 ; y ++)
			std::cout << m [x][y] << " ";

	return 0;
}
