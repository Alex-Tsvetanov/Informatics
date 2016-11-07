#include <iostream>

using namespace std;

bool border [1 << 14];

int main ()
{
	int n, m;
	cin >> m >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		int l, r;
		cin >> l >> r;
		for (int j = l ; j <= r ; j ++)
			border [j] = 1;
	}
	for (int i = 1 ; i <= m ; i ++)
		if (!border [i])
		{
			cout << "NO\n";
			return 0;
		}
	cout << "YES\n";
}
