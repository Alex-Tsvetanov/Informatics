#include <cstdio>
#include <algorithm>

using namespace std;

#define LL long long

#define maxk 100010
int k, p, a[maxk];
LL sum[maxk];

int FindI( LL x )
{
  int i, mi = 0, ma = k;
  while (mi < ma)
    if (a[i = (mi + ma) >> 1] <= x)
      mi = i + 1;
    else
      ma = i;
  return mi;
}

int main( void )
{
//  freopen("trees.in", "rt", stdin);
//  freopen("trees.out", "wt", stdout);
  while (scanf("%d%d", &k, &p) == 2)
  {
    int i;
    if (p > k)
    {
      printf("%d\n", k);
      continue;
    }
    for (i = 0; i < k; i++)
      scanf("%d", &a[i]);
    sort(a, a + k);
    sum[0] = 0;
    for (i = 0; i < k; i++)
      sum[i + 1] = sum[i] + a[i];

    LL xmi = 0, xma = (LL)1e18 / p;
    while (xmi < xma)
    {
      LL x = (xmi + xma + 1) >> 1;
      i = FindI(x);
      if (sum[i] + (LL)(k - i) * x >= x * p)
        xmi = x;
      else
        xma = x - 1;
    }
    
    i = FindI(xmi);
    LL tail = (k - i) + min((LL)i, sum[i] + (LL)(k - i) * xmi - xmi * p);
    printf("%I64d\n", (LL)xmi * p + tail);
  }
  return 0;
}
