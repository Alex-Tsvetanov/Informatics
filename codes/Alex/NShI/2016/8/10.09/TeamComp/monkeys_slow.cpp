#include <iostream>

using namespace std;

int arr [100000];

int main ()
{
	ios::sync_with_stdio (false);
	cin.tie (nullptr);
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0 ; i < n ; i ++)
	{
		cin >> arr [i];
		int blq = 0;
		for (int j = 0 ; j < i ; j ++)
			blq += (arr [j] + j > i);
		ans += blq * arr [i];
	}
	cout << ans << "\n";
}
