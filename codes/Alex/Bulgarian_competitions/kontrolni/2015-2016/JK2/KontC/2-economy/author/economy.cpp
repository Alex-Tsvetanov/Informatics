# include <cstdio>

using namespace std;

const int MAX_N = 1024;
const int MAX_B = 1024;

int a, b, c;
int n, d[MAX_N];
int e[MAX_B];
int par[MAX_N][MAX_B];

int ansn;
int ans[MAX_N];

void find_ans (int idx, int sum)
{
	if (idx == 0)
		return;
	find_ans (idx - 1, par[idx][sum]);	
	if (par[idx][sum] != sum)
		ans[ansn ++] = idx;
}

int main ()
{
	int i, s;
	scanf ("%d%d%d", &a, &b, &c);
	scanf ("%d", &n);
	for (i = 1; i <= n; i ++)
		scanf ("%d", &d[i]);
		
	if (a > c)
	{
		printf ("%d\n", a);
		printf ("0\n");
		return 0;
	}
	
	e[0] = 1;
	for (i = 1; i <= n; i ++)
	{
		for (s = b - 1; s >= 0; s --)
		{
			par[i][s] = -1;
			if (s - d[i] >= 0 && e[s - d[i]])
			{
				par[i][s] = s - d[i];
				e[s] = 1;
			}
			else
			{
				if (e[s])
					par[i][s] = s;
			}
		}
	}
	
				
	
	int lamp = 0;
	
	for (s = 0; s < b; s ++)
	{
		if (e[s] && s + a > c)
		{
			printf ("%d\n", s + a);
			find_ans (n, s);
			lamp = 1;
			break;
		}
	}
	
	
	if (lamp == 0)
	{
		printf ("%d\n", a + b);
		printf ("-1\n");
		return 0;
	}
	
	printf ("%d\n", ansn);
	if(ansn)printf ("%d", ans[0]);
	for (i = 1; i < ansn; i ++)
		printf (" %d", ans[i]);
	printf ("\n");

	return 0;
}

