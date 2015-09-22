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
char ind = '0';

void rec (int x, int y)
{
	 map [x][y] = ind;
	 for (int i = 0 ; i < (int)(sizeof (X)/sizeof (int)) ; i ++)
	 {
		if (x + X [i] >= 0 and x + X [i] < n and y + Y [i] >= 0 and y + Y [i] < m and map [x + X [i]][y + Y [i]] == '#')
		{
			rec (x + X [i], y + Y [i]);
		}
	 }
}

int main ()
{
	 cin >> n >> m;
	 map = new char* [n];
	 for (int i = 0 ; i < n ; i ++)
	 {
		  map [i] = new char [m];
		  for (int j = 0 ; j < m ; j ++)
			   cin >> map [i][j];
	 }
	 for (int i = 0 ; i < n ; i ++)
		  for (int j = 0 ; j < m ; j ++)
			   if (map [i][j] == '#')
			   {
				    rec (i, j);
				    ind ++;
			   }
	 for (int i = 0 ; i < n ; i ++, cout << "\n")
		  for (int j = 0 ; j < m ; j ++)
			   cout << map [i][j];
	 
}
