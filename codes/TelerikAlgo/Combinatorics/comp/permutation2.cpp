#include <iostream>
#include <stdlib.h>

using namespace std;

int arr [20];
bool visited [20];

int main ()
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


	long long fact = 1;
	for (int i = 2 ; i < n ; i ++)
		fact *= i;

//	cout << fact << "\n";

	long long ans = 1;

	for (int i = 0 ; i < n - 1 ; i ++)
	{
		int first_mul = arr [i] - 1;
		for (int j = 1 ; j < arr [i] ; j ++)
			if (visited [j] == 1)
				first_mul --;
		ans += first_mul * fact;
//		cout << "adding: " << first_mul << " * " << fact << " = " << first_mul * fact << "\n";
		fact /= (n - i - 1);
		visited [arr [i]] = 1;
	}
	cout << ans << "\n";
}
