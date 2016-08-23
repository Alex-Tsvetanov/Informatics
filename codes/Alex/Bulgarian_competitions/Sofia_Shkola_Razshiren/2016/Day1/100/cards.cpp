#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

//              sum        fir  sec
vector < pair < int, pair <int, int> > > to_get;

int main ()
{
	int n;
	int sum = 0;
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		int a, b;
		cin >> a >> b;
		if (a > b)
			swap (a, b);
		to_get.push_back ({a + b, {a, b}});
	}
	sort (to_get.begin (), to_get.end ());
	for (int j = 0 ; j < n ; j ++)
	{
		if (j < n / 2)
			sum += to_get [j].second.first;
		else
			sum -= to_get [j].second.second;
	}
	cout << sum << "\n";
}
