#include <iostream>
#include <set>
#include <limits>

using namespace std;

int main ()
{
	set < int64_t > s;
	multiset < uint64_t > diffs;
	int n;
	cin >> n;
	uint64_t minDiff = -1;
	for (int i = 0 ; i < n ; i ++)
	{
		int64_t x;
		cin >> x;
		auto p = s.insert (x);
		if (!p.second)
		{
			uint64_t Prev = *std::prev (p.first);
			uint64_t Next = *std::next (p.first);
			diffs.erase (diffs.find (x - Prev));
			diffs.erase (diffs.find (Next - x));
			s.erase (p.first);
			if (s.size () == 1)
				cout << "There is only one number";
			else if (s.size () == 0)
				cout << "There are no numbers";
			else
				cout << *diffs.begin ();
			cout << "\n";
		}
		else
		{
			if (s.size () > 3)
			{
				auto itPrev = prev (p.first);
				auto itNext = next (p.first);

				{
					itPrev --;
					int64_t prev;
					prev = *itPrev;
					diffs.insert ((uint64_t)(x - prev));
				}
				
				{
					itNext ++;
					int64_t next = *itNext;
					next = *itNext;
					diffs.insert ((uint64_t)(x - next));
				}

				cout << *diffs.begin ();
			}
			else if (s.size () == 2)
			{
				auto first = s.begin ();
				auto second = next (s.begin ());
				diffs.insert (((uint64_t)(*second - *first)));
				cout << *diffs.begin ();
			}
			else if (s.size () == 1)
				cout << "There is only one number";
			else
				cout << "There are no numbers";
			cout << "\n";
		}
	}
}
