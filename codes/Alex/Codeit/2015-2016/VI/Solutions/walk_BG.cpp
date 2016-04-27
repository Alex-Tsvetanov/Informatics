#include <fstream>
#include <vector>
#include <cmath>
#include <stdio.h>

using namespace std;

ifstream fin ("walk.in");
FILE* pFile = fopen ("walk.out","w");

int main ()
{
	int n, k;
	fin >> n >> k;
	vector < int > in;
	for (int i = 0 ; i < n ; i ++)
	{
		int h;
		fin >> h;
		in.push_back (h);
	}
	int ans = 2925 * n;
	int curr = 0;
	for (int j = 1 ; j < k ; j ++)
	{
		curr += abs (in [j] - in [j - 1]);
	}
	ans = min (ans, curr);
	for (int i = 1 ; i <= n - k ; i ++)
	{
		curr -= abs (in [i] - in [i - 1]);
		curr += abs (in [i + k - 1] - in [i  + k - 2]);
		ans = min (ans, curr);
	}
	fprintf (pFile, "%d\n", ans);
	fclose (pFile);
}
