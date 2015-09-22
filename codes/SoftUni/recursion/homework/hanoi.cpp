#include <stdio.h>

unsigned n;

void diskMove (unsigned n, char a, char b)
{
	printf("Преместете диск %u от %c на %c.\n", n, a, b);
}

void hanoi (char a, char c, char b, unsigned numb)
{
	if (1 == numb)
		diskMove(1, a, c);
	else
	{
		hanoi(a, b, c, numb - 1);
		diskMove(numb, a, c);
		hanoi(b, c, a, numb - 1);
	}
}
int main ()
{
	scanf ("%u", &n);
	hanoi ('a', 'c', 'b', n);
}
