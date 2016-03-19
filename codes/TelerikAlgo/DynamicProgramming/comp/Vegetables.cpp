#include <iostream>
#include <algorithm>

using namespace std;

long long dp1[1024][1024];
long long dp2[1024][1024];
const long long mod = 10037;

long long my_pow (int a, int b)
{
	long long result = 1;
	while (b > 0)
	{
		if (b & 1)
		{
			result *= a;
			result %= mod;
		}
		b >>= 1;
		a %= mod;
		a *= a;
		a %= mod;
	}

	return result % mod;
}

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	long long prev, curr, next;
	{
		long long n, m;
		cin >> n >> m;
		for (int i = 1 ; i <= n ; i ++)
			for (int j = 1 ; j <= m ; j ++)
			{
				cin >> dp1[i][j];
				dp1[i][j] += (max (dp1[i - 1][j], dp1[i][j - 1]));
			}
		curr = dp1[n][m] % mod;
		prev = curr;
	}
	{
		long long n, m;
		cin >> n >> m;
		for (int i = 1 ; i <= n ; i ++)
			for (int j = 1 ; j <= m ; j ++)
			{
				cin >> dp2[i][j];
				dp2[i][j] += (max (dp2[i - 1][j], dp2[i][j - 1]));
			}
		curr = dp2[n][m] % mod;
	}
	long long n;
	cin >> n;
	if (n == 1)
		cout << prev % mod << "\n";
	else if (n == 2)
		cout << curr % mod << "\n";
	else
	{
		for (int i = 2 ; i < n ; i ++)
		{
			next = my_pow (prev, curr) % mod;
			prev = curr % mod;
			curr = next % mod;
		}
		cout << next << "\n";
	}
}
