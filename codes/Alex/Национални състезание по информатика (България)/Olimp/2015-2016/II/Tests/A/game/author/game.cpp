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

struct Circle {
	int x,y,r;
} circles[MAXN];
int sortedCircles[MAXB][MAXN];
int neededRadius[MAXB][MAXN];

int currentQuery;
bool compareByNeededRadius(int a, int b)
{
	return (neededRadius[currentQuery][a] < neededRadius[currentQuery][b]);
}

int getPoints(int x, int y, int r, int idx)
{
	//if(!isInside(x,y,r, sortedCircles[idx][0])) return 0;
	if(r < neededRadius[idx][sortedCircles[idx][0]]) return 0;
	int from=0,to=N-1,mid=(from+to+1)/2;
	while(from < to)
	{
		//if(isInside(x,y,r, sortedCircles[idx][mid])) from = mid;
		if(r >= neededRadius[idx][sortedCircles[idx][mid]]) from = mid;
		else to = mid-1;
		mid = (from+to+1)/2;
	}
	//while(mid<N-1 and isInside(x,y,r, sortedCircles[idx][mid+1])) mid++;
	//while(!isInside(x,y,r, sortedCircles[idx][mid])) mid--;
	while(mid<N-1 and r >= neededRadius[idx][sortedCircles[idx][mid+1]]) mid++;
	while(r < neededRadius[idx][sortedCircles[idx][mid]]) mid--;
	return mid+1;
}

void solve()
{
	for(int i=0; i<N; i++)
	{
		circles[i].x = circleX[i];
		circles[i].y = circleY[i];
		circles[i].r = circleRadius[i];
	}
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			neededRadius[i][j] = circles[j].r + (int)(ceil(dist(queryX[i],queryY[i], circles[j].x, circles[j].y)));
		}

		for(int j=0; j<N; j++) sortedCircles[i][j] = j;

		currentQuery = i;

		sort(sortedCircles[i], sortedCircles[i]+N, compareByNeededRadius);

	}

	int multiply = 1;
	int circleCount;
	int totalPoints =0;
	for(int i=0; i<Q; i++)
	{
		circleCount = 0;
		for(int j=0; j<M; j++) circleCount += getPoints(queryX[j], queryY[j], punchStrength[i] * multiply, j);
		//printf("%d (%d): ", punchStrength[i], multiply);
		totalPoints += circleCount;
		multiply = (circleCount % 2 == 0) ? 2 : 1;
	}
	printf("%d\n", totalPoints);
}

void solveNaive()
{
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			neededRadius[i][j] = circleRadius[j] + (int)(ceil(dist(queryX[i],queryY[i], circleX[j], circleY[j])));
		}
	}

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
				if(punchStrength[i]*multiply >= neededRadius[j][k]) circleCount++;
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
	//freopen("game.05.in", "r", stdin);
	//freopen("game.out", "w", stdout);

	init();
	solve();
	//solveNaive();

	return 0;
}
