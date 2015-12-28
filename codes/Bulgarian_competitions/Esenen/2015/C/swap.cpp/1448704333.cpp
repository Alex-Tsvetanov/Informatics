//swap.cpp
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
	basic_string <int> origP;
	for (int i = 0 ; i < N ; i ++)
	{
		int a;
		cin >> a;
		P += a;
	}
	origP = P;
	sort (origP.begin (), origP.end ());
	
	set < basic_string < int > > all;
	queue < pair < basic_string < int >, vector < pair < int, int > > > > q;
	q.push ({P, {}});
	while (!q.empty ())
	{
		auto front = q.front (); q.pop ();
		auto currP = front.first;
		auto path = front.second;
		all.insert (currP);
		
		if (currP == origP)
		{
			cout << path.size () << "\n";
			for (auto& x : path)
				cout << x.first + 1 << " " << x.second + 1 << "\n";
			return 0;
		}
		
		for (int i = 0 ; i < currP.size () - 1 ; i ++)
		{
			if (currP [i] != i + 1 and currP [i + 1] != i + 2)
			{
				swap (currP [i], currP [i + 1]);
				path.push_back ({i, i + 1});
				if (all.find (currP) == all.end ())
					q.push ({currP, path});
				path.pop_back ();
				swap (currP [i], currP [i + 1]);
			}
		}
	}
}
