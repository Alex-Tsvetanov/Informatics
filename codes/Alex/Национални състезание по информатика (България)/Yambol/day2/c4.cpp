#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
	int n, p;
	cin >> n >> p;
	vector < int > v;
	for (int i = 0 ; i < n ; i ++)
	{
		int a;
		cin >> a;
		v.push_back (a);
	}

	long long ans = 0;
	while (v.size () >= p)
	{
		sort (v.begin (), v.end ());
		reverse (v.begin (), v.end ());
		while (v.size () >= p and v.back () == 0)
			v.pop_back ();
		if (v.size () < p)
			break;
		int Min = 1e9;
		for (int i = 0 ; i < p ; i ++)
			Min = min (Min, v [i]);
		for (int i = 0 ; i < p ; i ++)
			v [i] -= Min;
		ans += Min * p;
	}
	ans += v.size ();
	cout << ans << "\n";
}
