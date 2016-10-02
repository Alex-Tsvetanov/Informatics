//Binary search - Delian Pirinki - 28-08-2016i - Slow
#include <iostream>

using namespace std;

int arr [100000];

int main ()
{
	int n;
	cin >> n;
	
	for (int i = 0 ; i < n ; i ++)
	{
		cin >> arr [i];
	}
	
	if (n == 1)
	{
		cout << "0" << "\n";
	}

	if (n == 2)
	{
		if (arr [0] < arr [1])
			cout << "1" << "\n";
		else if (arr [0] >= arr [1])
			cout << "0" << "\n";
	}

	for (int i = 1 ; i < n - 1 ; i ++)
	{
		if (arr [i - 1] < arr [i] and arr [i] < arr [i + 1])
		{
			cout << i << "\n";
			return 0;
		}
	}
	cout << -1 << "\n";
	return 0;
}
