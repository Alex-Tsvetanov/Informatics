#include <iostream>

using namespace std;

int arr [1000000];

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);

	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
		cin >> arr [i];

	int ans = 0;
	for (int i = 0 ; i < n ; i ++)
		for (int j = 0 ; j < i ; j ++)
			ans += (arr [i] < arr [j]);

	cout << ans << "\n";
}
