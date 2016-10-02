#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

std::vector<uint64_t> parent;
std::vector < std::pair <uint64_t, std::pair <uint64_t, uint64_t> > > q;

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

int main ()
{
	int N;
	std::cin >> N;
	for (int i = 0 ; i < N ; i ++)
	{
		uint64_t n, m, k;
		std::cin >> n >> m >> k;
		parent.clear ();
		q.clear ();
		parent.resize (n);

		for (uint64_t i = 0 ; i < n ; i ++)
			parent [i] = i;

		for (uint64_t i = 0 ; i < m ; i ++)
		{
			uint64_t a, b;
			uint64_t c;
			std::cin >> a >> b >> c;
			q.push_back ({c, {a, b}});
		}

		//-------------------------------------------
		///Connect undestroyed edges with tree
		//-------------------------------------------
		std::set <uint64_t> arr;

		for (uint64_t i = 0 ; i < k ; i ++)
		{
			uint64_t x;
			std::cin >> x;
			arr.insert (x);
		}

		for (uint64_t i = 0 ; i < m ; i ++)
			if (arr.find (i + 1) == arr.end ())
				if (!our (q [i].second.first, q [i].second.second))
					connect (q [i].second.first, q [i].second.second);

		//-------------------------------------------
		///Do Kruskal's algorithm
		//-------------------------------------------

		std::sort (q.begin (), q.end ());

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
		std::cout << T << "\n";
	}
}
