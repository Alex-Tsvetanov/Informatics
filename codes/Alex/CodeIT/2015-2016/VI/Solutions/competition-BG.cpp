#include <fstream>
#include <iomanip>
#include <stdio.h>

using namespace std;

ifstream fin ("competition.in");
FILE* pFile = fopen ("competition.out","w");

int main ()
{
	int p1, p2, p3;
	fin >> p1 >> p2 >> p3;
	int mark = (p1 * 1 + p2 * 2 + p3 * 3);
	double ans = (double)0.0;
	if (mark < 60) ans = 2.00f;
	else if (mark >= 120) ans = 6.00f;
	else ans = (double)0.05 * (double)(mark);
	fprintf (pFile, "%.2f\n", ans);
	fclose (pFile);
}
