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
		int bla2 = bla;
		arr.push_back (bla2);
		bla2 = bla;
		NUMS.insert (bla2);
		//cout << bla << " " << bla2 << "\n";
		//cout.flush ();
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
			//cout << br << " " << b << "\n";
		//cout.flush ();
			if (br >= k)
				ans ++;
		}
		cout << ans << "\n";
		//cout.flush ();
	}
}
