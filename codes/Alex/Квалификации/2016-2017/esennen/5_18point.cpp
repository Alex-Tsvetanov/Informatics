#include <iostream>

using namespace std;

const long long MAXCOINS = 500;
const long long MAXSUM = 1000;

long long F [MAXSUM][MAXSUM];

bool exist [MAXSUM];
long long sum = 0;
const long long n = 500;

void init ()
{ 
	long long i, j;
	
	for (i = 0; i <= sum; i++)
		for (j = 0; j <= sum; j++)
			F[i][j] = 0;
	
	for (i = 0 ; i <= sum ; i ++)
		exist [i] = 0;

	for (i = 0 ; i < n ; i ++)
		exist [2 * i + 1] = 1;
}

long long count (long long sum, long long max)
{
	long long i;
	if (sum <= 0)
		return 0;
	if (F [sum][max] > 0)
		return F [sum][max];
	else 
	{
		if (sum < max)
			max = sum;
		if (sum == max && exist [sum])
			F [sum][max] = 1;
		for (i = max ; i > 0 ; i --)
			if (exist [i])
				F [sum][max] += count (sum - i, i);
	}
	return F [sum][max];
} 

int main () 
{
	cin >> sum;
	init ();
	cout << count (sum, sum) << "\n";
	return 0;
}
