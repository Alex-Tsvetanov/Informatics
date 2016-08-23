#include <iostream>

using namespace std;

#include "structuring.hpp"
course arr [9];

int main ()
{
	int n = 9;
	clog << "Courses:\n";
	for (int i = 0 ; i < n ; i ++)
	{
		int day, ind, theme, level;
		cin >> day >> ind >> theme >> level;
		arr [i] = course (day, ind, theme, level);
	}
	clog << "Желения:\n";
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		int ind1, ind2;
		cin >> ind1 >> ind2;
		cout << possibility::by_time (arr [ind1], arr [ind2]) + possibility::by_time (arr [ind1], arr [ind2]) << "+";
	}
}
