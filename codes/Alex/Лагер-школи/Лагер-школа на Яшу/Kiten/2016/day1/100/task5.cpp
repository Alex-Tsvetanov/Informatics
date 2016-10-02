#include <iostream>

using namespace std;

const int mod = 1e9;
int dp [1000000];
bool vis [1000000];

int main ()
{
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 0 ; i < n ; i ++)
	{
		cin >> vis [i];
	}

	int rolling_sum = 1;
	dp [0] = 1;
	for (int i = 1 ; i < n ; i ++)
	{
		if (vis [i])
			dp [i] += rolling_sum;
		rolling_sum += dp [i];
		if (i >= (b - a - 1))
			rolling_sum -= dp [i - (b - a - 1)];
	}
}
