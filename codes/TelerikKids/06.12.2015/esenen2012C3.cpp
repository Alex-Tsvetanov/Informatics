#include <iostream>
#include <iomanip>
//#include <stdio.h>

using namespace std;
                        //  L R . X  Value
int input [1024][1024]; //  1 2 4 16 32 * v

int dp [1024][1024];
int from [1024][1024];

const int up = 1;
const int up_right = 2;
const int up_left = 3;

bool can (int input, int arrow)
{
	if (arrow == 6)
		return (input == 16);
	if (arrow == 5)
		return (input == 16);
	if (arrow == 4 and input == 16)
		return true;
	if (input == 16)
		return false;
	return ((input & arrow) == arrow);
}

int main ()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0 ; i < n ; i ++)
		for (int j = 0 ; j < m ; j ++)
		{
			char a;
			cin >> a;
			if (a == 'L')
				input [i][j] = 1;
			else if (a == 'R')
				input [i][j] = 2;
			else if (a == '.')
				input [i][j] = 4;
			else if (a == 'X')
				input [i][j] = 16;
			else
				input [i][j] = 4 + 32 * (a - '0');
		}
//-----------------------------End of input--------------------------------

//--------------Starting Make Dynamic Programming method-------------------
	dp [0][0] = (input [0][0] / 32);
	for (int i = 1 ; i < n ; i ++)
		dp [i][0] =	dp [i - 1][0] * can (input [i - 1][0], 4) + (input [i][0] / 32);
	for (int i = 1 ; i < m ; i ++)
		dp [0][i] = dp [0][i - 1] * can (input [0][i - 1], 1) + (input [0][i] / 32);
	for (int i = 1 ; i < n ; i ++)
		for (int j = 1 ; j < m ; j ++)
		{
			int to_add = 0;
			if (
					(can (input [i - 1][j], 4))// and is_visible [i - 1][j])
					or
					(can (input [i - 1][j - 1], 6))// and is_visible [i - 1][j - 1])
			   )
				to_add = (input [i][j] / 32);
			else if (j + 1 < m)
			{
				if (can (input [i - 1][j + 1], 5))
					to_add = (input [i][j] / 32);
				else
					continue;
			}
			else
				continue;

			int from_up = dp [i - 1][j] * can (input [i - 1][j], 4);
			int from_up_left = dp [i - 1][j - 1] * can (input [i - 1][j - 1], 6);
			int from_up_right; 
			if (j + 1 < m)
				from_up_right = dp [i - 1][j + 1] * can (input [i - 1][j + 1], 5);
			else
				from_up_right = 0;
			
			from_up += to_add;
			from_up_left += to_add;
			from_up_right += to_add;

			int MAX = max (from_up, max (from_up_left, from_up_right));
			if (MAX == from_up_right)
				from [i][j] = up_right; 
			if (MAX == from_up_left)
				from [i][j] = up_left;
			if (MAX == from_up)
				from [i][j] = up;
			dp [i][j] = MAX;
			//cout << i << " " << j << " " << from_up << " " << from_up_left << " " << from_up_right << " " << MAX << "\n";
		}
//-----------------End of Make Dynamic Programming method-------------------
	int col = 0;
	for (int i = 0 ; i < m ; i ++)
		if (dp [n - 1][col] < dp [n - 1][i])
			col = i;
	string a;
	int i = n - 1, j = col;
	while (from [i][j] != 0)
	{
		if (from [i][j] == up)
		{
			a += "D";
			i --;
		}
		else if (from [i][j] == up_right)
		{
			a += "L";
			i --;
			j ++;
		}
		else if (from [i][j] == up_left)
		{
			a += "R";
			i --;
			j --;
		}
	}
	cout << j + 1 << endl;
	cout << dp [n - 1][col] << endl;
	for (int k = a.size () - 1 ; k >= 0 ; k --)
		cout << a [k];
	cout << endl;

	cout << "Input: \n";
	for (int i = 0 ; i < n ; i ++, cout << "\n")
		for (int j = 0 ; j < m ; j ++)
		{
			char A;
			if (input [i][j] == 1) A = 'L';
			else if (input [i][j] == 2) A = 'R';
			else if (input [i][j] == 4) A = '.';
			else if (input [i][j] == 16) A = 'X';
			else A = (input [i][j] - 4) / 32 + '0';
			cout << setw (4) << A << " ";
		}
	cout << "Input: \n";
	for (int i = 0 ; i < n ; i ++, cout << "\n")
		for (int j = 0 ; j < m ; j ++)
			cout << setw (4) << input [i][j] << " ";
	cout << "DP: \n";
	for (int i = 0 ; i < n ; i ++, cout << "\n")
		for (int j = 0 ; j < m ; j ++)
			cout << setw (4) << dp [i][j] << " ";
}
