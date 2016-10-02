#include <fstream>
#include <random>
#include <algorithm>

using namespace std;

const int Max = ((unsigned int)(-1)) / 2;
const int Min = 0;//-(((unsigned int)(-1)) / 2 - 5);

int arr [10000];

int my_random (int a, int b)
{
	random_device rnd;
	mt19937 mt (rnd ());
	uniform_int_distribution <int> u (a, b);
	return u (mt);
}

int main (int argn, char** argv)
{
	ofstream fin (argv [1]);
	ofstream fout (argv [2]);
	int n = my_random (5, 10000);
	fin << n << "\n";
	for (int i = 0 ; i < n ; i ++)
		arr [i] = my_random (Min, Max);
	int k = my_random (1, n - 2);
	sort (arr, arr + k, less <int> ());
	sort (arr + k + 1, arr + n, greater <int> ());
	for (int i = 0 ; i < n ; i ++)
		fin << arr [i] << " ";
	fin << endl;

	fout << k - 1 << endl;
}
