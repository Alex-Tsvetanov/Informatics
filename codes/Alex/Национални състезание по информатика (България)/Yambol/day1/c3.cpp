#include <iostream>
#include <vector>

using namespace std;

bool knapsack [1024];

int main ()
{
	int a, b, c;
	cin >> a >> b >> c;
	
	vector <int> w;
	if (a != 0 and b != 0 and c != 0)
		w = {a, b, c, abs (a - b), abs (b - c), abs (a - c)};
	else if (a != 0 and b != 0)
		w = {a, b, abs (a - b)};
	else if (a != 0 and c != 0)
		w = {a, c, abs (a - c)};
	else if (c != 0 and b != 0)
		w = {c, b, abs (c - b)};
	else if (a != 0)
		w = {a};
	else if (b != 0)
		w = {b};
	else if (c != 0)
		w = {c};
	else
		w = {};

	knapsack [0] = true;
	for (auto& x : w)
	{
		for (int i = 1023 - x ; i >= 0 ; i --)
			if (knapsack [i] == true)
				knapsack [i + x] = true;
	}

	int sum = 0;
	for (int i = 1 ; i < 1024 ; i ++)
		sum += knapsack [i];
	cout << sum << "\n";
}
