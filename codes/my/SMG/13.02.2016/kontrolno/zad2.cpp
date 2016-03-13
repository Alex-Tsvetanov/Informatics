#include <iostream>
#include <stdlib.h>

using namespace std;

string ans;
int n;
int k;
int ind1;
string rec (int n1)
{
	if (n1 == 0)
	{
		ind1 ++;
		if (k == ind1)
		{
			cout << ans << "\n";
			return ans;;
		}
		else
			return "";
	}
	for (char i = 'A' ; i <= 'Z' ; i ++)
	{
		bool L = 1;
		for (int j = 0 ; j < n - n1 and L ; j ++)
			if (i == ans [j])
				L = 0;
		if (L == 1)
		{
			ans [n - n1] = i;
			string h = 
			rec (n1 - 1);
			if (h != "")
				return h;
		}
	}
	return "";
}

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	cin >> n >> k;
//	for (k = 1 ;  ; k ++)
	{
//		cout << k << " -> ";
		ans = string (n, ' ');
		rec (n);
		ind1 = 0;
	}
}
