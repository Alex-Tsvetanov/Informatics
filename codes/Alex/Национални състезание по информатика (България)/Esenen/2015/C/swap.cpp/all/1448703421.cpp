//swap_greedy.cpp
#include <iostream>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	int N;
	cin >> N;
	basic_string <int> P;
	int for_changeing = 0;
	for (int i = 0 ; i < N ; i ++)
	{
		int a;
		cin >> a;
		P += a;
		if (a != i + 1)
			for_changeing ++;
	}
	vector < pair < int, int > > ans;
	for (int k = 0 ; k < for_changeing ; k ++)
	{
		int Min = -1;
		for (int i = 0 ; i < N ; i ++)
		{
			if (P [i] != i + 1)
			{
				if (Min == -1)
					Min = i;
				else if (P [i] < P [Min])
					Min = i;
			}
		}
		if (Min == -1)
			break;
		//cout << "Move " << P [Min] << " from " << Min << " to " << P [Min] - 1 << "\n";
		int from = Min, to = P [Min] - 1, step = 1;
		if (from > to)
			step = -1;
		for (from ; ((step == -1) ? (from > to) : (from < to)) ; from += step)
		{
			swap (P [from], P [from + step]);
			ans.push_back ({from + 1, from + 1 + step});
		}
	}
	cout << ans.size () << "\n";
	for (auto& x : ans)
		cout << x.first << " " << x.second << "\n";
}
