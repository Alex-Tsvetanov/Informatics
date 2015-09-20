#include <iostream>
#include <vector>

using namespace std;

vector <int> for_print;

void rec (int n)
{
	if (for_print.size () == (size_t)n)
	{
		for (auto& x : for_print)
			cout << x << " ";
		cout << endl;
		return;
	}
	for (int i = 1 ; i <= n ; i ++)
	{
		for_print.push_back (i);
		rec (n);
		for_print.pop_back ();
	}
}

int main ()
{
	int n;
	cin >> n;
	rec (n);
}
