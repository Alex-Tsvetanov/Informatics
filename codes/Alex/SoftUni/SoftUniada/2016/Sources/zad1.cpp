#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
	int a [4];
	int sum = 0;
	for (int i = 0 ; i < 4 ; i ++)
	{
		cin >> a [i];
		sum += a [i];
	}
	sort (a + 0, a + 4);

	for (int i = 0 ; i < 4 ; i ++)
		if (a [i] == sum - a [i])
		{
			cout << "Yes\n" << a [i] << "\n";
			return 0;
		}

	for (int i = 0 ; i < 4 ; i ++)
	for (int j = i + 1 ; j < 4 ; j ++)
		if (a [i] + a [j] == sum - a [i] - a [j])
		{
			cout << "Yes\n" << a [i] + a [j] << "\n";
			return 0;
		}

	cout << "No\n";

}
