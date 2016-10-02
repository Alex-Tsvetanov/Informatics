#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
	int n;
	long long k;
	cin >> n >> k;
	int* arr = new int [n];
	for (int i = 0 ; i < n ; i ++)
		arr [i] = i + 1;
	do
	{
		if (k == 1)
		{
			for (int i = 0 ; i < n ; i ++)
				cout << arr [i] << " ";
			cout << "\n";
			return 0;
		}
		else 
			k --;
	} while (next_permutation (arr, arr + n));

	delete[] arr;
}
