//GMP
#include <gmpxx.h>
//Standard
#include <iostream>

using namespace std;

int main ()
{
	string mask;
	int bits = 16;
	int n = 50;
	mask = string ('0', bits);
	mask [0] = mask [bits - 1] = '1';
	while (n > 0)
	{
		for (int base = 2 ; base < 11 ; base ++)
		{
			mpz_class curr (mask, base);
			
		}
		mask += (1 << 1);
	}
}
