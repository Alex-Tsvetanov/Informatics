//#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream cin ("symbol.in");
ofstream cout ("symbol.out");

int main ()
{
	const int n = 5;
	vector < pair < int, char > > input;

	for (int i = 0 ; i < n ; i ++)
	{
		int k; char c;
		cin >> k >> c;
		input.push_back ({k, c});
	}
	sort (input.begin (), input.end ());
	for (auto& x : input)
	{
		cout << string (x.first, x.second) << "\n";
	}
}
