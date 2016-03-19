#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

double sqr(double x) { return x*x; }
double dist(double x1, double y1, double x2, double y2) { return sqrt(sqr(x1-x2) + sqr(y1-y2)); }
double sqrDist(double x1, double y1, double x2, double y2) { return (sqr(x1-x2) + sqr(y1-y2)); }

const int MAXN = 10000;
const int MAXB = 10;
const int MAXQ = 10000;

int N,M,Q;
int circleX[MAXN],circleY[MAXN],circleRadius[MAXN],queryX[MAXB],queryY[MAXB],punchStrength[MAXQ];

void init()
{
	scanf("%d %d %d", &N, &M, &Q);

	for(int i=0; i<N; i++) scanf("%d %d %d", &circleX[i], &circleY[i], &circleRadius[i]);
	for(int i=0; i<M; i++) scanf("%d %d", &queryX[i], &queryY[i]);
	for(int i=0; i<Q; i++) scanf("%d", &punchStrength[i]);
	//for(int i=0; i<Q; i++) printf("%d\n", punchStrength[i]);
}

int neededRadius[MAXB][MAXN];
void solve()
{
	int multiply = 1;
	int circleCount;
	int totalPoints =0;
	for(int i=0; i<Q; i++)
	{
		circleCount = 0;
		for(int j=0; j<M; j++)
		{
			for(int k=0; k<N; k++)
			{
				//neededRadius[j][k] = circles[k].r + (int)(dist(queryX[j],queryY[j], circles[k].x, circles[k].y) + 0.9999999999999);
				if((double)(punchStrength[i]*multiply) > (double)(circleRadius[j]) + dist(queryX[i],queryY[i], circleX[j], circleY[j])) circleCount++;
			}
		}
		//printf("%d (%d): ", punchStrength[i], multiply);
		totalPoints += circleCount;
		multiply = (circleCount % 2 == 0) ? 2 : 1;
	}
	printf("%d\n", totalPoints);
}

int main()
{
	init();
	solve();

	return 0;
}
