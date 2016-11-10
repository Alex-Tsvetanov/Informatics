#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <bitset>
#define int int64_t

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

project projects [100000];
///                              100000 
pair < int, bitset < 5000 > > dp [5000];

int n;

int ans = 0;

bool check (int i, int j)
{
	const project& a = projects [i];
	const project& b = projects [j];
	return 
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
	  ;
}

int32_t main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		b = a + b - 1;

		projects [i] = (project (a, b, c));
	}

	int max_ind = 0;

	for (int i = 0 ; i < n ; i ++)
	{
		bitset <5000> tmp;
		dp [i] = {projects [i].c, tmp.set (i)};
		max_ind = max (max_ind, dp [i].first);

		//for (int j = 0 ; j <= n ; j ++)
		//{
		//	cout << dp [j].first << " ";
		//}
		//cout << "\ni = " << i << ": \n";
		for (int j = 0 ; j < i ; j ++)
		{
			for (int k = 0 ; k < n ; k ++)
				if (dp [j].second [k] == true and check (k, i))
					goto NEXT;
			//cout << "\t\t" << dp [i].first << " " << dp [j].first  << " + " <<  projects [i].c << "\n";
			if (dp [i].first < dp [j].first + projects [i].c)
			{
				bitset<5000> tmp = dp [j].second;
				dp [i] = {dp [j].first + projects [i].c, tmp.set (i)};
				max_ind = max (max_ind, dp [j].first + projects [i].c);
				//cout << "\t\t\t" << dp [j].first + projects [i].c << "\n";
			}
			NEXT:
			{}
		}
	}

	cout << max_ind << "\n";
	return 0;
}

