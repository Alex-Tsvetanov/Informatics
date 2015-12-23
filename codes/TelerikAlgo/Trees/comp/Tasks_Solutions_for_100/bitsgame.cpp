#include <iostream>
#include <set>
#include <iomanip>
#include <sstream>

using namespace std;

set<int64_t>::iterator prevOfEnd (set <int64_t>& s)
{
	auto it = s.end ();
	it --;
	return it;
}

void print (__int128_t a)
{
	uint64_t MOD = 1e18;
	uint64_t x1 = a % MOD;
	uint64_t x2 = a / MOD;
	stringstream ss;
	ss << x2 << setw (18) << setfill ('0') << x1;
	string x = ss.str ();
	while (x [0] == '0')
		x.erase (0, 1);
	cout << x;
}

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	set < int64_t > s;
	multiset < __int128_t > diffs;
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		int64_t x;
		cin >> x;
		auto p = s.insert (x);
		auto itOfElementX = p.first;

		bool eraseX = false;
		if (!p.second) // erase x
		{
			auto Prev = itOfElementX;
			auto Next = itOfElementX;

			if (itOfElementX != prevOfEnd (s))
			{
				Next ++;
				diffs.erase (diffs.find ((__int128_t)(*Next) - x)); // erase diff of x and Next element in the set
			}
			if (itOfElementX != s.begin ())
			{
				Prev --;
				diffs.erase (diffs.find ((__int128_t)(x) - *Prev)); // erase diff of x and Prev element in the set
			}
			if (itOfElementX != s.begin () and itOfElementX != prevOfEnd (s))
					diffs.insert (((__int128_t)(*Next)) - *Prev); // add sum of Next and Prev element
			
			s.erase (x); // erase x;
			eraseX = true;
		}

		if (s.size () == 0)
			cout << "There are no numbers";
		else if (s.size () == 1)
			cout << "There is only one number";
		else if (eraseX)
			print (*diffs.begin ());
		else if (s.size () == 2)
		{
			diffs.insert (((__int128_t)(*prevOfEnd (s))) - *s.begin ());
			print (*diffs.begin ());
		}
		else if (s.size () > 2)
		{
			auto Prev = itOfElementX;
			auto Next = itOfElementX;
			if (itOfElementX != prevOfEnd (s))
			{
				Next ++;
				diffs.insert (((__int128_t)(*Next)) - x);
			}
			if (itOfElementX != s.begin ())
			{
				Prev --;
				diffs.insert (((__int128_t)(x)) - *Prev);
			}
			if (itOfElementX != s.begin () and itOfElementX != prevOfEnd (s))
					diffs.erase (((__int128_t)(*Next)) - *Prev);
			print (*diffs.begin ());
		}
		cout << "\n";
	}
}

