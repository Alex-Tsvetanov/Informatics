#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

double sqr(double x) { return x*x; }
double dist(double x1, double y1, double x2, double y2) { return sqrt(sqr(x1-x2) + sqr(y1-y2)); }

const int maxN=10000;
const int maxM=10;
const int maxQ=10000;

struct circle{
  int Ox;
  int Oy;
  int r;
};

int N,M,Q;
int s, score=0;
circle circles[maxN+1];

double d[maxM+1][maxN+1];

void init() {
  int i,j;
  int xp,yp;

  scanf("%d %d %d", &N,&M,&Q);
  for (i=1;i<=N;i++)
    scanf("%d %d %d",&circles[i].Ox, &circles[i].Oy, &circles[i].r);

  for (i=1;i<=M;i++)
  {
    scanf("%d %d",&xp,&yp);
    for (j=1;j<=N;j++)
      d[i][j]= dist(xp,yp,circles[j].Ox,circles[j].Oy)+circles[j].r;
    sort(d[i]+1,d[i]+N+1);
  }
}

int pscore(int pointNo, double s){
  int L=1,R=N, m;
  while(L<=R){
    m=(L+R)/2;
    if (s>=d[pointNo][m])
      L=m+1;
    else
      R=m-1;
  }
  return L-1;
}

  int main(){
    int qscore=1,s;
    int i,j;
    init();
    for (i=1;i<=Q;i++){
      scanf("%d",&s);
      if (qscore%2==0) s=2*s;
      qscore=0;
      for (j=1;j<=M;j++)
        qscore=qscore+pscore(j,s);
      score=score+qscore;
    }
    printf("%d\n",score);
    return 0;
  }

