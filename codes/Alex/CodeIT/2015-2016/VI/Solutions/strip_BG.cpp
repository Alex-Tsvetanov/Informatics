#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>

using namespace std;

ifstream fin ("strip.in");
FILE* pFile = fopen ("strip.out","w");

int main ()
{
	int n;
	fin >> n;
	vector < int64_t > in;
	vector < int64_t > dp;
	int64_t sum = 0;
	for (int i = 0 ; i < n ; i ++)
	{
		int h;
		fin >> h;
		in.push_back (h);
		sum += h;
		dp.push_back (sum);
	}
	int B = 0;
	for (int i = 0 ; i < n - 1 ; i ++)
	{
		if (dp [i] + dp [i + 1] > dp [B] + dp [B + 1])
			B = i;
	}
	int A = min_element (dp.begin (), dp.begin () + B) - dp.begin ();
	int C = min_element (dp.begin () + B + 1, dp.end ()) - dp.begin ();
	fprintf (pFile, "%d %d %d\n", A + 1, B + 1, C + 1);
	fclose (pFile);
}
