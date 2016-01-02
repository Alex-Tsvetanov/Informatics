#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
	int n, k;
	cin >> n >> k;
	vector <int64_t> balls;
	balls.reserve (n);

	for (int i = 0 ; i < n ; i ++)
	{
		int64_t a;
		cin >> a;
//		a = (a < 0) ? -a : a;
	
		balls.push_back (a);
	}

	auto result = std::minmax_element (balls.begin (), balls.end ());
	cout << *result.second - *result.first << "\n";

}
