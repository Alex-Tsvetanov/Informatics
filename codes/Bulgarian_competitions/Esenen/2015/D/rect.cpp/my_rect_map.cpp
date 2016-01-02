#include <iostream>
#include <utility>
#include <vector>

using namespace std;

bool can_merge (int a, int b, int c , int d)
{
	return (a == c) or (a == d) or (b == c) or (b == d);
}

vector < pair < pair < int, int >, pair < int, int > > > can_merge (vector < pair < int, int > > a, int c , int d)
{
	vector < pair < pair < int, int >, pair < int, int > > > ans = {};
	for (int i = 0 ; i < a.size () ; i ++)
	{
		if (a [i].first == c)
			ans.push_back ({a [i].first, a [i].first + d});
		if (a [i].first == d and c != d)
			ans.push_back ({a [i].first, a [i].first + c});
		if (a [i].second == c and a [i].first != a [i].second)
			ans.push_back ({a [i].second, a [i].second + d});
		if (a [i].second == d and a [i].first != a [i].second and c != d)
			ans.push_back ({a [i].second, a [i].second + c});
	}
	return move (ans);
}

vector < pair < int, int > > merge (int a, int b, int c, int d)
{
	vector < pair < int , int > > ans;
	if (a == c)
		ans.push_back ({a, b + d});
	if (a == d and c != d)
		ans.push_back ({a, b + c});
	if (a != b and b == c)
		ans.push_back ({b, a + d});
	if (a != b and c != d and b == d)
		ans.push_back ({b, a + c});
}

int main ()
{
	int a1, b1;
	int a2, b2;
	int a3, b3;
	
	cin >> a1 >> b1;
	cin >> a2 >> b2;
	cin >> a3 >> b3;

	if ((can_merge (a1,b1,a2,b2)) and (can_merge (merge (a1, b1, a2, b2), a3, b3)).size () > 0)
	{
		
	}

	
}
