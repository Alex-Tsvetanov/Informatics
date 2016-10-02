#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

vector < pair < int, int > > blocks;
vector < int > ln [100000];
vector < bool > used;

int dfs (int i, int depth = 1)
{
////cout << i << " " << depth << endl;
	used [i] = 1;
	int ans = depth;
	for (auto& x : ln [i])
		if (!used [x])
		{
			used [x] = 1;
			ans = max (ans, dfs (x, depth + 1));
			used [x] = 0;
		}
	used [i] = 0;
	return ans;
}

int main ()
{
	ios::sync_with_stdio (false);
	cin.tie (nullptr);
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		int a, b;
		cin >> a >> b;
		blocks.push_back ({a, b});
		used.push_back (false);
	}
	for (int i = 0 ; i < n ; i ++)
		for (int j = 0 ; j < n ; j ++)
			if (i != j)
				if (blocks [i].second == blocks [j].first)
					ln [i].push_back (j);
	int ans = 0;
	for (int i = 0 ; i < n ; i ++)
	{
		ans = max (ans, dfs (i));
	}
	cout << ans << "\n";
}
