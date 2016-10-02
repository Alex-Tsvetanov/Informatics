#include <iostream>
//#include <stack>
#include <algorithm>

using namespace std;

int arr [100000];

int main ()
{
	ios::sync_with_stdio (false);
	cin.tie (nullptr);
	int n;
	cin >> n;
	int ans = 0;
	int br = 0;
	for (int i = 0 ; i < n ; i ++)
	{
		cin >> arr [i];
////	int blq = 0;
////	for (int j = 0 ; j < i ; j ++)
////		blq += (arr [j] + j > i);
		ans += br * arr [i];
		if (arr [i] + i > i + 1)
			br ++;
	}
	cout << ans << "\n";
}
