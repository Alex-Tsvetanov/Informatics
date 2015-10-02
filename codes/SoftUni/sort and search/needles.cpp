#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct element
{
	int value;
	int indx;
	int pos;
};

int main ()
{
	vector < pair < int32_t, pair < bool, int > > > a;
	int n, m;
	cin >> n >> m;
	for (int i = 0 ; i < n + m ; i ++)
	{
		int b; cin >> b;
		if (b != 0 and i < n)
		{
			for (int j = 0 ; j < i ; j ++)
				if (a [j].first == 0)
					a [j].first = b;
		}
		pair < int32_t, pair < bool, int > > x;
		x.first = b;
		x.second.first = (i < n);
		if (i < n)
			x.second.second = -1;
		else
			x.second.second = i - n;
		a.push_back (x);
	}
	if (a [n - 1].first == 0) 
		a [n - 1] = a [n - 2];
	sort (a.begin (), a.end ());
//	for (auto& x : a)
//	{
//		cout << x.first << " " << x.second.first << " " << x.second.second << endl;
//	}
	int pos = 0;
	vector < int > ans;
	ans.resize (m);
	for (int i = 0 ; i < (int)a.size () ; i ++)
	{
		if (!a [i].second.first)
			ans [a [i].second.second] = pos;
		pos += (a [i].second.first);
	}
	for (int i = 0 ; i < (int)ans.size () - 1 ; i ++)
		cout << ans [i] << " ";
	cout << ans.back () << "\n";
}
