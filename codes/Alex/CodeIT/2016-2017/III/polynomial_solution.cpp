#include <fstream>
#include <ctime>

using namespace std;

ifstream cin ("equations.in");
ofstream cout ("equations.out");

double c [2048][2048], ans [2048];
int approx [2048], exact [2048];
bool skipped [2048];

int main ()
{
	cin.tie (nullptr); 
	ios::sync_with_stdio (false);
	int n, m;
    cin >> m >> n;
	if (m < n)
	{
		cout << 1 << "\n";
		for (int i = 0 ; i < n - 1 ; i ++)
			cout << ((i % 2) + 2)<< " ";
		cout << (((n - 1) % 2) + 2) << "\n";
		return 0;
	}
	for (int i = 0 ; i < m ; ++ i)
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
        for (int row = 0 ; row < m ; ++ row)
		{
            cin >> c [row][n];
        }
    
		int num_of_independent = n;
		for (int i = 0 ; i < n ; ++ i)
		//for each variable
		{
			int x = -1;
			for (int j = i ; j < m ; ++ j) 
			// find equation with coeficient not equals to 0
			{
				if (c [j][i] != 0)
				{
					x = j;
					break;
				}
			}

			if (x == -1)
			{
				continue;
			}
		   
			swap (c [i], c [x]);
			swap (skipped [i], skipped [x]);
			// swap i-th and x-th rows

			for (int j = i + 1 ; j <= n ; ++ j)
			{
				c [i][j] /= c [i][i];
			}

			c [i][i] = 1;

			for (int j = i + 1 ; j < m ; ++ j)
			{
				skipped [j] = true;
				for (int k = i + 1 ; k < n + 1 ; ++ k)
				{
					c [j][k] -= c [i][k] * c [j][i];
					if (c [j][k] != 0)
						skipped [j] = false;
				}
				c [j][i] = 0;
			}
		}
		{
			for (int i = 0 ; i < m ; ++ i)
			{
				num_of_independent -= skipped [i];
			}
			if (num_of_independent < n)
			{
				continue;
			}
		}
		{
			for (int i = m - 1 ; i >= 0 ; -- i)
			{
				if (skipped [i])
					continue;
	//			cout << "from " << i << "-th\n";
				ans [i] = c [i][n];
				for (int j = n - 1 ; j > i ; -- j)
				{
					ans [i] -= c [i][j] * ans [j];
				}
	//			cout << "\t" << ans [i] << "\n";
			}
			cout << indS + 1 << "\n";
			for (int i = 0 ; i < n - 1 ; ++ i)
			{
				cout << (int)ans [i] << " ";
			}
			cout << (int)ans [n - 1] << "\n";
			return 0;
		}
	}
	{
		cout << 1 << "\n";
		for (int i = 0 ; i < n - 1 ; i ++)
			cout << ((i % 2) + 2)<< " ";
		cout << (((n - 1) % 2) + 2) << "\n";
	}
	return 0;
}
