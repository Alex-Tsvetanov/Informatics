#include <iostream>

using std::cin;
using std::cout;
using std::string;
using std::vector;

vector < int > ln [26];

int main ()
{
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		string a;
		cin >> a;
		for (int _1 = 0 ; _1 < a.size () ; _1 ++)
			for (int _2 = _1 + 1 ; _2 < a.size () ; _2 ++)
				ln [a [_1] - 'a'].push_back (a [_2] - 'a');
	}

}
