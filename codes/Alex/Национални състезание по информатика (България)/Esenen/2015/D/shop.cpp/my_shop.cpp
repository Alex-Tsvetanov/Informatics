#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
	int n, k;
	cin >> n >> k;

	vector < int > products;
	products.reserve (n);

	for (int i = 0 ; i < n ; i ++)
	{
		int a;
		cin >> a;
		products.push_back (a);
	}

	sort (products.begin (), products.end ());
	reverse (products.begin (), products.end ());

	int sum = 0;
	for (int i = 0 ; i < n ; i ++)
		if ((i + 1) % k != 0)
			sum += products [i];
	cout << sum << "\n";
}
