#include <iostream>
#include <utility>
#include <vector>
#include <set>

using namespace std;

set <int> rows;
set <int> cols;
set <int> dia1;
set <int> dia2;

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
			if (dia2.find (y + x) != dia2.end () and dia1.find (y - x) != dia2.end ())
			{
				cols.erase (cols.find (x));
				dia1.erase (dia1.find (y + x));
				dia2.erase (dia2.find (y - x));
				coords.push_back ({x, y});
				ans += NP ();
				coords.pop_back ();
				cols.insert (x);
				dia1.insert (y + x);
				dia2.insert (y - x);
			}
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
	for (int i = -R ; i <= R ; i ++)
	{
		dia2.insert (i + R);
		dia1.insert (i);
	}
	cout << NP () << endl;
}
