#include <iostream>
#include <string>
#include <vector>

using namespace std;

string a;

int ans (int s, int e)
{
	if (a [s] == '0')
		return 0;
	if (s > e)
		return 0;
	if (s == e)
	{
		return 1;
	}
	int ans1 = 0;
	if (a [s + 1] != '0') 
		ans1 += ans (s + 1, e);
	if (a [s + 1] == '1')
		ans1 += ans (s + 2, e);
	if (a [s + 1] == '2' and a [s + 2] < '7')
		ans1 += ans (s + 2, e);


	return ans1;
}

int main ()
{
	cin >> a;
	cout << ans (0, a.size ()) << "\n";;


}
