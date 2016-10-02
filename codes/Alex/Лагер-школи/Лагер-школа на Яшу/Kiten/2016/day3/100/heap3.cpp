#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	vector <int> v;
	make_heap (v.begin (), v.end (), greater<int> ());
	int n;
	std::cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		char c;
		std::cin >> c;
		if (c == 'r')
		{
			pop_heap (v.begin (), v.end (), greater <int> ());
			std::cout << v [v.size () - 1] << "\n";
			v.pop_back ();
		}
		else // c = 'a'
		{
			int a;
			std::cin >> a;
			v.push_back (a);
			push_heap (v.begin (), v.end (), greater<int> ());
		}
	}
	std::cout.flush ();
	return 0;
}
