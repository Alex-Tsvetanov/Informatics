#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

int cnt [200001];
int arr [200001];
const int MOD = 1000000007;

constexpr int fact (int n)
{
	return ((n <= 1)?1:((fact (n - 1) * n) % MOD));
}

int main ()
{
	const int f = fact (200005);
	int n = f;
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		cin >> arr [i];
		cnt [arr [i]] ++;
	}
	int ans = 0;
	for (int i = 0 ; i < n ; i ++)
	{
		cnt [arr [i]] --;
		int k = 0;
		for (int j = 0 ; j < arr [i] ; j ++)
			k += (cnt [j] > 0);
		int curr = fact (n - i - 1);
		for (int j = 0 ; j < n ; j ++)
			curr /= fact (cnt [j]);
		ans +=
	}
	cout << ans << "\n";
}
