#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>

using namespace std;

ifstream fin ("stats.in");
FILE* pFile = fopen ("stats.out","w");
int num [101];

int main ()
{
	int n;
	fin >> n;
	vector < int64_t > in;
	for (int i = 0 ; i < n ; i ++)
	{
		int h;
		fin >> h;
		in.push_back (h);
		num [h] ++;
	}
	sort (in.begin (), in.end ());
	int mid = in [(n + 1) / 2 - 1];
	int mod = max_element (num + 1, num + 101) - num;
	fprintf (pFile, "%d %d\n", mid, mod);
	fclose (pFile);
}
