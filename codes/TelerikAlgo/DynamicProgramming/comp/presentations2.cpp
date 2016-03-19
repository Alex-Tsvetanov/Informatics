#include <iostream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

using namespace std;

	int money [1000];
	int Time [1000];
//	int knapsack [1000];
	int MAX = -1;
	int n, h, k;

	clock_t now;
	clock_t start;
void rec (int s, int presentations, int total_time, int sum)
{
	now = clock ();
	double sec = ((float)(now - start)) / CLOCKS_PER_SEC;
	if (sec > 0.18f)
	{
		cout << MAX << endl;
		exit (0);
	}
	if (total_time > h)
		return ;
	if (presentations > k)
		return ;
	MAX = max (MAX, sum);
	for (int i = s + 1 ; i < n ; i ++)
		rec (i, presentations + 1, total_time + Time [i], sum + money [i]);
}

int main ()
{
	start = clock();
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	cin >> n >> h >> k;

	for (int i = 0 ; i < n ; i ++)
		cin >> Time [i];
	for (int i = 0 ; i < n ; i ++)
		cin >> money [i];
/*	knapsack [0] = 0;
	int diff = -1;
	for (int i = 0 ; i < n ; i ++)
	{
		if (i != diff)
		{
			for (int j = h ; j >= 0 ; j --)
				if (j + time [i] <= h)
				if (knapsack [j + time [i]] < knapsack [i] + money [i])
					knapsack [j + time [i]] = knapsack [j] + money [i];
		}
	}
	cout << *max_element (knapsack, knapsack + h + 1) << "\n";
*/
	rec (-1, 0, 0, 0);
	cout << MAX << "\n";
}
