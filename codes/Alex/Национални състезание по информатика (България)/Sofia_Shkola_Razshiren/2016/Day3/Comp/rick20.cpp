#include <iostream>

using namespace std;

int dp [50000][128];

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	int n, q, k;
	cin >> n >> q >> k;
	for (int i = 1 ; i <= n ; i ++)
	{
		int input;
		cin >> input;
		for (int j = 1 ; j <= 100 ; j ++)
			dp [i][j] = dp [i - 1][j];
		dp [i][input] ++;
	}
	for (int i = 0 ; i < q ; i ++)
	{
		int l, r, ans = 0;
		cin >> l >> r;
		for (int j = 0 ; j <= 100 ; j ++)
			if (dp [r][j] - dp [l - 1][j] >= k)
				ans ++;
		cout << ans << "\n";
	}
}
