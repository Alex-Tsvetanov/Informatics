//#include <iostream>
#include <fstream>

using namespace std;

ifstream cin ("phonebook.in");
ofstream cout ("phonebook.out");

int main ()
{
	int n;
	cin >> n;
	string prev, curr;

	for (int i = 0 ; i < n ; i ++)
	{
		cin >> curr;
		if (prev > curr)
		{
			cout << i << "\n";
			return 0;
		}
		prev = curr;
	}
}
