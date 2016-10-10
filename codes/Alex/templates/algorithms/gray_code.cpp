#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <iomanip>
using namespace std;
/*
vector <string> gray_code (int n)
{
	vector <string> ans = {""};
	for (int i = 0 ; i <= n ; i ++)
	{
		int x = ans.size ();
		for (int i = x - 1 ; i >= 0 ; i --)
			ans.push_back (ans [i]);
		for (int i = 0 ; i < x ; i ++)
		{
			ans [i] = "0" + ans [i];
			ans [i + x] = "1" + ans [i + x];
		}
	}
	return ans;
}
*/
string print (string b)
{
	string x = b;
	for (int i = 0 ; i < b.size () ; i ++)
		x [i] = ((b [i] == '1')?'(':')');
	return x;
}
/*

void CoolCat (int k)
{
	int n = 2 * k;
	string b = string (k, '1') + string (k, '0');
	int x = k;
	int y = k;
	int ind = 0;
	cout << ++ind << ") " << print (b) << endl;
	while (x < n)
	{
		b [x] = '0';
		b [y] = '1';
		x ++;
		y ++;
		if (b [x] == '0')
		{
			if (x == 2 * (y - 1))
			{
				x ++;
			}
			else
			{
				b [x] = '1';
				b [2] = '0';
				x = 3;
				y = 2;
			}
		}
		cout << ++ind << ") " << print (b) << "\n";
	}
}
string xx;
set<string> my_set;
void T (int n, int k, int pos = 0, bool dir = 0)
{
	if ((k == 0) or (k == n))
		my_set.insert (xx);
	else
	{
		if (k == 1) 
		{
			xx [pos] = '1';
			T (n, k + 1, pos + 1, dir);
			xx [pos] = '0';
		}
		else
		{
			if (dir)
			{
				xx [pos] = '1';
				T (n, k + 1, pos + 1, not dir);
				xx [pos] = '0';
				T (n - 1, k - 1, pos + 1, dir);
			}
			else
			{
				T (n - 1, k - 1, pos + 1, dir);
				xx [pos] = '1';
				T (n, k + 1, pos + 1, not dir);
				xx [pos] = '0';
			}
		}
	}
}
*/
vector<string> K (int t, int s)
{
	if (t == s)
	{
		auto a = K (t, s - 1);
		vector < string > ans;
		for (auto& x : a)
			ans.push_back (x + "0");
		ans.push_back (string (t, '1') + string (s, '0'));
		return ans;
	}
	if (1 == s)
	{
		auto a = K (t - 1, s);
		vector < string > ans;
		for (auto& x : a)
			ans.push_back (x + "1");
		ans.push_back (string (t - 1, '1') + "01");
		return ans;
	}
	if (1 < s and s < t)
	{
		vector<string> ans;
		auto a = K (t, s - 1);
		for (auto& x : a)
			ans.push_back (x + "0");
		auto b = K (t - 1, s);
		for (auto& x : b)
			ans.push_back (x + "1");
		string c = string (t - 1, '1') + string (s, '0') + "1";
		ans.push_back (c);
		return ans;
	}
	return {};
}
int main ()
{
	int n;
	cin >> n;
	int ind = 0;
	auto f = K (n, n);
	vector < string > ans;
	ans.push_back (f [0]);
	for (int i = 1 ; i < f.size () ; i ++)
	{
		if (f [i] == f [i - 1])
			continue;
		ans.push_back (f [i]);
	}
	for (auto& x : ans)
		cout << setw (3) << ++ ind << ") "<< print (x) << endl;
/*	CoolCat (n);
	for (auto& x : gray_code (n))
	{
		if (x [0] == '1')
		{
			int arr [2] = {0,0};
			for (auto& y : x)
			{
				arr [y - '0'] ++;
				if (arr [1] < arr [0])
					goto Bad;
			}
			if (arr [0] == arr [1])
				cout << x << endl;
		}
		Bad:
		{
		}
	}*/
}
