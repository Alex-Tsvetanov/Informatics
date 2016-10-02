#include <iostream>
#include <set>

using namespace std;

set <int> s;
int arr [10000];

int main ()
{
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		cin >> arr [i];
		s.insert (arr [i]);
	}
	int ans = 0;
	for (int i = 0 ; i < n ; i ++)
		for (auto it = s.find (arr [i]) ; it != s.begin () ; it --)
			ans ++;
	cout << ans << "\n";
}
