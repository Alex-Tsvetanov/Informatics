//twostr.cpp
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string maxStr (const string a, const string b)
{
	if (a.size () < b.size ())
		return b;
	if (a.size () > b.size ())
		return a;
	if (a < b)
		return b;
	else
		return a;
}

string minStr (const string a, const string b)
{
	if (a.size () < b.size ())
		return a;
	if (a.size () > b.size ())
		return b;
	if (a < b)
		return a;
	else
		return b;
}

string sub (string a, string b)
{
	//    cout << a  << " - " << b << " = " << endl;
	//    cout << "\\t";
	string res;
	while (a.size () < b.size ())
		a = "0" + a;
	while (a.size () > b.size ())
		b = "0" + b;
	bool minusChar = (a < b);
	if (minusChar)
		swap (a, b);
	int prenos = 0;
	for (int i = a.size () - 1 ; i >= 0 ; i --)
	{
		char c = a [i] - b [i] - prenos + '0';
		if (c < '0')
		{
			prenos = 1;
			c += 10;
		}
		else
			prenos = 0;
		res = c + res;
	}
	while (res [0] == '0')
		res.erase (0, 1);
	if (minusChar)
		res = "-" + res;
	return res;
}

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	string s, t;
	cin >> s >> t;
	string maxS, minT = t;
	for (int k = 0 ; k < s.size () ; k ++)
	{
		if (s [0] != '0')
			maxS = maxStr(maxS, s);
		s += (s [0]);
		s.erase (0, 1);
	}
	for (int k = 0 ; k < t.size () ; k ++)
	{
		if (t [0] != '0')
			minT = minStr(minT, t);
		t += (t [0]);
		t.erase (0, 1);
	}
	//    cout << "Found min and max: " << minT << " " << maxS << endl;
	cout << sub (maxS, minT) << endl;
}
