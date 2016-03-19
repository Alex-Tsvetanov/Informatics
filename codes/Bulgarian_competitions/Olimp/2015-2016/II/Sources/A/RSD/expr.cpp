#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
const int MAXN = (1 << 10);
const int OFFSET = (1 << 10);

int n, m;
string s;

void read()
{
	cin >> s;
	n = s.size();
}

int v[MAXN], a[MAXN];
int last[MAXN];
int pos[OFFSET * 2];

int rec(int l, int r)
{
	if(l == r) return v[a[l]];
	
	if(s[r] == ')') 
	{
		if(last[r] == l) return rec(l + 1, r - 1);
		return !(rec(l, last[r] - 1) && rec(last[r] + 1, r - 1));
	}

	return !(rec(l, r - 1) && (v[a[r]]));
}

void solve()
{
	int b = 0;
	for(int i = 0; i < n; i++)
		if(s[i] == '(' || s[i] == ')')
		{
			b = b + ((s[i] == '(') ? (1) : (-1));
			if(s[i] == ')') last[i] = pos[b + OFFSET + 1];
			else pos[b + OFFSET] = i;
		}
		else a[i] = s[i] - 'a';

	string ss;
	while(true)
	{
		cin >> ss;
		if(ss == "2") break;
		for(int i = 0; i < ss.size(); i++)	
			v[i] = ss[i] - '0';

		cout << rec(0, n - 1);
	}

	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	read();
	solve();
	return 0;
}

