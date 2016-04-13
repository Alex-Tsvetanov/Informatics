#include <iostream>
#include <set>

using namespace std;

uint64_t var [26];

uint64_t vars (int n)
{
	uint64_t ans = 1;
	for (int i = 0 ; i < n ; i ++)
		ans *= (26 - n - i);
	return ans;
}

string ans;
int n;
int k;
set <char> s;

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	cin >> n >> k;
	for (char i = 'A' ; i <= 'Z' ; i ++)
		s.insert (i);
	ans = string (n, ' ');
	for (int i = 0 ; i < n ; i ++)
	{
		int ind = k / vars (n - i);
		cout << k << " " << ind << " " << ans << " -> ";
		for (auto& it : s)
		{
			if (ind == 0)
			{
				ans [i] = it;
				break;
			}
			ind --;
		}
		cout << ans << "\n";
		s.erase (ans [i]);
		k %= vars (n - i);
	}
	cout << ans << "|\n";
}
