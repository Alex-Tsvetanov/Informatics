#include <iostream>
#define forDigit(ind) for (int ind = 0 ; ind < 4 ; ind ++)

using namespace std;

inline int genNum (int a, int b)
{
	return a*10+b*1;
}

int main ()
{
	int a [4];
	for (int i = 0 ; i < 4 ; i ++)
		cin >> a [i];
	unsigned Y = 0, X = -1;
	forDigit (ind1)
		forDigit (ind2)
	forDigit (ind3)
		forDigit (ind4)
			if (ind1 != ind2 and ind1 != ind3 and ind1 != ind4 and ind2 != ind3 and ind2 != ind4 and ind3 != ind4)
				if (
						genNum (a [ind1], a [ind2]) - genNum (a [ind3], a [ind4]) > 0 and 
						genNum (a [ind1], a [ind2]) - genNum (a [ind3], a [ind4]) < X - Y)
					X = genNum (a [ind1], a [ind2]), Y = genNum (a [ind3], a [ind4]);

	if (X == -1 and Y == 0)
		cout << "No answer\n";
	else if (Y == 0)
		cout << "No 2 different numbers\n";
	else
		cout << X - Y << "\n";
//	cout << "Different numbers: " << allNums.size () << "\n";
}
