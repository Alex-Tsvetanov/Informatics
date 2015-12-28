//swap.cpp
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int find (vector <int>& v, int x)
{
	for (int i = 0 ; i < (int)v.size () ; i ++)
		if (v [i] == x)
			return i;
	return -1;
}

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	int N;
	cin >> N;
	vector <int> P;
	P.push_back (-1);
	vector <pair <int, int> > ans;
	for (int i = 0 ; i < N ; i ++)
	{
		int a;
		cin >> a;
		P.push_back (a);
	}
	for (int m = 1 ; m <= N ; m ++)
	{
		//cout << "m = " << m << ":\n";
		if (P [m] == m)
			continue;
		int j = find (P, m);
		//cout << "\t" << j << endl;
		while (j > m)
		{
			//cout << "\t\t" << j << endl;
			if (P [j - 1] != j)
			{
				swap (P [j - 1], P [j]);
				//for (int i = 1 ; i < P.size () ; i ++)
					//cout << P [i] << " ";
				//cout << endl;
				ans.push_back ({j - 1, j});
				j --;
			}
			else
			{
				int k = j - 1;
				
				while (k >= m and P [k] == k + 1)
				{
					k --;
				}

				//cout << "\t\t\t" << k << endl;

				if (k < m)
				{
					while (j > m)
					{
						swap (P [j], P [j - 1]);
						ans.push_back ({j - 1, j});
						j --;
					}
				}
				else
				{
					swap (P [j], P [j - 1]);
					ans.push_back ({j - 1, j});
					j --;
				}
				//cout << "\t\t\t " << j << endl;
			}
		}
	}
	cout << ans.size () << endl;
	for (auto& x : ans)
	{
		cout << x.first << " " << x.second << endl;
	}
}
