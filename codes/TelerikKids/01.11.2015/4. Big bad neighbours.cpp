#include <iostream>
#include <string.h>

using namespace std;

int arr [30000];
int n;
int dp [30000];

int sub (int s, int e)
{
	memset (dp, 0, sizeof (dp));
	dp [s] = arr [s];
	dp [s + 1] = max (dp [s], arr [s + 1]);
	for (int i = s + 2 ; i <= e ; i ++)
		dp [i] = max (dp [i - 1], dp [i - 2] + arr [i]);
	return dp [e];	
}

int ans ()
{
	return max (sub (0, n - 2), sub (1, n - 1));
}

int main ()
{
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
		cin >> arr [i];
	if (n == 1) cout << arr [0] << "\n";
	else if (n == 2) cout << max (arr [0], arr [1]) << "\n";
	else cout << ans () << "\n";
}
