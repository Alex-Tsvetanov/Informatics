#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	int n;
	long long k;
	cin >> n >> k;
	k --;
	int* arr = new int [n];
	set <int> all;
	for (int i = 0 ; i < n ; i ++)
	{
		all.insert (i + 1);
	}
	long long fact = 1; 
	for (int i = 2 ; i < n ; i ++)
		fact *= i;	

	int index = 0;

	while (k > 0)
	{
		//for (int i = 0 ; i < n ; i ++)
		//	cout << arr [i] << " ";
		//cout << "\n" << k << "\n-----------------------------\n";
		int IND = 0;
		while (k >= fact)
		{
			k -= fact;
			IND ++;
		}
		//cout << "IND = " << IND << "\n";
		for (auto& x : all)
		{
			if (IND == 0)
			{
				arr [index] = x;
				break;
			}
			else
				IND --;
		}
		all.erase (arr [index]);
		fact /= (n - index - 1);
		index ++;
	}
	for (auto& x : all)
		arr [index ++] = x;
	for (int i = 0 ; i < n ; i ++)
		cout << arr [i] << " ";
	cout << "\n";
	delete[] arr;
}
