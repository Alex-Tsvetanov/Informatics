//#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

ifstream cin ("equations.in");
ofstream cout ("equations.out");

double c [2048][2048], ans [2048];
int approx [2048], exact [2048];

int main ()
{
	cin.tie (nullptr); 
	ios::sync_with_stdio (false);
	int n, m;
    cin >> m >> n;
	if (m != n)
	{
		cout << "1\n";
		for (int i = 0 ; i < n - 1 ; i ++)
			cout << "2 ";
		cout << "2\n";
		return 0;
	}
	for (int i = 0 ; i < n ; ++ i)
	{
        for (int j = 0 ; j < n ; ++ j)
		{
            cin >> c [i][j];
        }
		cin >> exact [i] >> approx [i];
    }
	int s;
	cin >> s;
    for (int indS = 0 ; indS < s ; ++ indS)
	{
        for (int row = 0 ; row < n ; ++ row)
		{
            cin >> c [row][n];
        }
    
		try
		{
			for (int i = 0 ; i < n ; ++ i)
			{
				int x;
				for (int j = i ; j < n ; ++ j)
				{
					if (c [j][i] != 0)
					{
						x = j;
						break;
					}
				}
			   
				swap (c [i], c [x]);

				for (int j = i + 1 ; j < n + 1 ; ++ j)
				{
					c [i][j] /= c [i][i];
				}

				c [i][i] = 1;

				for (int j = i + 1 ; j < n ; ++ j)
				{
					for (int k = i + 1 ; k < n + 1 ; ++ k)
					{
						c [j][k] -= c [i][k] * c [j][i];
					}
					c [j][i] = 0;
				}
			}

			for (int i = n - 1 ; i >= 0 ; -- i)
			{
				ans [i] = c [i][n];
				for (int j = n - 1 ; j > i ; -- j)
				{
					ans [i] -= c [i][j] * ans [j];
				}
			}
			
			cout << /*indS + */1 << "\n";
			for (int i = 0 ; i < n - 1 ; ++ i)
			{
				cout << (int)ans [i] << " ";
			}
			cout << (int)ans [n - 1] << "\n";
			break;
		}
		catch (...)
		{
			continue;
		}
	}
    return 0;
}
