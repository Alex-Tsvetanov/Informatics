#include <iostream>
#define int int64_t

using namespace std;

int32_t main ()
{
	int x, y, area;
	cin >> x >> y;
	area = x * y - (x - 2) * (y - 2);
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		int a;
		cin >> a;
		if (area % a == 0 and
		   (
				((x - 0) % a == 0 and (x - 2) % a == 0 and (y - 1) % a == 0 and (y - 1) % a == 0) or
				((x - 0) % a == 0 and (x - 1) % a == 0 and (y - 2) % a == 0 and (y - 1) % a == 0) or
				((x - 0) % a == 0 and (x - 0) % a == 0 and (y - 2) % a == 0 and (y - 2) % a == 0) or
				((x - 1) % a == 0 and (x - 1) % a == 0 and (y - 1) % a == 0 and (y - 1) % a == 0) or
				((x - 1) % a == 0 and (x - 1) % a == 0 and (y - 2) % a == 0 and (y - 0) % a == 0) or

				((x - 2) % a == 0 and (x - 2) % a == 0 and (y - 0) % a == 0 and (y - 0) % a == 0) or
				((x - 2) % a == 0 and (x - 1) % a == 0 and (y - 1) % a == 0 and (y - 0) % a == 0) or
				false
		   ))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}

