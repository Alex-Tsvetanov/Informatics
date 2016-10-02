#include <iostream> 
#include <algorithm>

#define int int64_t

int arr [300];
int mins [300][300];

int n, k;

int sum (int ind, int Sum = 0, int lastR = -1)
{
	if (ind == k - 1)
	{
		return Sum + mins [lastR + 1][n - 1];
	}

	int ans = -1;

	for (int i = lastR + 1 ; i < n ; i ++)
		ans = std::max (ans, sum (ind + 1, Sum + mins [lastR + 1][i], i));
	
	return ans;
}

int32_t main ()
{
	std::cin.tie (nullptr);
	std::ios::sync_with_stdio (false);
	std::cin >> n >> k;

	for (int i = 0 ; i < n ; i ++)
		std::cin >> arr [i];
	
	for (int i = 0 ; i < n ; i ++)
	{
		mins [i][i] = arr [i];
		for (int j = i + 1 ; j < n ; j ++)
			mins [i][j] = std::min (arr [j], mins [i][j - 1]);
	}

	std::cout << sum (0, 0, -1) << "\n";
}
