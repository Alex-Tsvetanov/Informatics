#include <iostream>
#include <random>

using namespace std;

const int Max = ((unsigned int)(-1)) / 2;
const int Min = -(((unsigned int)(-1)) / 2 - 5);

int my_random (int a, int b)
{
	random_device rnd;
	mt19937 mt (rnd ());
	uniform_int_distribution <int> u (a, b);
	return u (mt);
}

int main ()
{
	ios::sync_with_stdio (false);
	cin.tie (nullptr);
	int n = my_random (5, 10000);
	cout << n << "\n";
	for (int i = 0 ; i < n ; i ++)
		cout << my_random (Min, Max) << " ";
	cout << endl;
}
