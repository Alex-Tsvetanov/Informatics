#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector < pair < pair < int , int >, int > > v;
set < pair < int , int > > s;

int main ()
{
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back ({{a, b}, i});
	}

	sort (v.begin (), v.end (), 
			[](auto a, auto b)
			{
				return a.first.first < b.first.first;
			}
		 );

	for (int i = 0 ; i < n - 1 ; i ++)
	{
		for (int j = i ; v [i].first.first == v [j].first.first ; j ++)
			if (i != j)
				s.insert ({i, j});
	}

	sort (v.begin (), v.end (), 
			[](auto a, auto b)
			{
				return a.first.second < b.first.second;
			}
		 );

	for (int i = 0 ; i < n - 1 ; i ++)
	{
		for (int j = i ; v [i].first.second == v [j].first.second ; j ++)
			if (i != j)
				s.insert ({i, j});
	}
	cout << s.size () << "\n";
}
