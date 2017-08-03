#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector < int > ln [100000];
bool visited [100000];
vector < int > top_sort;

bool topological_sort (int v, int visits = 1)
{
	//cout << string (top_sort.size (), ' ');
	//for (auto& x : top_sort)
		//cout << " " << x;
	//cout << endl;
	for (auto& x : ln [v])
	{
		if (not visited [x])
		{
			//top_sort.push_back (x);
			visited [x] = true;
			if (topological_sort (x, visits + 1))
				return true;
			//top_sort.pop_back ();
			visited [x] = false;
		}
	}
	bool ans = true;
	for (int i = 0 ; i < n ; i ++)
		ans = ans and visited [i];
	return ans;
}

int parent [100000];

int find (int a)
{
	if (parent [a] == a or parent [a] == -1)
		return a;
	return parent [a] = find (parent [a]);
}

bool connect (int a, int b)
{
	int fa = find (a), fb = find (b);
	parent [fa] = fb;
	return fa != fb;
}

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	cin >> n >> k;
	if (k < n - 1)
	{
		cout << -1 << "\n";
		return 0;
	}
	for (int i = 0 ; i < n ; i ++)
		parent [i] = i;
	for (int i = 0 ; i < k ; i ++)
	{
		int a, b;
		cin >> a >> b;
		a --; b --;
		ln [a].push_back (b);

		//cout << "Iteration " << i << endl;
		if (connect (a, b) or i == k - 1)
			if (i >= n - 2)
			{
				for (int j = 0 ; j < n ; j ++)
				{
					for (int k = 0 ; k < n ; k ++)
						visited [k] = false;
					if (not visited [j])
					{
						visited [j] = true;
						top_sort.push_back (j);
						if (topological_sort (j))
						{
							cout << i + 1 << endl;
							return 0;
						}
						top_sort.pop_back ();
					}
				}
			}
		//cout << "-----------------------------------------------\n";
	}
	cout << -1 << endl;
}
