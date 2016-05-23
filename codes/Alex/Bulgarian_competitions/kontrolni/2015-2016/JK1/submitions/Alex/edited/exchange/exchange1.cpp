#include <iostream>
#include <set>
#include <vector>
#include <iomanip>

using namespace std;

int a [256];
int b [256];
int c [256];
vector <int> monets;
int sum;

__uint128_t mem [2048][256];

__uint128_t rec (int s, size_t ind = 0)
{
	if (s > sum)
		return 0;
	if (ind >= monets.size ())
		return s == sum;
	if (mem [s][ind] == 0)
	{
		__uint128_t ans = 0;
		for (int i = 0 ; i <= c [monets [ind]] ; i ++)
			ans += rec (s + monets [ind] * i, ind + 1);
		return (mem [s][ind] = ans);
	}
	return mem [s][ind];
}

void print_uint128_t (__uint128_t a)
{
	__uint128_t _18 = 1e18;
	uint64_t _1 = a / _18;
	uint64_t _2 = a % _18;
	if (_1 == 0) cout << _2 << "\n";
	else cout << _1 << setw (18) << setfill ('0') << _2 << "\n";
}

int main ()
{
	int n;
	cin >> sum >> n;
	for (int i = 0 ; i < n ; i ++) cin >> a [i];
	
	for (int i = 0 ; i < n ; i ++) cin >> b [i];

	set <int> tmp;
	for (int i = 0 ; i < n ; i ++)
	{
		c [a [i]] += b [i];
		tmp.insert (a [i]);
	}
	monets = vector <int> (tmp.begin (), tmp.end ());

	__uint128_t res = rec (0);
	print_uint128_t (res);
}
