#include <iostream>
#include <utility>

using namespace std;

int n, m;
int* input;
//    MaxLen     индекс
//      до         на
//	  индекс    предишния
//      i        елемент
pair <  int,      int   >* dp;

bool check (int ind1, int ind2)
{
	if (ind2 == 0 or ind1 == 0)
		return true;
	return ((-m <= (input [ind1] - input [ind2])) and ((input [ind1] - input [ind2]) <= m));
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
			if (check (i, dp [j].second))
				if (maxLenght < dp [j].first)
				{
					maxLenght = dp [j].first + 1;
					last_index = i;
				}

		if (maxLenght < 1)
		{
			maxLenght = 1;
			last_index = i;
		}
		if (maxLenght < dp [i - 1].first)
		{
			maxLenght = dp [i - 1].first;
			last_index = dp [i - 1].second;
		}

		dp [i] = {maxLenght, last_index};
	}
//------------------End of init DP------------------
	cout << dp [n].first << "\n";
}
