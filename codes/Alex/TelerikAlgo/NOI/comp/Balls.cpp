#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool ans [100001];
set < int > steps;
bool have_1 = false;
int mem [100001];

int solve (int n)
{
	if (mem [n] != 0)
		return mem [n];

	//for (auto& x : steps)
	for (auto& x : steps)
	{
		if (n - x < 0)
			continue;
		if (n - x == 0)
			return 1;
		if (n - x > 0 and solve (n - x) == 2)
		{
			mem [n] = 1;
			return 1;
		}
	}
	mem [n] = 2;
	return 2;
}

int main ()
{
////steps = {1, 3, 4};
////have_1 = true;
////cout << solve (1, 'H', 'M') << endl;
////cout << solve (2, 'M', 'H') << endl;
////have_1 = false;
////steps = {};
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	//input
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		int a;
		cin >> a;
		if (a == 1)
			have_1 = true;
		steps.insert (a);
	}
	int a, b;
	cin >> a >> b;
	ans [0] = 0;
	for (int i = 1 ; i <= b ; i ++)
	{
		ans [i] = 0;
		for (int j : steps)
		{
			if (i - j >= 0)
				if (!ans [i - j])
				{
					ans [i] = 1;
					break;
				}
		}
	}
	int total_number = 0;
	for (int i = a ; i <= b ; i ++)
	{
		//cout << i << " -> " << solve (i, 'M', 'H') << endl;
		total_number += (ans [i] == 1);
	}
	cout << total_number << "\n";
}
