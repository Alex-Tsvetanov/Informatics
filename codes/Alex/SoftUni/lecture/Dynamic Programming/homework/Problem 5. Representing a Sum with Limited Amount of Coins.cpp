#include <stdio.h>
#define MAXCOINS    100
#define MAXSUM      100
#define SWAP(a, b)  { a = a ^ b; b = a ^ b; a = a ^ b; }
unsigned long** F;
unsigned n = 7;
unsigned sum = 6;
unsigned* coins;

void init ()
{
    scanf ("%u", &n);
    coins = new unsigned [n];
    for (unsigned i = 0 ; i < n ; i ++)
        scanf ("%u", &coins [i]);
    scanf ("%u", &sum);

    unsigned i;
    F = new unsigned long* [sum + 1];
    for (i = 0; i <= sum; i++)
        F [i] = new unsigned long [sum + 1];
}
void destroy ()
{
    delete []coins;
    unsigned i;
    for (i = 0; i <= sum; i++)
        delete[] F [i];
    delete[] F;
}
void sort()
{
	unsigned i, j;
	for (i = 0; i < n-1; i++)
		for (j = i + 1; j < n; j++)
			if (coins[i] > coins[j])
				SWAP(coins[i], coins[j]);
}
unsigned long count(int sum, int k)
{ 
	unsigned j;
	if (sum <= 0 || k < 0)
		return 0;
	if (F[sum][k] > 0)
		return F[sum][k];
	else
	{
		if (coins[k] == (unsigned)sum)
			F[sum][k] = 1;
		F[sum][k] += count(sum-coins[k], k-1);
		j = k;
		while (j > 0 and coins[j] == coins[k])
			j --;
		if (coins [j] != coins [k])
			F[sum][k] += count(sum, j);
	}
	return F[sum][k];
}
int main()
{
	init();
	sort();
	printf("%lu", count(sum, n-1));
	return 0;
}
