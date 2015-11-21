#include <iostream>
#include <sstream>

using namespace std;

struct my_int
{
	string str;
	my_int minus1 ()
	{
		int i = str.size ();
		while (str [i] == '0')
			str [i --] = '9';
		str [i] --;
		return *this;
	}
};

constexpr string f (my_int N)
{
	return ((N.str == "1")?"1":(N.str + string (f (N.minus1 ()), 2)));
}

int main ()
{
	int N, K;
	cin >> N >> K;
	string line;
	for (int N = 1 ; N <= 10 ; N ++)
	{
		line = f (N);
	}
}
