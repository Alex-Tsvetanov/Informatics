#include <iostream>

using namespace std;

#include <set>
int main ()
{
	set <pair <int, int> > s;
	int n;
	cin >> n;
	int* arr = new int [n];
	int* ans = new int [n];
	for (int i = 0 ; i < n ; i ++)
	{
		cin >> arr [i];
		auto it = s.lower_bound (arr [i]);
		if (it != s.begin ())
		{
			it --;
			ans [i] = it->second;
		}
		else
			ans [i] = 0.0f/0.0f;

		s.insert ({arr [i], i});
	}
	for (int i =  0 ; i < n ; i ++)
		cout << ans [i] << " ";
	cout << std::endl;
	delete[] arr;
	delete[] ans;
}
