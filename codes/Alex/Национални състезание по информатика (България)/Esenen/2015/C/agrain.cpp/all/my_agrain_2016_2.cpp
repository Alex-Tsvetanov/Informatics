#include <iostream>
#define int uint64_t

using namespace std;

int32_t main ()
{
	int n, l, d;
	cin >> n >> l >> d;
	int x, a, b;
	cin >> x >> a >> b;
	for (int i = 0 ; i < n ; i ++)
	{

		x = (x * a + b) % (l + 1);
	}
}
