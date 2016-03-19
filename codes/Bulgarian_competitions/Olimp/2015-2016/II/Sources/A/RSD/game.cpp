#include <bits/stdc++.h>
#define endl '\n'

#define int long long

using namespace std;
const int MAXN = (int)(5e4) + 42;

struct point
{
	int x, y, rad;
	point() {x = 0; y = 0; rad = 0;}
	point(int _x, int _y, int _rad)
	{
		x = _x;
		y = _y;
		rad = _rad;
	}
};

double dist(point a, point b) { return sqrt((double)((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y
- b.y))); }

point p[MAXN];
int cM;
double val[MAXN], per[MAXN];

bool cmp(int a, int b)
{
	return val[a] < val[b];
}

int n, m, q;
point a[MAXN];
int s[MAXN], R[MAXN], sz = 0;

void read()
{
	cin >> n >> m >> q;
	for(int i = 0; i < n; i++)
	{
		int x, y, rad;
		cin >> x >> y >> rad;
		a[i] = point(x, y, rad);
	}

	for(int i = 0; i < m; i++)
	{
		int x, y, rad = 0;
		cin >> x >> y;
		p[i] = point(x, y, rad);
	}

	for(int i = 0; i < q; i++)
	{
		cin >> s[i];
		R[sz++] = s[i];
		R[sz++] = 2 * s[i];
	}	
}

int ans[20][MAXN];

int bin_search(int ra)
{
	int l = 0, r = n - 1, mid, ret = 0;
	double radi = ra;

	while(l <= r)
	{
		mid = (l + r) / 2; 
		if(val[mid] <= radi)
		{
			l = mid + 1;
			ret = mid + 1;
		}
		else
			r = mid - 1;
	}

	return ret;
}

void solve()
{
	for(int xx = 0; xx < m; xx++)
	{
		cM = xx;
		for(int i = 0; i < n; i++)
		{
			per[i] = i;
			val[i] = (double)a[i].rad + dist(p[cM], a[i]);
		}

		sort(per, per + n, cmp);
		
		for(int i = 0; i < sz; i++)
			ans[cM][R[i]] = bin_search(R[i]);
	}

	int answer = 0;
	int lastr = 1, currs = 0;
	for(int i = 0; i < q; i++)
	{
		if(lastr % 2 == 0) currs = 2 * s[i];
		else currs = s[i];

		int t = 0;
		for(int k = 0; k < m; k++)
			t += ans[k][currs];

		answer += t;
		lastr = t;
	}

	cout << answer << endl;
}

#undef int
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	read();
	solve();
	return 0;
}

