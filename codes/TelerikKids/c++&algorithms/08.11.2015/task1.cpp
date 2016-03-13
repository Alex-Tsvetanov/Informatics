#include <iostream>
#include <iomanip>
#include <utility>

using namespace std;

int n, m;
int* input;
pair <int, int>* dp;

bool check (int ind1, int ind2)
{
//	cout << "Check for " << input [ind1] << " and " << input [ind2] << ": ";
	if (ind2 == 0 or ind1 == 0)
	{
//		cout << "true\n";
		return true;
	}
//	cout << boolalpha << (abs (input [ind1] - input [ind2]) <= m) << "\n";;
	return (abs (input [ind1] - input [ind2]) <= m);
}

int main ()
{
	cin >> n;
	cin >> m;
	input = new int [n + 1];
	for (int i = 1 ; i < n + 1 ; i ++)
		cin >> input [i];
//----------End of input --------------
	dp = new pair <int, int> [n + 1];
	dp [0] = {0, 0};
	for (int i = 1 ; i < n + 1 ; i ++)
	{
		int last_index = -1;
		int maxLenght = -1;
		for (int j = i - 1 ; j > 0 ; j --)
			if (check (i, j))
				if (maxLenght < dp [j].first + 1)
				{
					maxLenght = dp [j].first + 1;
					last_index = j;
//					cout << "Index: " << i << " -> {" << maxLenght << ", " << last_index << "}\n";
				}

		if (maxLenght < 1)
		{
			maxLenght = 1;
			last_index = 0;
		}

		dp [i] = {maxLenght, last_index};
	}
//------------------End of init DP------------------
	
//	cout << "  Input: ";
//	for (int i = 0 ; i < n + 1 ; i ++)
//		cout << setw (3) << input [i] << " ";
//	cout << "\n";
//	cout << "MaxLens: ";
//	for (int i = 0 ; i < n + 1 ; i ++)
//		cout << setw (3) << dp [i].first << " ";
//	cout << "\n";
//	cout << "PrevInd: ";
//	for (int i = 0 ; i < n + 1 ; i ++)
//		cout << setw (3) << dp [i].second << " ";
//	cout << "\n";
//	cout << dp [n].first << "\n";
	int ANS = -1;
	for (int i = 0 ; i < n + 1 ; i ++)
		ANS = max (ANS, dp [i].first);
	cout << ANS << "\n";
	delete[] input;
	delete[] dp;
}
