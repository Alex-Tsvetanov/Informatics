#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>

using namespace std;

int arr [20];

int main()
{
	string input;
	getline (cin, input);
	input += " ";

	string currNum = "";
	int n = 0;

	for (int i = 0 ; i < (int)input.size () ; i ++)
	{
		if (input [i] == ' ')
		{
			arr [n ++] = atoi (currNum.c_str ());
			currNum = "";
		}
		else
			currNum += input [i];
	}
////cout << n << "\n";
////for (int i = 0 ; i < n ; i ++)
////	cout << arr [i] << " ";
////cout << "\n";
	
	int k = 0;

	do
	{
		k ++;
	}
	while (prev_permutation (arr, arr + n));
	cout << k << "\n";
}
