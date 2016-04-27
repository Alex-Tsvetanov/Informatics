#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
	int n, p, k;
	cin >> n >> p >> k;
	vector <int> arr;
	for (int i = 0 ; i < n ; i ++)
	{
		int x;
		cin >> x;
		arr.push_back (x);
	}
	sort (arr.begin (), arr.end (), 
			[p](int a, int b)
			{
				return abs (p - a) < abs (p - b);
			}
		 );
	for (int i = 0 ; i < k ; i ++)
		cout << arr [i] << " ";
	cout << "\n";
}
