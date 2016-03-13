#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
	int n;
	cin >> n;
	int sum = 0;
	int* arr = new int [n];
	for (int i = 0 ; i < n ; i ++)
	{
		cin >> arr [i];
		sum += arr [i];
	}
	vector < size_t >* knapsack = new vector <size_t> [sum / 2 + 1];
	set < int, greater <int>, allocator <int> > visitedSums = {0};
	cout << "Input & Init\n";
	for (int i = n - 1 ; i >= 0 ; i --)
		for (auto& x : visitedSums)
		{
			if (x + arr [i] <= sum / 2 and knapsack [x + arr [i]].empty ())
			{
				knapsack [x + arr [i]] = knapsack [x];
				knapsack [x + arr [i]].push_back (i);
				visitedSums.insert (x + arr [i]);
			}
		}
	cout << "Before Sort\n";
	set < int >::iterator endIt = visitedSums.begin ();
//	endIt --;
	int Max = *endIt;
	int Alan = 0, bob = sum;
	for (auto& x : knapsack [Max])
	{
		Alan += arr [x];
		bob -= arr [x];
	}
	cout << "Difference: " << abs (Alan - bob) << "\n";
	cout << "Alan:" << Alan << " Bob:" << bob << "\n";
	cout << "Alan takes: ";
	for (auto& x : knapsack [Max])
		cout << arr [x] << " ";
	cout << "\n";
	cout << "Bob takes the rest." << endl;
}
