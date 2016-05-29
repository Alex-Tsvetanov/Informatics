#include <string>
#include <set>
#include <vector>
#include <iostream>

using namespace std;

set < int > ln [10];
int n;	

bool topological_sort (vector <int> s = vector <int> ())
{
	if (s.size () == n)
	{
		for (int i = 0 ; i < s.size () ; i ++)
		{
			cout << s [i];
		}
		cout << "\n";
		return 1;
	}
	if (s.size () == 0)
		for (int i = 0 ; i < n ; i ++)
		{
			s.push_back (i);
			if (topological_sort (s))
			{
				return 1;
			}
			s.pop_back ();
		}
	else
		for (auto& x : ln [s [s.size () - 1]])
		{
			s.push_back (x);
			if (topological_sort (s))
			{
				return 1;
			}
			s.pop_back ();
		}
	return 0;
}

int main ()
{
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		char x, y;
		string blq;
		cin >> x >> blq >> blq >> y;
		x -= '0';
		y -= '0';
		if (blq == "after")
		{
			ln [x].insert (y);
		}
		else
		{
			ln [y].insert (x);
		}
	}
	topological_sort ({});
}
