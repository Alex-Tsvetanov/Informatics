#include <iostream>
#include <set>

using namespace std;

set < int > row, col, diagMain, diagSec;
bool map [8][8];

int ans (int n = 0)
{
	//cout << n << endl;
	//for (auto& f : map)
	//{
	//	for (auto& c : f)
	//		cout << c << " ";
	//	cout << endl;
	//}
	//cout << "------------------------------" << endl;

	if (n == 8)
		return 1;
	int localAns = 0;

	for (auto& y : row)
	{
		for (auto& x : col)
		{
			//cout << "(" << y << ", " << x << ")\n";
			if (diagSec.find (y + x) != diagSec.end () and diagMain.find (y - x) != diagMain.end ())
			{
				map [x][y] = 1;
				//cout << "Set on the map ----- Sucssesful" << endl;
				row.erase (row.find (y));
				//cout << "Erase from the rows' set ----- Sucssesful" << endl;
				col.erase (col.find (x));
				//cout << "Erase from the cols' set ----- Sucssesful" << endl;
				//cout << "Main diagonals' set numbers: ";
				//for (auto& f : diagMain)
				//	cout << f << " ";
				//cout << endl;
				diagMain.erase (diagMain.find (y - x));
				//cout << "Erase from the main diagonals' set ----- Sucssesful" << endl;
				diagSec.erase (diagSec.find (y + x));
				//cout << "Erase from the secondary diagonals' set ----- Sucssesful" << endl;
				localAns += ans (n + 1);
				diagMain.insert (y - x);
				diagSec.insert (y + x);
				row.insert (y);
				col.insert (x);
			}
		}
	}
	
	return localAns;
}

int main ()
{
	for (int i = 0 ; i < 8 ; i ++)
	{
		row.insert (i);
		col.insert (i);
	}
	for (int i = -7 ; i < 8 ; i ++)
	{
		diagMain.insert (i);
		diagSec.insert (i);
	}
	cout << ans () << endl;
}
