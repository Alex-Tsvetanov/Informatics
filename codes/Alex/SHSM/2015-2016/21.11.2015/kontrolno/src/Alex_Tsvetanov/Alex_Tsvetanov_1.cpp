#include <stdio.h>

int main ()
{
	int h1, m1, h2, m2;
	scanf ("%d:%d",&h1,&m1);
	scanf ("%d:%d",&h2,&m2);
	int hm1, hm2;
	hm1 = h1 * 60 + m1;
	hm2 = h2 * 60 + m2;
	int diff = hm2 - hm1;
	if (diff < 0)
		diff += 24*60;
	printf ("%02d:%02d", diff / 60, diff % 60);
}
