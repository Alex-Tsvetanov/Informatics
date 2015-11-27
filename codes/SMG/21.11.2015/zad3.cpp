#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>

using namespace std;

int num_of_digits (int N)
{
	return ((N < 10) ? 1 : ((N < 100) ? 2 : ((N < 1000) ? 3 : ((N < 10000) ? 4 : ((N < 100000) ? 5 : ((N < 1000000) ? 6 : 7))))));
}

struct my_stack
{
private:
	stack < char > st;
	int num_of_erased;
public:
	my_stack ()
	{
		st = stack < char > ();
		num_of_erased = 0;
	}

	char push (char c, int k = -2)
	{
		if (!st.empty ())
		{
			if (c == st.top ())
			{
				st.pop ();
				num_of_erased += 2;
			}
			else
				st.push (c);
		}
		else
			st.push (c);
		if ((int)st.size () + num_of_erased == k or (int)st.size () + num_of_erased == k + 1)
		{
			return c;
		}
		else
			return '\0';
	}
	void clear ()
	{
		num_of_erased = 0;
		while (!st.empty ())
			st.pop ();
	}
};

my_stack str;

int64_t k;

char f_order (int64_t);
char f_reversed (int64_t);

char f_order (int64_t n)
{
	if (n == 1)
	{
		return str.push ('1', k);
	}
	string a;
	{
		stringstream ss;
		ss << n;
		a = ss.str ();
	}
	for (auto& x : a)
	{
		char c = str.push (x, k);
		if ( c != '\0' )
		{
			return c;
		}
	}
	char c;
	c = f_order (n - 1);
	if ( c != '\0' )
		return c;
	c = f_reversed (n - 1);
	return c;
}

char f_reversed (int64_t n)
{
	if (n == 1)
	{
		return str.push ('1', k);
	}
	string a;
	{
		stringstream ss;
		ss << n;
		a = ss.str ();
		reverse (a.begin (), a.end ());
	}
	for (auto& x : a)
	{
		char c = str.push (x, k);
		if ( c != '\0' )
		{
			return c;
		}
	}
	char c;
	c = f_reversed (n - 1);
	if ( c != '\0' )
		return c;
	c = f_order (n - 1);
	return c;
}

int main ()
{
	int64_t N;
	cin >> N >> k;
	k ++;
	cout << f_order (N) << endl;
////for (k = 1 ; k <= ((1<<N) - 1) ; k ++)
////{
////	cout << f_order (N);
////	cout.flush ();
////	str.clear ();
////}
}
