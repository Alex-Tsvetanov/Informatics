#include <iostream>
#include <vector>

using namespace std;

vector <int> for_print;

void rec (int n, int k)
{
	if (for_print.size () == (size_t)k)
	{
		cout << "(";
		for (int i = 0 ; i < k - 1 ; i ++)
			cout << for_print [i] << " ";
		cout << for_print [k - 1] << ")"<< endl;
		return;
	}
	for (int i = 1 ; i <= n ; i ++)
	{
		for_print.push_back (i);
		rec (n, k);
		for_print.pop_back ();
	}
}

int main ()
{
	int n, k;
	cin >> n >> k;
	rec (n, k);
}
