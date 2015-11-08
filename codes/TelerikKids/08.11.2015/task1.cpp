#include <iostream>
#include <utility>

using namespace std;

int n, m;
int* input;

pair <int, int>* dp;

int main ()
{
	cin >> n;
	cin >> m;
	input = new int [n + 1];
	for (int i = 1 ; i < n + 1 ; i ++)
		cin >> input [i];
//----------End of input --------------
	dp = new pair <int, int> [n + 1];
	dp [0] = {0, -1};
	for (int i = 1 ; i < n + 1 ; i ++)
	{
		int last_index = -1;
		int maxLenght = -1;
		for (int j = i - 1 ; j >= 0 ; j --)
			if (dp [j].second > -1)
			{
				if (abs (input [i] - input [dp [j].second]) <= m)
				if (maxLenght < dp [j].first)
				{
					maxLenght = dp [j].first + 1;
					last_index = i;
				}
			}
		if (maxLenght < 1)
			maxLenght = 1, last_index = i;

		dp [i] = {maxLenght, last_index};
	}
//------------------End of init DP------------------
	cout << dp [n].first << "\n";
}
