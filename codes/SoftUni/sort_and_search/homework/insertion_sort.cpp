#include <iostream>

using namespace std;

void insertion_sort (int* arr, int length)
{
	int j, temp;

	for (int i = 0 ; i < length; i++)
	{
		j = i;

		while (j > 0 && arr[j] < arr[j-1])
		{
			temp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = temp;
			j--;
		}
	}
}

int main ()
{
	int* arr;
	int n;
	cin >> n;
	arr = new int [n];
	for (int i = 0 ; i < n ; i ++)
		cin >> arr [i];
	insertion_sort (arr, n);
	for (int i = 0 ; i < n ; i ++)
		cout << arr [i] << " ";
	cout << "\b\n";
}
