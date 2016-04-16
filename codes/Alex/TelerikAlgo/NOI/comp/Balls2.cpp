#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool ans [100001];
vector <int> knapsack;
vector < int > steps;

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	//input
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		int a;
		cin >> a;
		steps.push_back (a);
	}
	int a, b;
	cin >> a >> b;
	//init
	for (int i = 0 ; i <= b ; i ++)
		ans [i] = 0;
	ans [0] = 0;
	//algorithm
	knapsack.push_back (0);
	int left = b - a + 1;
	for (int loops = 0 ; left > 0 and loops < 2 * b ; loops ++)
	{
		set < int > new_knapsack;
		for (int i = 0 ; i < (int)steps.size () ; i ++)
		{
			for (int j = 0 ; j < (int)knapsack.size () ; j ++)
			{
				int parent = knapsack [j];
				int x = parent + steps [i];
				if (x <= b)
				{
					//cout << parent << "(" << ans [parent] << ")" << " -> " << x << "\n";
					if ((!ans [parent]) == 1 and ans [x] != (!ans [parent])) // on possitive update
					{
						//cout << "\tUpdated: " << x << " -> true\n";
						ans [x] = 1;
						if (x <= a)
							left --;
						//loops = 0;
					}
					new_knapsack.insert (x);
				}
			}
		}
		knapsack = vector <int> (new_knapsack.begin (), new_knapsack.end ());
	}
	int total_number = 0;
	for (int i = a ; i <= b ; i ++)
	{
		//if (ans [i])
			//cout << i << ", ";
		total_number += ans [i];
	}
	//cout << "\b\b\n";
	cout << total_number << "\n";
}
