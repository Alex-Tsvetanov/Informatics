#include <iostream>
//#include <fstream>
#include <stdlib.h>

using namespace std;

//ifstream cin ("equations.in");
//ofstream cout ("equations.out");

double c [2048][2048], ans [2048];
double** D [2048];
int approx [2048], exact [2048];

double det (int n, double** mat)
{ 
	double d = 0;
	int c, subi, i, j, subj;
	double** submat = new double* [n];
	for (int i = 0 ; i < n ; i ++)
		submat [i] = new double [n];

	if (n == 2) 
	{
		return ((mat [0][0] * mat [1][1]) - (mat [1][0] * mat [0][1]));
	}
	else
	{  
		for (c = 0; c < n; c ++)
		{  
			subi = 0;  
			for(i = 1; i < n; i ++)
			{  
				subj = 0;
				for(j = 0; j < n; j ++)
				{    
					if (j == c)
					{
						continue;
					}
					submat [subi][subj] = mat [i][j];
					subj ++;
				}
				subi ++;
			}
			d = d + (((c % 2 == 0)?(1):(-1)) * mat [0][c] * det (n - 1, submat));
		}
	}
	for (int i = 0 ; i < n ; i ++)
		delete submat [i];
	delete submat;
	return d;
}

int main ()
{
	cin.tie (nullptr); 
	ios::sync_with_stdio (false);
	int n, m;
    cin >> m >> n;
	if (m < n)
	{
		cout << "1\n";
		for (int i = 0 ; i < n - 1 ; i ++)
			cout << "2 ";
		cout << "2\n";
		return 0;
	}
	for (int i = 0 ; i <= n ; i ++)
	{
		D [i] = new double* [n];
		for (int j = 0 ; j < n ; j ++)
		{
			D [i][j] = new double [n];
		}
	}
	for (int i = 0 ; i < m ; ++ i)
	{
        for (int j = 0 ; j < n ; ++ j)
		{
            cin >> c [i][j];
			for (int k = 0 ; k <= n ; k ++)
				D [k][i][j] = c [i][j];
        }
		cin >> exact [i] >> approx [i];
    }
	int s;
	cin >> s;
    for (int indS = 0 ; indS < s ; ++ indS)
	{
        for (int row = 0 ; row < m ; ++ row)
            cin >> c [row][n];
		if (m == n)
		{
			for (int i = 0 ; i < n ; i ++)
				for (int j = 0 ; j < n ; j ++)
					D [i][j][i] = c [j][n];
			for (int i = 0 ; i < n ; i ++)
				ans [i] = det (n, D [i]) / det (n, D [n]);
			for (int i = 0 ; i < n - 1 ; i ++)
				cout << (int)ans [i] << " ";
			cout << (int)ans [n - 1] << "\n----------------------------------\n";
		}
		else
		{

		}
	}
	for (int i = 0 ; i <= n ; i ++)
	{
		for (int j = 0 ; j < n ; j ++)
			delete[] D [i][j];
		delete[] D [i];
	}
    return 0;
}
