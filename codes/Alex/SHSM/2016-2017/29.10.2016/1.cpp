#include <iostream>

using namespace std;

int T [2][1000000];
int A [2][1000000];
int dp [2][1000000];

int S [2], E [2];

int main ()
{
	int n;
	cin >> n;

	cin >> S [0] >> E [0] >> S [1] >> E [1];

	for (int i = 0 ; i < 2 ; i ++)
		for (int j = 0 ; j < n ; j ++)
			cin >> T [i][j];

	for (int i = 0 ; i < 2 ; i ++)
		for (int j = 0 ; j < n - 1 ; j ++)
			cin >> A [i][j];

	dp [0][0] = S [0] + T [0][0];
	dp [1][0] = S [1] + T [1][0];
		for (int j = 1 ; j < n ; j ++)
	for (int i = 0 ; i < 2 ; i ++)
		{
			cout << i << " " << j << " out: " << dp [1 - i][j - 1] << " + " << A [1 - i][j - 1] << " " << dp [i][j - 1] << " + " << T [i][j] << "\n";
			dp [i][j] = min (dp [1 - i][j - 1] + A [1 - i][j - 1], dp [i][j - 1] + T [i][j]);
		}
	
	for (int i = 0 ; i < 2 ; i ++, cout << "\n")
		for (int j = 0 ; j < n ; j ++)
			cout << dp [i][j] << " ";

	cout << min (dp [0][n - 1], dp [1][n - 1]) << "\n";
}
