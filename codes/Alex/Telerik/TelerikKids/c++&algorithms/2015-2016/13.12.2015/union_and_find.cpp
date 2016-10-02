#include <iostream>
#include <vector>
#include <set>

using namespace std;

using counterType = unsigned;
using vertexType = unsigned;

vector < vertexType > ln [1<<20];
counterType n;

void addEdge (vertexType a, vertexType b)
{
	ln [a].push_back (b);
}

vertexType parent [1<<20];

vertexType Find (vertexType a)
{
	if (parent [a] == a)
		return a;
	return (parent [a] = Find (parent [a]));
}

bool Union (vertexType a, vertexType b)
{
	a = Find (a);
	b = Find (b);

	bool ans = (a != b);

	parent [a] = b;

	return ans;
}

counterType number_of_commponents ()
{
	counterType ans = n;
	for (vertexType i = 0 ; i < n ; i ++)
		parent [i] = i;
	for (vertexType from = 0 ; from < n; from ++)
		for (auto& x : ln [from])
		{
			ans -= Union (from, x);
//				cout << "Union (" << from << ", " << x << ")\n";
		}
	for (vertexType from = 0 ; from < n; from ++)
		parent [from] = Find (from);
//	return ans;
//	/*

	set < vertexType > diff;
//		cout << "parent = {";
	for (vertexType i = 0 ; i < n ; i ++)
	{
		diff.insert (parent [i]);
//			cout << parent [i] << ", ";
	}
//		cout << "\b\b}\n";
	return diff.size ();

//	*/
}

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);

	counterType m;
	cin >> m >> n;
	vertexType a, b;
	for (counterType i = 0 ; i < m ; i ++)
	{
		cin >> a >> b;
		addEdge (a, b);
		addEdge (b, a);
	}

	cout << number_of_commponents () << "\n";
}
