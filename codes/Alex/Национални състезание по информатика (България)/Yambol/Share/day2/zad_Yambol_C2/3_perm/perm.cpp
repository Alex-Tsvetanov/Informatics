#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};

// ========================================================================= //

const int N = 100179;

int n, m;
vector < int > e[N], ei[N];
int tt;
int a[N];
int cnt, ans;

void dfs(int v)
{
	if (a[v] != -1)
		return;
	a[v] = -2;
	for (int nv : e[v])
		dfs(nv);
	a[v] = --tt;
}

int main()
{
    ios::sync_with_stdio(false);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		--x;
		--y;
		e[x].push_back(y);
		ei[x].push_back(i);
	}

	tt = n;
	memset(a, -1, sizeof(a));
	for (int i = 0; i < n; ++i)
		dfs(i);
	
	cnt = ans = 0;
	for (int v = 0; v < n; ++v)
		for (int i = 0; i < sz(e[v]); ++i)
			if (a[e[v][i]] == a[v] + 1)
			{
				++cnt;
				ans = max(ans, ei[v][i] + 1);
			}
	if (cnt == n - 1)
		cout << ans << "\n";
	else
		cout << "-1\n";

    return 0;
}
