#include <iostream>

using namespace std;

int main ()
{
	int n;
	cin >> n;
	int** dp = new int* [n + 1];
	for (int i = 0 ; i <= n ; i ++)
		dp [i] = new int [n + 1];

	for (int i = 0 ; i <= n ; i ++)
		dp [0][i] = 1;
	dp [1][0] = 1;

	for (int row = 1 ; row <= n ; row ++)
	{
		for (int col = 0 ; col < row ; col ++)
			dp [row][col] = dp [row - 1][col] + dp [row][col - 1];
		dp [row][row] = dp [row][row - 1];
	}

	for (int row = 0 ; row <= n ; row ++)
	{
		for (int col = 0 ; col <= row ; col ++)
			cout << dp [row][col] << " ";
		cout << endl;
	}

	cout << dp [n][n] << endl;

	for (int i = 0 ; i <= n ; i ++)
		delete[] dp [i];
	delete[] dp;

}
