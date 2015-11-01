#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
	int n;
	cin >> n;
	int* coins = new int [n];
	for (int i = 0 ; i < n ; i ++)
	{
		cin >> coins [i];
		coins [i] = -coins [i];
	}
	sort (coins, coins + n);
	int sum;
	cin >> sum;
	int ind = 0, br = 0;
	while (sum != 0)
	{
		if (-coins [ind] > sum)
		{
			cout << -coins [ind] << " x " << br << endl;
			ind ++;
			br = 0;
		}
		else
		{
			br ++;
			sum += coins [ind];
		}
	}
	cout << -coins [ind] << " x " << br << endl;
}
