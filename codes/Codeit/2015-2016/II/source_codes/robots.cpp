#include <fstream>
//#include <iostream>

using namespace std;

const int64_t mod = 1e9 + 7;

int64_t power (int64_t a, int64_t b)
{
	if ( b == 1 )
		return a % mod;
	if ( b == 0 )
		return 1;
	int64_t power_1 = power (a, b / 2) % mod;
	power_1 = (power_1 * power_1) % mod;
	if (b % 2)
		power_1 = (power_1 * a) % mod;
	return power_1;
}

int main ()
{
	ifstream cin ("robots.in");
	ofstream cout ("robots.out");
	int64_t n;
	cin >> n;
	int64_t ans = ((power (2, n) % mod) * (power (3, n * (n - 1) / 2) % mod)) % mod;
	cout << ans << "\n";
}
