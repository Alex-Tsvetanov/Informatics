#include <iostream>

int main ()
{
	for (unsigned char a = 0 ; a < 255 ; a ++)
		std::cout << (int)a << " " << a << "\n";
}
