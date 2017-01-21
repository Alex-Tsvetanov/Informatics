#include <iostream>
#include <math.h>

using namespace std;

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
	int n;
	cout << "enter the order of matrix ";
	cin >> n;
	double** mat = new double* [n];
	for (int i = 0 ; i < n ; i ++)
		mat [i] = new double [n];
	int i, j;
	cout << "enter the elements:" << endl;
	for (i = 0 ; i < n ; i ++)
	{
		for (j = 0 ; j < n ; j ++)
		{
			cin >> mat [i][j];
		}
	}
	cout << "\ndeterminant" << det (n, mat) << "\n";
	for (int i = 0 ; i < n ; i ++)
		delete mat [i];
	delete mat;
}
