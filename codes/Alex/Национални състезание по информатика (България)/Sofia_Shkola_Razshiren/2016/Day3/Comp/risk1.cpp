#include <iostream>
#include <map>
#define MAXN 1000

using namespace std;

map <int, int> code;
int dp [MAXN][MAXN];

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	int n, q, k, ind = 0;
	cin >> n >> q >> k;
	for (int i = 0 ; i < n ; i ++)
	{
		int input;
		cin >> input;
		if (code.find (input) == code.end ())
		{
			code [input] = ind;
		}
		if (i != 0)
		{
			for (int j = 0 ; j < MAXN ; j ++)
				dp [i][j] = dp [i - 1][j];
			dp [i][code [input]] ++;
		}
		else
			dp [i][code [input]] = 1;
	}
	for (int i = 0 ; i < q ; i ++)
	{
		int l, r, ans = 0;
		cin >> l >> r;
		for (int j = 0 ; j < MAXN ; j ++)
			if (l == 0 and dp [r][j] >= k)
				ans ++;
			else if (dp [r][j] - dp [l - 1][j] >= k)
				ans ++;
		cout << ans << "\n";
	}
}
