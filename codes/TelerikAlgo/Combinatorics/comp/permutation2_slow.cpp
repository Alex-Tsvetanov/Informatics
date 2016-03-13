#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <sstream>

using namespace std;

int arr [20];

int main ()
{
	string input;
	getline (cin, input);
	input += " ";
	
	int n = 0;

	for (int i = 0 ; i < (int)input.size () ; i ++)
		if (input [i] == ' ')
			n ++;
	
	for (int i = 0 ; i < n ; i ++)
		arr [i] = i + 1;
	int k = 0;
	do
	{
		k ++;
		stringstream ss;
		for (int i = 0 ; i < n ; i ++)
			ss << arr [i] << " ";
		if (ss.str () == input)
		{
			cout << k << endl;
			return 0;
		}
	} while (next_permutation (arr, arr + n));

	return 0;
//	cout << n << "\n";
//	for (int i = 0 ; i < n ; i ++)
//		cout << arr [i] << " ";
//	cout << "\n";


	long long fact = 1;
	for (int i = 2 ; i < n ; i ++)
		fact *= i;

//	cout << fact << "\n";

	long long ans = 1;

	for (int i = 0 ; i < n - 1 ; i ++)
	{
		ans += (arr [i] - i - 1) * fact;
		cout << "adding: " << (arr [i] - i - 1) << " * " << fact << " = " << (arr [i] - i - 1) * fact << "\n";
		fact /= (n - i - 1);
	}
	cout << ans << "\n";
}
/*
1 2 3 4 5 = 0 + 0 + 0 + 0 + 0
1 2 3 5 4 = 0 
*/
