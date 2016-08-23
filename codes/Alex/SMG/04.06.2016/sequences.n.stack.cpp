#include <iostream>
#include <stack>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	int* arr = new int [n];
	int* ans = new int [n];
	stack < pair <int, int> > st;
	for (int i = 0 ; i < n ; i ++)
	{
		cin >> arr [i];
		ans [i] = 0.0f/0.0f;
		while (!st.empty ())
		{
			if (st.top ().first >= arr [i])
				st.pop ();
			else
			{
				ans [i] = st.top ().second;
				break;
			}
		}
		st.push ({arr [i], i});
	}
	for (int i =  0 ; i < n ; i ++)
		cout << ans [i] << " ";
	cout << std::endl;
	delete[] arr;
	delete[] ans;
}
