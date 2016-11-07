#include <iostream>

using namespace std;

int main ()
{
	int n;
	cin >> n;
	int* arr = new int [n];
	int* ans = new int [n];
	for (int i = 0 ; i < n ; i ++)
	{
		cin >> arr [i];
		ans [i] = 0.0f/0.0f;
		for (int j = i - 1 ; j >= 0 ; j --)
		{
			if (arr [j] < arr [i])
			{
				ans [i] = j;
				break;
			}
		}
	}
	for (int i =  0 ; i < n ; i ++)
		cout << ans [i] << " ";
	cout << std::endl;
	delete[] arr;
	delete[] ans;
}
