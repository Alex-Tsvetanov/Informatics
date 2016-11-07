#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
const int MAXN = (1 << 20);
const long long base = 27;
const long long mod = (long long)1e9 + 9;

int n;
string s;

void read()
{
	cin >> s;
	n = s.size();
}

long long pw[MAXN], hl[MAXN], hr[MAXN];
int dp[MAXN];

inline long long get_hl(int l, int r)
{
	return (hl[r] - (hl[l - 1] * pw[r - l + 1]) % mod + mod) % mod;
}

inline long long get_hr(int l, int r)
{
	return (hr[l] - (hr[r + 1] * pw[r - l + 1]) % mod + mod) % mod;
}

void solve()
{
	dp[0] = 0;
	pw[0] = 1;
	for(int i = 1; i <= n + 1; i++)
		pw[i] = (pw[i - 1] * base) % mod;

	hl[0] = 0;
	for(int i = 1; i <= n; i++)
		hl[i] = (hl[i - 1] * base + (long long)(s[i - 1] - 'a' + 1)) % mod;
	
	hr[n + 1] = 0;
	for(int i = n; i >= 1; i--)
		hr[i] = (hr[i + 1] * base + (long long)(s[i - 1] - 'a' + 1)) % mod;

	for(int i = 1; i <= n; i++)
	{
		if(i % 2 == 0)
			if(get_hl((i / 2) + 1, i) == get_hr(1, i / 2))
			{
				dp[i] = 1;
				continue;
			}

		dp[i] = dp[i - 1] + 1;
		for(int len = 1; i - 1 >= (2 * len); len++)
		{
			if(get_hl(i - len + 1, i) == get_hr(i - 2 * len + 1, i - len))
				dp[i] = min(dp[i], dp[i - 2 * len] + 1);
			if(get_hl(i - len + 1, i) == get_hr(i - 2 * len, i - len - 1))
				dp[i] = min(dp[i], dp[i - 2 * len - 1] + 1);
		}
	}	

	cout << dp[n] - 1 << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	read();
	solve();
	return 0;
}

