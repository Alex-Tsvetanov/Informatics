#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr [100000];
vector < pair < int, int > > v;

int main ()
{
	ios::sync_with_stdio (false);
	cin.tie (nullptr);
	int n;
	cin >> n;
	
	int ans = 0;
	
	for (int i = 0 ; i < n ; i ++)
	{
		cin >> arr [i];
		v.push_back ({arr [i] + i, i});
	}
	
	sort (v.begin (), v.end ());

	for (int i = 0 ; i < n ; i ++)
	{
		int br = 0;
		auto upper = upper_bound (v.begin (), v.end (), i);
		for (int j = upper - v.begin () ; j < v.size () ; j ++)
			br += (v [j].second < i);
		ans += br * arr [i];
////	if (arr [i] + i > i + 1)
////		br ++;
	}
	cout << ans << "\n";
}
