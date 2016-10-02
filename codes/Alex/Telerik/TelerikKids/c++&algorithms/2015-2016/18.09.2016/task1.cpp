#include <iostream>
#include <algorithm>

using namespace std;

int positions [64];

double mem [64][64];

double solve (int curr

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	
	int S, E;
	cin >> S >> E;
	
	int N;
	cin >> N;
	for (int i = 0 ; i < N ; i ++)
		cin >> positions [i];

	sort (positions, positions + N);
}
