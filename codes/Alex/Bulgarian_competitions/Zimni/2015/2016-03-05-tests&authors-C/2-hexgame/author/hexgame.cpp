//task: hexgame
//author: Tsvetan Angelov
#include<cstdio>
using namespace std;

const int INF = 300010;

int min(int a, int b, bool &f)
{
	if (b < a) 
	{
		f = true; 
		return b;
	}
	return a;
}

int main()
{
	int res[2][6] = { 0 }, n, hexagon[6];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		bool flag = false;

		for (int j = 0; j < 6; j++)
		{
			scanf("%d", &hexagon[j]);
			res[1][j] = INF;
		}
			
		for (int j = 3; j < 6; j++)
		{
			res[1][hexagon[j]] = min(res[1][hexagon[j]], res[0][hexagon[j - 3]] + j - 3, flag);
			res[1][hexagon[j - 3]] = min(res[1][hexagon[j - 3]], res[0][hexagon[j]] + 6 - j, flag);
		}

		if (!flag)
		{
			printf("NO %d\n", i+1);
			return 0;
		}

		for (int j = 0; j < 6; j++)
			res[0][j] = res[1][j];
	}

	int ans = INF;
	for (int i = 0; i < 6; i++)
		if (res[0][i] < ans)
			ans = res[0][i];

	printf("%d\n", ans);
	return 0;
}
