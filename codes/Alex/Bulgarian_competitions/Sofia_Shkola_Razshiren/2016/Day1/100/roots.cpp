#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#define int int64_t

using namespace std;

vector <int> horner (const vector <int> & poly, int root)
{
	vector <int> new_poly;
	new_poly.push_back (poly [0]);
	for (int i = 1 ; i < (int)poly.size () ; i ++)
		new_poly.push_back (new_poly [i - 1] * root + poly [i]);
	return move (new_poly);
}

int32_t main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	size_t N;
	cin >> N;
	vector <int> poly;
	for (int i = 0 ; i < (int)N + 1 ; i ++)
	{
		int a;
		cin >> a;
		poly.push_back (a);
	}
	vector <int> ans;
	int ind = poly.size () - 1;
	while (poly [ind] == 0) ind --;
	int del_of = abs (poly [ind]);
	for (int i = 0 ; i * i <= del_of ; i ++)
	{
		if (i == 0)
		{
			while (ans.size () <= N)
			{
				vector <int> new_poly = horner (poly, i);
				if (new_poly.back () == 0)
				{
					ans.push_back (i);
					new_poly.pop_back ();
					poly = move (new_poly);
				}
				else
					break;
			}
		}
		else
		{
			int x = 0;
			x = i;
			while (del_of % x == 0 and ans.size () <= N)
			{
				vector <int> new_poly = horner (poly, x);
				if (new_poly.back () == 0)
				{
					//cout << "\t" << x << "\n";
			//cout.flush ();
					ans.push_back (x);
					new_poly.pop_back ();
					poly = move (new_poly);
				}
				else
					break;
			}
			x = del_of / i;
			while (del_of % x == 0 and ans.size () <= N)
			{
				vector <int> new_poly = horner (poly, x);
				if (new_poly.back () == 0)
				{
					//cout << "\t" << x << "\n";
			//cout.flush ();
					ans.push_back (x);
					new_poly.pop_back ();
					poly = move (new_poly);
				}
				else
					break;
			}
			x = -i;
			while (del_of % x == 0 and ans.size () <= N)
			{
				vector <int> new_poly = horner (poly, x);
				if (new_poly.back () == 0)
				{
					//cout << "\t" << x << "\n";
			//cout.flush ();
					ans.push_back (x);
					new_poly.pop_back ();
					poly = move (new_poly);
				}
				else
					break;
			}
			x = -del_of / i;
			while (del_of % x == 0 and ans.size () <= N)
			{
				vector <int> new_poly = horner (poly, x);
				if (new_poly.back () == 0)
				{
					//cout << "\t" << x << "\n";
			//cout.flush ();
					ans.push_back (x);
					new_poly.pop_back ();
					poly = move (new_poly);
				}
				else
					break;
			}
		}
	}
	sort (ans.begin (), ans.end ());
	int back = ans.back ();
	ans.pop_back ();
	for (auto& x : ans)
	{
		cout << x << " ";
	}
	cout << back << "\n";
    return 0;
}
