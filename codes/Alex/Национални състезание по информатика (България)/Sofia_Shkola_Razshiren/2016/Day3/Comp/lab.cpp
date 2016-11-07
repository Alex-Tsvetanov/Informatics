#include <iostream>

using namespace std;

void rec ()
{
	string a;
	cin >> a;
	if (a == "BLOCKED")
		return ;
	for (auto& x : {"SOUTH", "WEST", "NORTH", "EAST"})
	{
		cout << x << "\n";
		cout.flush ();
		rec ();
	}
}

int main ()
{
	for (auto& x : {"SOUTH", "WEST", "NORTH", "EAST"})
	{
		cout << x << "\n";
		cout.flush ();
		rec ();
	}
	cout << "DONE\n";
	cout.flush ();
}
