//#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <fstream>

using namespace std;

//
ifstream cin ("heritage.in");
//
ofstream cout ("heritage.out");

char input [256][256];
int a [256][256];

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	int n, m, K;
	cin >> n >> m >> K;
	for (int i = 0 ; i < n ; i ++)
		for (int j = 0 ; j < m ; j ++)
		{
			cin >> input [i][j];
			input [i][j] -= '0';
		}

	a [0][0] = input [0][0];
	for (int i = 1 ; i < n ; i ++)
		a [i][0] = a [i - 1][0] + input [i][0];
	for (int i = 1 ; i < m ; i ++)
		a [0][i] = a [0][i - 1] + input [0][i];
	for (int i = 1 ; i < n ; i ++)
		for (int j = 1 ; j < m ; j ++)
			a [i][j] = a [i - 1][j] + a [i][j - 1] - a [i - 1][j - 1] + input [i][j];
//	for (int i = 0 ; i < n ; i ++, cout << "\n")
//		for (int j = 0 ; j < m ; j ++)
//			cout << a [i][j] << " ";
	
	int Max = -1;
	vector < pair < int, int > > Krazlog;
	for (int i = 1 ; i * i <= K ; i ++)
		if (K % i == 0)
		{
			Krazlog.push_back ({i, K / i});
			Krazlog.push_back ({K / i, i});
		}
	for (int I = 0 ; I < Krazlog.size () ; I ++)
	{
		for (int i = 0 ; i < n ; i ++)
			for (int j = 0 ; j < m ; j ++)
			{
				int k = i + Krazlog [I].first - 1;
				int l = j + Krazlog [I].second - 1;
				if (k < n and l < m)
				{
					//cout << (k - i + 1) << " x " << (l - j + 1) << "\n"; 
					if ((k - i + 1) * (l - j + 1) == K)
					{
						//cout << "\t" << k << " " << l << " " << i << " " << j << "\n";
						//cout << "\t" << a [k][l] << " - " << a [0][i] << " - " << a [l][0] << " + " << a [0][0] << "\n";;
						Max = max (Max, a [k][l] - a [k][j - 1] - a [i - 1][l] + a [i - 1][j - 1]);
					}
				}
			}
	}
	cout << Max << "\n";
}
