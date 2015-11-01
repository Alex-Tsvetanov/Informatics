#include <iostream> // cin, cout
#include <map>      // map

using namespace std;

int path_counter = 0;

         int Y [] = { 1 , 0 ,-1 , 0 };
         int X [] = { 0 , 1 , 0 ,-1 };
char character [] = {'R','D','L','U'};

char** Map;
int n, m;
int ind = 0;

map < char, int > ans;

void rec (int x, int y)
{
	 char c = Map [x][y];
	 Map [x][y] = '#';
	 for (int i = 0 ; i < (int)(sizeof (X)/sizeof (int)) ; i ++)
	 {
		if (x + X [i] >= 0 and x + X [i] < n and y + Y [i] >= 0 and y + Y [i] < m and Map [x + X [i]][y + Y [i]] == c)
		{
			rec (x + X [i], y + Y [i]);
		}
	 }
}

int main ()
{
	 cin >> n >> m;
	 Map = new char* [n];
	 for (int i = 0 ; i < n ; i ++)
	 {
		  Map [i] = new char [m];
		  for (int j = 0 ; j < m ; j ++)
			   cin >> Map [i][j];
	 }
	 for (int i = 0 ; i < n ; i ++)
		  for (int j = 0 ; j < m ; j ++)
			   if (Map [i][j] != '#')
			   {
				    ans [Map [i][j]] ++;
				    rec (i, j);
				    ind ++;
			   }
	 cout << "Areas: " << ind << "\n";
	 for (auto& x : ans)
		  cout << "Letter \'" << x.first << "\' -> " << x.second << "\n";;
	 
}
