#include <iostream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

using namespace std;

	int money [1000];
	int Time [1000];
	int knapsack [1000];
	int n, h, k;

int main ()
{
	//start = clock();
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	cin >> n >> h >> k;
//	h *= 2;

	for (int i = 0 ; i < n ; i ++)
		cin >> Time [i];
	for (int i = 0 ; i < n ; i ++)
		cin >> money [i];
	knapsack [0] = 0;
	for (int i = 0 ; i < n ; i ++)
	{
		for (int j = h ; j >= 0 ; j --)
			if (knapsack [j + Time [i]] <= h)
			if (knapsack [j + Time [i]] < knapsack [i] + money [i])
				knapsack [j + Time [i]] = knapsack [j] + money [i];
	}
	cout << *max_element (knapsack, knapsack + 1000) << "\n";

//	rec (-1, 0, 0, 0);
//	cout << MAX << "\n";
}
