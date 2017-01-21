#include <iostream>
//#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

//ifstream cin ("equations.in");
//ofstream cout ("equations.out");

int approx [2048], exact [2048];
bool skipped [2048];

struct polynom
{
	double Const;
	vector <double> k_x_i;

	polynom ()
	{
		Const = 0;
	}

	polynom (int vars)
	{
		Const = 0;
		k_x_i.resize (vars, 0);
	}

	double calc (const vector <double> & x_i)
	{
		//cout << k_x_i.size () << " " << x_i.size () << endl;
		double res = Const;
		for (int i = 0 ; i < (int)x_i.size () ; i ++)
			res += k_x_i [i] * x_i [i];
		return res;
	}
};

polynom c [2048][2048], ans [2048];
vector <double> b;

void elimination (int m , int n)
{
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
			c [i][j] = c [i][j] / c [i][i];
		}

		c [i][i].Const = 1;
		c [i][i].k_x_i.clear ();
		c [i][i].k_x_i.resize (m, 0);

		for (int j = i + 1 ; j < m ; ++ j)
		{
			skipped [j] = true;
			for (int k = i + 1 ; k < n + 1 ; ++ k)
			{
				c [j][k] = c [j][k] - c [j][i] * c [i][k];
				if (c [j][k] != 0)
					skipped [j] = false;
			}
			c [j][i].Const = 0;
			c [j][i].k_x_i.clear ();
			c [j][i].k_x_i.resize (m, 0);
		}
	}
	
	for (int i = 0 ; i < m ; ++ i)
	{
		num_of_independent -= skipped [i];
	}
	if (num_of_independent < n)
	{
		return;
	}
	for (int i = m - 1 ; i >= 0 ; -- i)
	{
		if (skipped [i])
			continue;
		ans [i] = c [i][n];
		for (int j = n - 1 ; j > i ; -- j)
		{
			ans [i] = ans [i] - c [i][j] * ans [j];
		}
	}
}

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
	for (int j = 0 ; j < n ; ++ j)
		ans [j].k_x_i.resize (m, 0);
	
	for (int i = 0 ; i < m ; ++ i)
	{
        for (int j = 0 ; j < n ; ++ j)
		{
			double a;
            cin >> a;
			c [i][j].Const = a;
			c [i][j].k_x_i.resize (m, 0);
        }
		c [i][n].k_x_i.resize (m, 0);
//		cout << "Resize" << endl;
		c [i][n].k_x_i [i] = 1;
//		cout << "Set i to 1" << endl;
		cin >> exact [i] >> approx [i];
    }

	cout << "Before elimination" << endl;
	elimination (m, n);
	cout << "After elimination" << endl;
	for (int row = 0 ; row < n ; ++ row, cout << "\n")
		for (int i = 0 ; i < m ; i ++)
		{
			cout << ans [row].k_x_i[i] << " ";
		}
	cout << "---------------------------------------\n";

	b.resize (m, 0);
	int s;
	cin >> s;
    for (int indS = 0 ; indS < s ; ++ indS)
	{
        for (int row = 0 ; row < m ; ++ row)
		{
            cin >> b [row];
        }
		cout << "Input b-s" << endl;
    
		cout << indS + 1 << "\n";
		for (int i = 0 ; i < n - 1 ; ++ i)
		{
			cout << (int)ans [i].calc (b) << " ";
		}
		cout << (int)ans [n - 1].calc (b) << "\n";
		return 0;
	}
	
	cout << 1 << "\n";
	for (int i = 0 ; i < n - 1 ; i ++)
		cout << ((i % 2) + 2)<< " ";
	cout << (((n - 1) % 2) + 2) << "\n";
	
	return 0;
}
