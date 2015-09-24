#include <iostream> // cin, cout
#include <vector>   // vector
#include <string>   // string
#include <stdlib.h> // exit

using namespace std;

int path_counter = 0;
string curr_path;

         int Y [] = { 1 , 0 ,-1 , 0 };
         int X [] = { 0 , 1 , 0 ,-1 };
char character [] = {'R','D','L','U'};

char** map;
int n, m;

void rec (int x, int y)
{
	if (map [x][y] == 'e')
	{ 
		path_counter ++;
		cout << curr_path << "\n";
		//for (int i = 0 ; i < n ; i ++, cout << "\n")
		//	for (int j = 0 ; j < m ; j ++)
		//		cout << map [i][j];
		//exit (0);
		return;
	}
	char val = map [x][y];
	map [x][y] = '@';
	for (int i = 0 ; i < (int)(sizeof (X)/sizeof (int)) ; i ++)
	{
		if (x + X [i] >= 0 and x + X [i] < n and y + Y [i] >= 0 and y + Y [i] < m and map [x + X [i]][y + Y [i]] != '*' and map [x + X [i]][y + Y [i]] != '@')
		{
			curr_path += character [i];
			rec (x + X [i], y + Y [i]);
			curr_path.pop_back ();
		}
	}
	map [x][y] = val;
}

int main ()
{
	cin >> n >> m;
	int sx, sy;
	map = new char* [n];
	for (int i = 0 ; i < n ; i ++)
	{
		map [i] = new char [m];
		for (int j = 0 ; j < m ; j ++)
		{
			cin >> map [i][j];
			if (map [i][j] == 's')
				sx = i, sy = j;
		}
	}
	rec (sx, sy);
	cout << "Total paths found: " << path_counter << "\n";
}
