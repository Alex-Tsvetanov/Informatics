//Solved by Recursion
#include <iostream>

using namespace std;

int n;
int variant = 1;

void all (int opened, int closed)
{ 
	if (opened == n and closed == n)
	{
		variant ++;
		return ;
	}
	if (opened + closed == 2 * n)
	{
		return ;
	}
	if (opened == closed)
	{
		all (opened + 1, closed);
	}
	if (opened < closed)
		return ;
	if (opened > closed)
	{
		all (opened + 1, closed);
		all (opened, closed + 1);
	}
}

int main ()
{
	cin >> n;
	all (0, 0);
	cout << variant << "\n";
}
