#include <stdio.h>
#include <iostream>
#include <random> //C++11

using namespace std;

void printArray (int* arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr [i] << " ";
	cout << "\n";
}

void randomize (int* arr, int n)
{
	std::random_device rd;
	std::mt19937 gen (rd());
	for (int i = n - 1 ; i > 0 ; i --)
	{
		std::uniform_int_distribution<> dis (0, i - 1);
		int j = dis (gen);

		swap (arr[i], arr[j]);
	}
}

int main()
{
	int n;
	cin >> n;
	int* arr = new int [n];
	for (int i = 0 ; i < n ; i ++)
		cin >> arr [i];
	randomize  (arr, n);
	printArray (arr, n);
}

