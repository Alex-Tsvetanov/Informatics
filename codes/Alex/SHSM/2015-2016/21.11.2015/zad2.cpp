#include <iostream>

using namespace std;

int f (int N, int K)
{
	if (K == 0)
		return N;
	if (K >= (1 << (N - 1)))
		return f (N - 1, K - (1 << (N - 1)));
	else
		return f (N - 1, K - 1);
}

int main ()
{
	int N, K;
	cin >> N >> K;
	cout << f (N, K) << endl;
}
