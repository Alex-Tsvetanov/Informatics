#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>

using namespace std;

#include <string.h>

int kmp_search(const char *text, const char *pattern)
{
	int ans = 0;
	int* T;
	int i, j;

	if (pattern [0] == '\0')
		return strlen (text);

	/* Construct the lookup table */
	T = new int [strlen (pattern) + 1];
	T[0] = -1;
	for (i=0; pattern[i] != '\0'; i++) {
		T[i+1] = T[i] + 1;
		while (T[i+1] > 0 and pattern[i] != pattern[T[i+1]-1])
			T[i+1] = T[T[i+1]-1] + 1;
	}

	/* Perform the search */
	for (i=j=0; text[i] != '\0'; ) {
		if (j < 0 or text[i] == pattern[j]) {
			++i, ++j;
			if (pattern[j] == '\0') {
				ans ++;
			}
		}
		else j = T[j];
	}

	free(T);
	return ans;
}


ifstream fin ("string.in");
FILE* pFile = fopen ("string.out","w");

int main ()
{
	string A, B, C, R;
	int k;
	fin >> A >> B >> R >> C >> k;
	int in_A = kmp_search (A.c_str (), C.c_str ());
	int in_B = kmp_search (B.c_str (), C.c_str ());
	int in_next;
	int XinR = kmp_search (R.c_str (), "X");
	int YinR = kmp_search (R.c_str (), "Y");

	cout << in_A << "\n";
	cout << in_B << "\n";
	cout << XinR << "\n";
	cout << YinR << "\n";
	for (int i = 0 ; i < k - 2 ; i ++)
	{
		in_next = XinR * in_A + YinR * in_B;
		cout << in_next << "\n";
		in_A = in_B;
		in_B = in_next;
	}
	if (k == 1)
		fprintf (pFile, "%d\n", in_A);
	else if (k == 2)
		fprintf (pFile, "%d\n", in_B);
	else
		fprintf (pFile, "%d\n", in_next);
	fclose (pFile);
}
