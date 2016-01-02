#include <iostream>
#include <set>

using namespace std;

set<int>::iterator prevOfEnd (set <int>& s)
{
	auto it = s.end ();
	it --;
	return it;
}

int last (multiset <int>& s)
{
	//	cout << "last: " << "\t" << s.size () << endl;
	auto it = s.end ();
	it --;
	return *it;
}

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	set < int > s;
	multiset < int > diffs;
	int n, l, d;
	cin >> n >> l >> d;
	int x, a, b;
	cin >> x >> a >> b;
	if ((uint64_t)(n + 1) * d < (uint64_t)l)
	{
		cout << "-1\n";
		return 0;
	}
	s.insert (l);
	//	diffs.insert (l);
	for (int i = 0 ; i < n ; i ++)
	{
		auto p = s.insert (x);
		auto itOfElementX = p.first;

		if (s.size () >= 2)
		{
			//			cout << diffs.size () << endl;
			auto Prev = itOfElementX;
			auto Next = itOfElementX;
			if (itOfElementX != prevOfEnd (s))
			{
				Next ++;
				diffs.insert (((int)(*Next)) - x);
			}
			//			cout << diffs.size () << endl;
			if (itOfElementX != s.begin ())
			{
				Prev --;
				diffs.insert (((int)(x)) - *Prev);
			}
			//			cout << diffs.size () << endl;
			if (itOfElementX != s.begin () and itOfElementX != prevOfEnd (s))
				if (Prev != itOfElementX and Next != itOfElementX)
					diffs.erase (diffs.find (((int)(*Next)) - *Prev));
			//			cout << diffs.size () << endl;
		}
		//		cout << s.size () << " " << ((diffs.size () > 0) ? last (diffs) : int ()) << endl;
		if (diffs.size () > 0)
		{
			if (last (diffs) <= d and (*s.begin ()) <= d and l - (* /*std::prev */(prevOfEnd (s))) <= d)
			{
				////			for (auto& X : s)
				////				cout << X << " ";
				////			cout << endl;
				cout << i + 1 << "\n";
				return 0;
			}
			//			cout << "Changing X to " << endl;
			//			cout << "\t" << x << endl;
		}
		x = (int)((x * (uint64_t)a + b) % (l + 1));
	}
	cout << -1 << "\n";
}
