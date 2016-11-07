#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main ()
{
	string b;
	cin >> b;
	string a, c;
	a = b;
	c = b;

	sort (a.begin (), a.end ());
	sort (c.begin (), c.end ());
	reverse (c.begin (), c.end ());
	int i = 0;
	while (a [i] == '0')
		i ++;
	swap (a [i], a [0]);
	string ans;
	int prenos = 0;
	for (int i = a.size () - 1 ; i >= 0 ; i --)
	{
		char digit = a [i] + c [i] + prenos - '0';
		prenos = 0;
		if (digit > '9')
		{
			digit -= 10;
			prenos = 1;
		}
		ans = digit + ans;
	}
	if (prenos > 0)
		ans = (char)(prenos + '0') + ans;

	cout << ans << endl;
}
