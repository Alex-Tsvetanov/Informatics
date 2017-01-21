#include<iostream>
#include<iomanip>

using namespace std;

int exact [2000];
int aprox [2000];

int main ()
{
	int n, i, j, k;
////cout.precision (4);
////cout.setf (ios::fixed);
	cin >> n;
	float a [n][n + 1], x [n];
	for (i = 0 ; i < n ; i ++)
		for (j = 0 ; j <= n ; j ++)    
			cin >> a[i][j];

	for (i = 0 ; i < n ; i ++)
		for (k = i + 1 ; k < n ; k ++)
			if (a [i][i] < a [k][i])
				for (j = 0 ; j <= n ; j ++)
				{
					double temp = a [i][j];
					a [i][j] = a [k][j];
					a [k][j] = temp;
				}

////for (i = 0 ; i < n ; i ++)
////{
////	for (j = 0 ; j <= n ; j ++)
////		cout << a [i][j] << setw (16);
////	cout << "\n";
////}    
    for (i = 0 ; i < n - 1 ; i ++)
		for (k = i + 1 ; k < n ; k ++)
		{
			double t = a [k][i] / a [i][i];
			for (j = 0 ; j <= n ; j ++)
				a [k][j] = a [k][j] - t * a [i][j];
		}

////cout<<"\n\nThe matrix after gauss-elimination is as follows:\n";
////for (i=0;i<n;i++)            //print the new matrix
////{
////	for (j=0;j<=n;j++)
////		cout<<a[i][j]<<setw(16);
////	cout<<"\n";
////}

	for (i = n - 1 ; i >= 0 ; i --)
	{
		x [i] = a [i][n];
		for (j = 0 ; j < n ; j ++)
			if (j != i)
				x [i] = x [i] - a [i][j] * x [j];
		x [i] = x [i] / a [i][i];
	}

	cout << 1 << endl;
	for (i = 0 ; i < n - 1 ; i ++)
		cout << x [i] << " ";
	cout << x [n - 1] << endl;
	return 0;
}

