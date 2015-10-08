#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	vector < pair < int64_t, pair < bool, int64_t > > > a;
		     pair < int64_t, pair < bool, int64_t > >   x;
	vector < int64_t > pos_of_zeros;
	int64_t b;
	int64_t n, m;
	cin >> n >> m;
	for (int64_t i = 0 ; i < n + m ; i ++)
	{
		cin >> b;
		if (b == 0 and i < n)
			pos_of_zeros.push_back (i);
		if (b != 0 and i < n)
		{
			for (int j = 0 ; j < (int)pos_of_zeros.size () ; j ++)
				if (a [pos_of_zeros [j]].first == 0)
					a [pos_of_zeros [j]].first = b;
			pos_of_zeros.clear ();
		}
		x.first = b;
		x.second.first = (i < n);
		if (i < n)
			x.second.second = -1;
		else
			x.second.second = i - n;
		a.push_back (x);
	}
//	if (n > 1)
//		if (a [n - 1].first == 0) 
//			a [n - 1] = a [n - 2];
	sort (a.begin (), a.end ());
	int64_t pos = 0;
	vector < int64_t > ans;
	ans.resize (m);
	for (int64_t i = 0 ; i < (int64_t)a.size () ; i ++)
	{
		if (!a [i].second.first)
			ans [a [i].second.second] = pos;
		pos += (a [i].second.first);
	}
	for (int i = 0 ; i < (int64_t)ans.size () - 1 ; i ++)
		cout << ans [i] << " ";
	cout << ans.back () << "\n";
}
