#include <iostream>
#include <set>
#include <algorithm>
#define int long long
using namespace std;

const int MAXN = 75;
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
		if (a.b == b.b)
			return ((b.b - b.a) * a.c > (a.b - a.a) * b.c);
		else
			return a.b < b.b;
	}
	else 
		return a.a < b.a;
}


project projects [100000];
bool in [MAXN];

int n;

bool check (int k)
{
	for (int i = 0 ; i < n ; i ++)
	{
		if (in [i] and i != k)
		{
			bool curr = 
			  (
			   (projects [k].a <= projects [i].a and projects [i].a <= projects [k].b) or
			   (projects [i].a <= projects [k].a and projects [k].a <= projects [i].b) or			   
			   
			   (projects [k].a <= projects [i].b and projects [i].b <= projects [k].b) or
			   (projects [i].a <= projects [k].b and projects [k].b <= projects [i].b) or			   
			   false
			  )
			;
			//cout << i << " " << k << " = " << curr << "\n";
			//cout << a.a << " " << a.b << " " << b.a << " " << b.b << "\n";
			if (curr)
				return false;
		}
	}
	return true;
}

int ans = 0;

set < int >  mem [MAXN];

void rec (int curr_ind, int sum)
{
	if (mem [curr_ind].find (sum) != mem [curr_ind].end ())
		return;
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
	mem [curr_ind].insert (sum);
}

int32_t main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	cin >> n;
	if (n > 75/*1000*/)
	{
		for (int i = 0 ; i < n ; i ++)
		{
			int a, b, c;
			cin >> a >> b >> c;

			b = a + b;

			projects [i] = (project (a, b, c));
		}

		sort (projects + 0, projects + n);

		int max_ans = 0;
		for (int s = 0 ; s < n ; s ++)
		{
			int end = 0;
			int ans = 0;
			for (int i = s ; i < n ; i = (i + 1))
			{
				if (projects [i % n].a < end)
					continue;

				ans += projects [i % n].c;
				end = projects [i % n].b;
			}
			max_ans = max (max_ans, ans);
		}

		cout << max_ans << "\n";
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

		rec (0, 0);

		cout << ans << "\n";
	}
}
