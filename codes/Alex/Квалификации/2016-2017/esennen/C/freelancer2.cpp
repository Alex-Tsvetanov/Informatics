#include <iostream>
const int MAXV = 5000;

#define int long long
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

project projects [MAXV];

int dp [MAXV];
bool vis [MAXV][MAXV];

bool check (int i, int j)
{
	for (int k = 1 ; k < i ; k ++)
		if (vis [j][k]/* or true*/)
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
	return true;
}

int32_t main ()
{
	int n;
	cin >> n;

	for (int i = 1 ; i <= n ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		b = a + (b - 1);

		projects [i] = (project (a, b, c));
	}
////for (int i = 1 ; i <= n ; i ++, cout << "\n")
////for (int j = 1 ; j <= n ; j ++)
////	cout << check (i, j) << " ";

	int max_ans = 0;
	dp [0] = 0;
	for (int k = 1 ; k <= n ; k ++)
		vis [0][k] = 0;
	for (int i = 1 ; i <= n ; i ++)
	{
		{
			dp [i] = projects [i].c;
			for (int k = 1 ; k <= i ; k ++)
				vis [i][k] = (k == i);
		}
		for (int j = 1 ; j < i ; j ++)
			if (check (i, j))
			{
				if (dp [i] < dp [j] + projects [i].c)
				{
					dp [i] = (dp [j] + projects [i].c);
					for (int k = 1 ; k <= i ; k ++)
						vis [i][k] = vis [j][k] or (k == i);
				}
			}

		max_ans = max (max_ans, dp [i]);
	}
	cout << max_ans << "\n";
}
