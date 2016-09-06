#include <iostream>
#include <utility>

using namespace std;

//    pos  num
pair <int, int> Find (const int* arr, const int n) // O (n)
{
	int pos = 0;
	for (int i = 0 ; i < n ; i ++)
	{
		if (arr [pos] > arr [i])
			pos = i;
	}
	return {pos, arr [pos]};
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
