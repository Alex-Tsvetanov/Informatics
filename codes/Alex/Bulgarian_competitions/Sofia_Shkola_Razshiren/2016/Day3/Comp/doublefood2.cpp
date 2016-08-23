#include <iostream>
#include <vector>

using namespace std;

struct doublefood
{
	int a, b, c;
};

istream& operator >> (istream& in, doublefood d)
{
	in >> d.a >> d.b >> d.c;
	return in;
}

vector < doublefood > doublefoods;
int ans = -26*1e8;
bool blq = false;

void rec (int ind, int sum1 = 0, int sum2 = 0, int sum3 = 0)
{
	if (ind == (int)doublefoods.size ())
	{
		if (sum1 == sum2 and sum2 == sum3)
		{
			ans = max (ans, sum1);
			blq = true;
		}
		return;
	}
	rec (ind + 1, sum1 + doublefoods [ind].a, sum2 + doublefoods [ind].b, sum3);
	rec (ind + 1, sum1 + doublefoods [ind].a, sum2, sum3 + doublefoods [ind].c);
	rec (ind + 1, sum1, sum2 + doublefoods [ind].b, sum3 + doublefoods [ind].c);
}

int main ()
{
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		doublefood d;
		cin >> d;
		doublefoods.push_back (d);
	}
	rec (0);	
	if (!blq)
		cout << "Impossible\n";
	else
		cout << ans << "\n";
}
