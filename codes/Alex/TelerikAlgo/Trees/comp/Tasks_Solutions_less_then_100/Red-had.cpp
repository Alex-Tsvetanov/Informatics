#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

int* weight;
vector <int>* ln;
int* depth;

void dfs (int v, int prev = -1)
{
	if (prev != -1)
		depth [v] = depth [prev] + weight [v];
	else depth[v] = weight[v];
	for (auto& x : ln [v])
		if (x != prev)
			dfs (x, v);
}

int main()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);

	int n;
	cin >> n;
	
	weight = new int [n];
	ln = new vector <int> [n];
	depth = new int [n];

	for(int i = 0 ; i < n ; i ++)
		cin >> weight [i];

	for(int i = 0; i < n - 1 ; i ++)
	{
		int a, b;
		cin >> a >> b;
		a --;
		b --;
		ln [a].push_back (b);
		ln [b].push_back (a);
	}
	dfs (0);
	int x = max_element (depth, depth + n) - depth;
	std::cout << x << '\n';
	dfs (x);
	cout << *max_element (depth, depth + n) << endl;
	delete[] weight;
	delete[] ln;
	delete[] depth;
	return 0;
}
