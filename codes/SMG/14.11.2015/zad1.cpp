#include <iostream>
#include <set>
#define forDigit(ind) for (int ind = 0 ; ind < 4 ; ind ++)

using namespace std;

int genNum (int a, int b)
{
	return a*10+b*1;
}

int main ()
{
	int a [4];
	for (int i = 0 ; i < 4 ; i ++)
		cin >> a [i];
	set < int > allNums;
	forDigit (ind1)
		forDigit (ind2)
			if (ind1 != ind2)
				allNums.insert (genNum (a [ind1], a [ind2]));
	int prev = 0;
	unsigned Y = 0, X = -1;

	for (auto& x : allNums)
	{
		if (x - prev < X - Y)
			X = x, Y = prev;
		prev = x;
	}

	if (X == -1 and Y == 0)
		cout << "No answer\n";
	else if (Y == 0)
		cout << "No 2 different numbers\n";
	else
		cout << X - Y << "\n";
//	cout << "Different numbers: " << allNums.size () << "\n";
}
