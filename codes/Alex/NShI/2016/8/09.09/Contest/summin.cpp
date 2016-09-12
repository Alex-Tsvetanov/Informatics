#include <iostream> 
#include <algorithm>

#define int int64_t

int arr [300];
int mins [300][300];
//     groups to_ind
int sums [300][300];

int n, k;

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
	int groups = 1;
		for (int to_ind = 0 ; to_ind < n ; to_ind ++)
				sums [groups][to_ind] = mins [0][to_ind];

	for (groups = 2 ; groups <= k ; groups ++)
	{
			for (int prevInd = 0 ; prevInd < n ; prevInd ++)
				for (int to_ind = prevInd + 1 ; to_ind < n ; to_ind ++)
					sums [groups][to_ind] = std::max (sums [groups][to_ind], sums [groups - 1][prevInd] + mins [prevInd + 1][to_ind]);
	}

	std::cout << sums [k][n - 1] << "\n";
}
