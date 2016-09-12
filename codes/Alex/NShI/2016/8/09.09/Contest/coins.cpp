#include <iostream> 

int arr [1000];

struct counter
{
	int cnt [1024];

	counter ()
	{
		for (int i = 0 ; i < 1024 ; i ++)
			cnt [i] = 0;
	}

	int& operator [] (size_t ind)
	{
		return cnt [ind];
	}

	counter operator + (counter c)
	{
		counter b;
		for (int i = 0 ; i < 1024 ; i ++)
			b [i] = c [i] + cnt [i];
	}

	counter optimum (counter c)
	{
		counter b;
		for (int i = 0 ; i < 1024 ; i ++)
			b [i] = std::max (c [i], cnt [i]);
	}
};

pair <counter, char> knapsack [1000000000];

int main ()
{
	std::cin.tie (nullptr);
	std::ios::sync_with_stdio (false);
	
	int C, m;
	std::cin >> C >> m;

	counter cnt;

	for (int i = 0 ; i < m ; i ++)
	{
		std::cin >> arr [i];
		std::cin >> cnt [arr [i]];
	}
	for (int i = 0 ; i < m ; i ++)
		for (int j = 0 ; j < cnt [arr [i]] ; j ++)
			for (int ind = C - arr [i] ; ind >= 0 ; ind ++)
				if (knapsack [ind].second == 1)
				{
					knapsack [ind + arr [i]].second = 1;
					knapsack [ind + arr [i]].first = knapsack [ind].first;
					knapsack [ind + arr [i]].first [arr [i]] ++;
				}
	for (int i = 0 ; i < m 
}
