#include <iostream>
#include <utility>

using namespace std;

//    pos  num
pair <int, int> Find (const int* arr, const int n) // O (n)
{
	int left = 0, right = n - 1;
	while (right - left > 1)
	{
		int mid = (right + left) / 2;
		if (arr [mid] > arr [right])
			left = mid;
		else
			right = mid;
	}
	return {right, arr [right]};
}

int main ()
{
	int n;
	cin >> n;
	int* arr = new int [n];
	for (int i = 0 ; i < n ; i ++)
		cin >> arr [i];

	auto x = Find (arr, n);
	cout << x.first << " " << x.second << "\n";
}
