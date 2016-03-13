#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

bool ans (string A);

int main ()
{
	int n;
	cin >> n;
	string A;
	getline (cin, A);
	for (int i = 0 ; i < n ; i ++)
	{
		getline (cin, A);
		if (ans (A) == 0)
			cout << "No\n";
		else
			cout << "Yes\n";
	}
}

bool ans (string A)
{
	int n = 1;
	for (int i = 0 ; i < (int)A.size () ; i ++)
		n += (A [i] == ' ');
	stringstream ss;
	ss << A;
	int sum = 0;
	int* arr = new int [n];
	for (int i = 0 ; i < n ; i ++)
	{
		ss >> arr [i];
		//cout << "reading: " << arr [i] << "\n";
		sum += arr [i];
	}
	sort (arr + 0, arr + n); 
	if (sum % 3 != 0)
		return 0;
	else
	{
		vector < vector < size_t > >* knapsack = new vector <vector <size_t> > [sum / 3 + 1];
		knapsack [0] = {{0}};
		bool* visited = new bool [sum / 3 + 1];
		for (int i = n - 1 ; i >= 0 ; i --)
		{
//			cout << arr [i] << ":\n";
			for (int j = sum / 3 ; j >= 0 ; j --)
			if (visited [j])
			{
				auto x = j;
//				cout << "\tx = " << x << "\n"; 
				if (x + arr [i] <= sum / 3)
				{
					for (auto& f : knapsack [x])
					{
						knapsack [x + arr [i]].push_back (f);
						knapsack [x + arr [i]][knapsack [x + arr [i]].size ()].push_back (arr [i]);
					}
				}
			}
		}
		//cout << knapsack [sum / 3].size () << "\n"; 
		for (int i = 0 ; i < (int)knapsack [sum / 3].size () ; i ++)
			for (int j = i + 1 ; j < (int)knapsack [sum / 3].size () ; j ++)
			{
				for (int k = j + 1 ; k < (int)knapsack [sum / 3].size () ; k ++)
				{
					vector < int > a;
					for (auto& x : knapsack [sum / 3][i])
						a.push_back (x);
					for (auto& x : knapsack [sum / 3][j])
						a.push_back (x);
					for (auto& x : knapsack [sum / 3][k])
						a.push_back (x);

					sort (a.begin (), a.end ());

					for (int i = 0 ; i < (int)a.size () ; i ++)
						if (a [i] != arr [i])
							goto Break;
					return 1;
				}
				Break:
				{}
			}
	}
	return 0;
}
