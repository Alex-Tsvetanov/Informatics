//Solved by Catalan Numbers
#include <iostream>

using namespace std;

using T = uint64_t;

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	int n;
	cin >> n;
	
	T X (n);
	T curr = 1;

	for (T n = 1 ; n < X ; n = n + 1)
	{
		curr = ((T)4 * n + 2) * curr / (n + 2);
	}
	cout << curr << endl;
}
