#include <stdio.h>

unsigned n;

void diskMove (unsigned n, char a, char b)
{
	printf("Преместете диск %u от %c на %c.\n", n, a, b);
}

void hanoy (char a, char c, char b, unsigned numb)
{
	if (1 == numb)
		diskMove(1, a, c);
	else
	{
		hanoy(a, b, c, numb - 1);
		diskMove(numb, a, c);
		hanoy(b, c, a, numb - 1);
	}
}
int main ()
{
	scanf ("%u", &n);
	//printf ("Брой дискове: %u\n", n);
	hanoy ('a', 'c', 'b', n);
	return 0;
}
