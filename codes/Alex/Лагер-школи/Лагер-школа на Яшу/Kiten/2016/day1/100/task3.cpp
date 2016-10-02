#include <iostream>
#include <iomanip>

using namespace std;

//      sx  len
int dp [50][50 ];
int arr [50];
int sums [50];

int main ()
{
	int n;
	cin >> n;
	cin >> arr [0];
	dp [0][1] = arr [0];
	sums [0] = arr [0];
	for (int x = 1 ; x < n ; x ++)
	{
		cin >> arr [x];
		dp [x][1] = arr [x];
		sums [x] = sums [x - 1] + arr [x];
	}

	for (int len = 2 ; len <= n ; len ++)
		for (int i = 0 ; i <= n - len ; i ++)
		{
			dp [i][len] = dp [i][1] + dp [i + 1][len - 1];
			for (int divide = 2 ; divide < len ; divide ++)
				dp [i][len] = min (dp [i][len], dp [i][divide] + dp [i + divide][len - divide]);
			dp [i][len] += sums [i + len - 1] - sums [i - 1];
		}
	for (int len = 1 ; len <= n ; len ++, cout << "\n")
	{
		cout << "Len: " << len << ": ";
		for (int i = 0 ; i < len - 1 ; i ++) cout << "   ";
		for (int i = 0 ; i <= n - len ; i ++)
			cout << setw (2) << dp [i][len] << "   ";
	}
	cout << dp [0][n] << "\n";
}
