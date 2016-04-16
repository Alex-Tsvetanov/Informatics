#include <iostream>
#include <set>
#include <vector>

using namespace std;
using vertexType = int;

vertexType parent [200 * 600];

vertexType Find_root (vertexType i)
{
	if (parent [i] == i)
	{
		return i;
	}
	else
	{
		vertexType k = parent [i];
		parent [i] = (Find_root (k));
		return parent [i];
	}
}
inline void Union (vertexType i, vertexType j)
{
	vertexType a, b;
	parent [a = Find_root (i)] = (b = Find_root (j));
}

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	int n, m;
	cin >> n >> m;
	for (int i = 0 ; i < n * m ; i ++)
		parent [i] = i;
	string str;
	cin >> str;
	while (str != "END")
	{
		int a, b;
		cin >> a >> b;
		a --;
		b --;
		if (str == "CONNECTED")
		{
			int rootA = Find_root (a);
			int rootB = Find_root (b);
			if (rootA == rootB)
				cout << "yes\n";
			else
				cout << "no\n";
		}
		else if (str == "BUILD")
		{
			Union (a, b);
		}
		cin >> str;
	}
	return 0;
}
