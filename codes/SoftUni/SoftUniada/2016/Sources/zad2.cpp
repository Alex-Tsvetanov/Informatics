#include <iostream>

using namespace std;

int main ()
{
	int n;
	cin >> n;
	for (int i = 0 ; i < n - 1 ; i ++)
	{
		bool draw = false;
		for (int j = 0 ; j < 2 * n - 1 ; j ++)
		{
			if (j == n - i - 1)
			{
				cout << "*";
				draw = true;
			}
			if (j == n + i - 1)
			{
				if (n + i - 1 != n - i - 1)
					cout << "*";
				draw = false;
			}
			if (j != n + i - 1 and j != n - i - 1 and draw)
				cout << " ";
			if (j != n + i - 1 and j != n - i - 1 and !draw)
				cout << ".";
		}
		cout << "\n";
	}
	for (int i = 0 ; i < n - 1 ; i ++)
		cout << "* ";
	cout << "*";
	cout << "\n";

	for (int i = 0 ; i < n ; i ++)
	{
		cout << ((i == 0 or i == n - 1)?'+':'|');
		for (int j = 0 ; j < 2 *(n - 1) - 1 ; j ++)
		{
			cout << ((i == 0 or i == n - 1)?'-':' ');
		}
		cout << ((i == 0 or i == n - 1)?'+':'|');
		cout << "\n";
	}

}
