#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector <int> arr;
set <int> NUMS;

int32_t main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	int n, q, k;
	cin >> n >> q >> k;
	arr.push_back (0);
	for (int i = 0 ; i < n ; i ++)
	{
		int bla;
		cin >> bla;
		arr.push_back (bla);
		NUMS.insert (bla);
	}
	for (int i = 0 ; i < q ; i ++)
	{
		int l, r, ans = 0;
		cin >> l >> r;
		for (auto& b : NUMS)
		{
			int br = 0;
			for (int j = l ; j <= r ; j ++)
				if (arr [j] == b)
					br ++;
			if (br >= k)
				ans ++;
		}
		cout << ans << "\n";
	}
}
