#include <iostream>
#include <set>
#define int long long
int dp [20004];
std::set <int> a, b;
int n, m;

int32_t main ()
{
	std::cin.tie (nullptr);
	std::ios::sync_with_stdio (false);
	std::cin >> n >> m;
	
	for (int i = 0 ; i < n ; i ++)
		std::cin >> dp [i];

	a.insert (0);
	for (int i = 0 ; i < n ; i ++)
	{
		for (auto& x : a)
		{
			if (x + dp [i] <= m)
				b.insert (x + dp [i]);
		}
		for (auto& x : b)
			a.insert (x);
		b.clear ();
	}
	a.erase (0);
	for (auto& x : a)
			std::cout << x << " ";
	std::cout << "\n";
}
