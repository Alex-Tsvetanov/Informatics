#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define int uint64_t

using namespace std;

struct project 
{
	int a, b, c;
	project (int _a = 0, int _b = 0, int _c = 0)
	{
		a = _a;
		b = _b;
		c = _c;
	}
};

bool operator < (project a, project b)
{
	if (a.a == b.a)
	{
		if ((b.b - b.a) * a.c == (a.b - a.a) * b.c)
			return a.b < b.b;
		else
			return ((b.b - b.a) * a.c > (a.b - a.a) * b.c);
	}
	else 
		return a.a < b.a;
}

project projects [1<<17];
bool in [1<<17];

int n;

bool check (int j)
{
	const project& a = projects [j];
	for (int i = 0 ; i < j ; i ++)
	{
		const project& b = projects [i];

		if (in [i] and
		   (
				((a.a <= b.a) and (b.a <= a.b)) or
				((b.a <= a.a) and (a.a <= b.b)) or
				((a.a <= b.b) and (b.b <= a.b)) or
				((b.a <= a.b) and (a.b <= b.b)) or
/*
				((a.a <= b.a) and (a.b >= b.a)) or
				((a.a <= b.b) and (a.b >= b.b)) or
				((a.a >= b.a) and (a.b <= b.a)) or
				((a.a >= b.b) and (a.b <= b.b)) or
*/
				false
		   )
		   )
			return false;
	}
	return true;
}

int ans = 0;

//set < pair < int, int > >  mem;

void rec (int curr_ind, int sum)
{
//	if (mem.find ({curr_ind, sum}) != mem.end ())
//		return;
//	else
//		mem.insert ({curr_ind, sum});
	ans = max (ans, sum);
	if (curr_ind == n)
	{
		return;
	}
	if (check (curr_ind))
	{
		in [curr_ind] = 1;
		rec (curr_ind + 1, sum + projects [curr_ind].c);
		in [curr_ind] = 0;
	}
	rec (curr_ind + 1, sum);
}

int32_t main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	cin >> n;
	if (n > 90000)
		while (1){}
	if (n > 75/*1000*/)
	{
		for (int i = 0 ; i < n ; i ++)
		{
			int a, b, c;
			cin >> a >> b >> c;

			b = a + b;

			projects [i] = (project (a, b, c));
		}

		int ans = 0;
		for (int i = 0 ; i < n ; i ++)
		{
			if (check (i))
			{
				ans += projects [i].c;
				in [i] = 1;
			}
		}

		cout << ans << "\n";
		return 0;
	}
	else
	{

		for (int i = 0 ; i < n ; i ++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			
			b += a - 1;
			
			projects [i] = (project (a, b, c));
		}

	////for (int i = 0 ; i < n ; i ++)
	////	cout 
	////		<< projects [i].a << " "
	////		<< projects [i].b << " "
	////		<< projects [i].c << "\n";

		rec (0, 0);

		cout << ans << "\n";
	}
}
