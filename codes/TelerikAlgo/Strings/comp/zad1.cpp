#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using Char = unsigned char;

bool latin (Char a)
{
	if (a == 'x') return false;
	return 
	('a' <= a and a <= 'z') or
	('A' <= a and a <= 'Z');
}

bool digit (Char a)
{
	return 
	('0' <= a and a <= '9');
}

int priority (Char a)
{
	if ('A' <= a and a <= 'Z')
		return (a - 'A') * 2;
	if ('a' <= a and a <= 'z')
		return (a - 'a') * 2 + 1;
	if (a == '0')
		return priority ('z') + 10;
	if ('0' <= a and a <= '9')
		return (a - '0') + priority ('z');
	return -1;
}

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	int n;
	cin >> n;
	vector < Char > output;
	for (int i = 0 ; i < n ; i ++)
	{
		int a;
		cin >> a;
		Char b = (Char)a;
		//cout << (Char) a << "\n";
		if (latin (b) or digit (b))
			output.push_back (b);
	}
	sort (output.begin (), output.end (), 
			[](Char a, Char b)
			{
				return (priority (a) < priority (b));
			}
		 );
	for (auto& x : output)
		cout << x;
	cout << endl;
}

