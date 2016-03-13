#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> tatkofci;
vector<pair<int, int>> zaqfki;
set<int> asd;
int find(int x)
{

	if (tatkofci[x] == x)
		return x;
	else
		return find(tatkofci[x]);
}

void unionf(int x, int y)
{
	int xRoot = find(x);
	int yRoot = find(y);
	tatkofci[yRoot] = xRoot;
}

int main()
{
	int n, m;
	cin >> n >> m;
	tatkofci.resize(n);
	for (int i = 0; i < n; i++)
	{
		tatkofci[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		zaqfki.push_back({ a, b });
	}
	for (auto& p : zaqfki)
	{
		unionf(p.first, p.second);
	}
	for (auto& p : tatkofci)
	{
		asd.insert(p);
	}
	cout << asd.size() << endl;
	return 0;
}
