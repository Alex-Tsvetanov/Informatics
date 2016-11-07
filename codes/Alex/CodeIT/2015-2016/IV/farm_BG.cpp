//#include <iostream>
#include <fstream>

using namespace std;

ifstream cin ("farm.in");
ofstream cout ("farm.out");

uint64_t power3 [] = {
	1,
	3,
	9,
	27,
	81,
	243,
	729,
	2187,
	6561,
	19683,
	59049,
	177147,
	531441,
	1594323,
	4782969,
	14348907,
	43046721,
	129140163,
	387420489,
	1162261467,
	3486784401,
	10460353203,
	31381059609,
	94143178827,
	282429536481,
	847288609443,
	2541865828329,
	7625597484987,
	22876792454961,
	68630377364883,
	205891132094649,
	617673396283947,
	1853020188851841,
	5559060566555523
};

int value (uint64_t a, int p, int start = 1)
{
	if (p == 0)
		return start;
	if (power3 [p - 1] <= a and a < 2 * power3 [p - 1])
		return start;
	if (a < power3 [p - 1])
		return value (a, p - 1, start + 1);
	if (a >= 2 * power3 [p - 1])
		return value (a - 2 * power3 [p - 1], p - 1, start + 1);
}

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	int p, n;
	cin >> p >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		uint64_t a = i;
		cin >> a;
		a --;

		cout << value (a, p) << endl;
	}
}
