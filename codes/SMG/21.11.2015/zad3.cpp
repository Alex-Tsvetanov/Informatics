#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int num_of_digits (int N)
{
	return ((N < 10) ? 1 : ((N < 100) ? 2 : ((N < 1000) ? 3 : ((N < 10000) ? 4 : ((N < 100000) ? 5 : ((N < 1000000) ? 6 : 7))))));
}

string f (int N)
{
	if (N == 1)
		return "1";
	stringstream ss;
	string prev = f (N - 1);
	ss << N << prev << prev;
	return ss.str ();
}

unsigned long long 

int main ()
{
	int N, K;
	cin >> N >> K
	for ( ; N > 1 ; N --)
	{
		if (K < num_of_digits (N))
		{
			stringstream ss;
			ss << N;
			cout << ss.str ()[K];
			return 0;
		}
		else
		{
			K = (K - num_of_digits (N)) % lens [N - 1];
		}
	}
	cout << 1 << endl;
}
