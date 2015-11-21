#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string f (int N)
{
	if (N == 1)
		return "1";
	stringstream ss;
	string prev = f (N - 1);
	ss << N << prev << prev;
	return ss.str ();
}

int main ()
{
	int N, K;
	vector < int > pos [9];
	for (N = 1 ; N < 7 ; N ++)
	{
		cout << f (N) << endl;
	}
}
