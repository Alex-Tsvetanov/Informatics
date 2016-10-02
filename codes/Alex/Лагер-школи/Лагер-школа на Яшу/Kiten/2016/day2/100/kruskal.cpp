#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

vector<uint64_t> parent;
vector < pair <uint64_t, pair <uint64_t, uint64_t> > > q;

uint64_t find (uint64_t a)
{
	if (a == parent [a])
		return a;
	return parent [a] = find (parent [a]);
}

bool our (uint64_t a, uint64_t b)
{
	return find (a) == find (b);
}

void connect (uint64_t a, uint64_t b)
{
	parent [find (a)] = find (b);
}

int32_t main ()
{
	uint64_t n, m;
	cin >> n >> m;
	parent.resize (n + 10);

	for (uint64_t i = 0 ; i < n ; i ++)
		parent [i] = i;

	for (uint64_t i = 0 ; i < m ; i ++)
	{
		uint64_t a, b;
		uint64_t c;
		cin >> a >> b >> c;
		a --; b --;
		q.push_back ({c, {a, b}});
	}

	sort (q.begin (), q.end ());

	uint64_t T = 0;
	uint64_t iters = 0;

	for (auto& sq : q)
	{
		if (!our (sq.second.first, sq.second.second))
		{
			T += sq.first;
			connect (sq.second.first, sq.second.second);
			iters ++;
			if (iters == n - 1)
				break;
		}
	}
	cout << T << "\n";
	return 0;
}
