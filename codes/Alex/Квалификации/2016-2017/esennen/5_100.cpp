#include <iostream>

using namespace std;

unsigned long long table [1004][502];

unsigned long long count (long long m, long long n)
{
	//cout << n << endl;
	long long i, j, x, y, S;
	
	for (i = 0 ; i < m ; i ++)
		table [0][i] = 1;

	//cout << n << endl;
	for (i = 1 ; i < n + 1 ; i ++)
	{
		for (j = 0 ; j < m ; j ++)
		{
			S = j * 2 + 1;
			//cout << i << " " << j << " " << S << endl;
			x = (i - S >= 0) ? table [i - S][j] : 0;
			//cout << i << " " << j << " " << S << endl;
			y = (j >= 1) ? table [i][j - 1] : 0;
			//cout << i << " " << j << " " << S << endl;
			table [i][j] = x + y;
			//cout << i << " " << j << " " << S << endl;
		}
	}
	return table [n][m - 1];
}

int main ()
{
	long long n;
	cin >> n;
	//cout << n << endl;
	cout << count (500, n) << "\n";
	//cout << n << endl;
	return 0;
}
