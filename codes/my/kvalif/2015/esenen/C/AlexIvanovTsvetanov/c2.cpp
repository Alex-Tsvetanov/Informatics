#include <iostream>
#include <set>

using namespace std;

set < int > nextDigit [10]; // 0 - fail

//int ansForLeft [21][11];

int counterFunction (int leftDigits, int last = -1)
{
	//if (ansForLeft [leftDigits][last + 1] != 0)
	//	return ansForLeft [leftDigits][last + 1];
	if (leftDigits == 1)
	{
		if (last == -1)
			return 0;
		else
			return nextDigit [last].size ();
	}
	if (leftDigits == 0)
		return 1;

	int ans = 0;
	if (last == -1)
		for (int i = 1 ; i < 10 ; i ++)
			ans += counterFunction (leftDigits - 1, i);
	else
		for (set <int>::iterator it = nextDigit [last].begin () ; it != nextDigit [last].end () ; it ++)
			ans += counterFunction (leftDigits - 1, *it);

	return ans; //(ansForLeft [leftDigits][last + 1] = ans);
}

int main ()
{
	int n, d [3];
	cin >> n >> d [0] >> d [1] >> d [2];

	for (int j = 0 ; j < 3 ; j ++)
		for (int i = 1 ; i * d [j] < 100 ; i ++)
			if ((i * d [j]) / 10 != 0)
				nextDigit [(i * d [j]) / 10].insert ((i * d [j]) % 10);

	cout << counterFunction (n) << "\n";
}
