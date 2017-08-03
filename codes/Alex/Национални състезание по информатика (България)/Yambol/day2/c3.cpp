#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct edge 
{
	long long index = 0;
	long long v = 0;
	edge (long long a = 0, long long b = 0) : v (a), index (b)
	{

	}
};

long long n, k;
vector < edge > ln [100000];
bool visited [100000];
bool start [100000];

long long global = -1;

bool topological_sort (long long v, long long Max = -1, long long visits = 1)
{
	if (visits <= 0)
		return false;
	if (visits > n)
		return false;
	if (visits == n)
	{
		global = Max;
		return true;
	}
	for (auto& x : ln [v])
	{
		if (not visited [x.v])
		{
			visited [x.v] = true;
			if (topological_sort (x.v, max (Max, x.index), visits + 1))
				return true;
			visited [x.v] = false;
		}
	}
	return false;
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
	int starts = n;
	long long vertex = n * (n - 1) / 2;
	for (long long i = 0 ; i < k ; i ++)
	{
		long long a, b;
		cin >> a >> b;
		a --; b --;
		if (a == b)
			continue;
		ln [a].push_back (edge (b, i + 1));
		if (not start [b])
		{
			starts -= 1;
			vertex -= b;
			start [b] = true;
		}
	}
	if (starts != 1)
	{
		cout << -1 << endl;
		return 0;
	}
	int x = vertex;
	visited [x] = true;
	if (topological_sort (x))
	{
		cout << global << endl;
		return 0;
	}
	cout << -1 << endl;
}
