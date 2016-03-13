#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int map [200][200];
int n, r, k;

void input ();

int* deltaX;
int* deltaY;

void precomputeDataFill ();

set < pair < int, int > > queens;
set < pair < int, int > > optimumQueens;

int checkBattle (int x, int y)
{
	int battles = 0;
	for (int i = 0 ; i < 4 * r ; i ++)
		if (queens.find ({x + deltaX [i], y + deltaY [i]}) != queens.end ())
			battles ++;
	return battles;
}

unsigned long long calc ()
{
	unsigned long long ans = 0;
	for (auto& x : queens)
	{
		vector < int > nums;
		for (int i = 0 ; i < 4 * r ; i ++)
			if (queens.find ({x.first + deltaX [i], x.second + deltaY [i]}) != queens.end ())
				nums.push_back (map [x.first + deltaX [i]][x.second + deltaY [i]]);
		sort (nums.begin (), nums.end ());
		int maxN = 0, currN = 1, sum = ((nums.size () > 1)?nums [0]:0);
		for (int i = 1 ; i < (int)nums.size () ; i ++)
		{
			sum += nums [i];
			if (nums [i] == nums [i - 1])
				currN ++;
			else
			{
				maxN = max (maxN, currN);
				currN = 0;
			}
		}
		ans += sum * maxN;
	}
	return ans;
}

unsigned long long MAX = 0;

void rec (int x, int y, int rememberBattles, bool start = true)
{
//	cout << "Curr pos: " << x << " " << y << "\n";
//	cout << "Queens:\n";
//	for (auto& x : queens)
//		cout << "(" << x.first << ", " << x.second << ")\n";
//	cout << "-------------------------\n";
	bool recursive = false;
	for (int i = x ; i < n ; i ++)
		for (int j = y ; j < n ; j ++)
		{
			if (start and i == x and j == y) continue;

			int x = checkBattle (i, j);
			if (x <= rememberBattles)
			{
				queens.insert (make_pair (i, j));
				rec (i, j, rememberBattles - x, false);
				recursive = true;
				queens.erase (queens.find (make_pair (i, j)));
			}
		}
	if (!recursive)
	{
		unsigned long long curr = calc ();
		if (MAX < curr)
		{
			MAX = curr;
			optimumQueens = queens;
		}
//		for (auto& x : optimumQueens)
//			cout << "(" << x.first << ", " << x.second << ")\n";
//		cout << "----------------------" << endl;
	}
}

int main ()
{
	input ();
	precomputeDataFill ();
	rec (0, 0, k);
	cout << "Answer:\n";
	for (auto& x : optimumQueens)
	{
		cout << x.first << " " << x.second << "\n";
	}
}

void input ()
{
	cin >> n >> r >> k;
	for (int i = 0 ; i < n ; i ++)
		for (int j = 0 ; j < n ; j ++)
			cin >> map [i][j];
}

void precomputeDataFill ()
{
	deltaX = new int [4 * r];
	deltaY = new int [4 * r];
	for (int i = 0 ; i < r ; i ++)
	{
		deltaX [4 * i + 0] = i; deltaY [4 * i + 0] = 0;
		deltaX [4 * i + 1] =-i; deltaY [4 * i + 1] = 0;
		deltaX [4 * i + 2] = 0; deltaY [4 * i + 2] = i;
		deltaX [4 * i + 3] = 0; deltaY [4 * i + 3] =-i;
	}
}
