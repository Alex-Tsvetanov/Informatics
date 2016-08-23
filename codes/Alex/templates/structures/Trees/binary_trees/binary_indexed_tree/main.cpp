#include <iostream>
#include <vector>
#include <iomanip>
#define ever (;;)

using namespace std;

#include "binary_indexed_tree.hpp"

int max (int a, int b)
{
	return (a < b)?b:a;
}

int main ()
{
	int arr [] = {1,5,82,7,93,4,8,5,6798};
	BIT <int> bit (arr + 0, arr + 9, max);
//	for ever
	while (cin)
	{
		int a, b;
		cin >> a >> b;
		cout << bit (a, b) << "\n";
		cout.flush ();
	}
}
