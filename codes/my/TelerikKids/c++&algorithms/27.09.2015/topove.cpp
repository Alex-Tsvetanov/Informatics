#include <iostream>
#include <utility>
#include <vector>
#include <set>

using namespace std;

set <int> rows;
set <int> cols;
vector < pair < int, int > > coords;
int B;

uint64_t NP ()
{
	//cout << br << "\n";
	if ((int)coords.size () == B)
	{
		for (auto& x : coords)
			cout << x.first << " " << x.second << endl;
		cout << "-----------------------------------";
		cout << endl;
		return 1;
	}
	if ((int)coords.size () > B)
		return 0;
	uint64_t ans = 0;
	set < int > copy_rows = rows;
	set < int > copy_cols = cols;
	for (auto y : copy_rows)
	{
		rows.erase (rows.find (y));
		for (auto x : copy_cols)
		{
			cols.erase (cols.find (x));
			coords.push_back ({x, y});
			ans += NP ();
			coords.pop_back ();
			cols.insert (x);
		}
		rows.insert (y);
	}
	return ans;
}

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	int R;
	cin >> R >> B;
	for (int i = 0 ; i < R ; i ++)
	{
		rows.insert (i);
		cols.insert (i);
	}
	NP ();
	uint64_t ans = 1;
	for (int i = 0 ; i < B ; i ++)
		ans *= (R - i) * (R - i);
	cout << ans << "\n";
}
