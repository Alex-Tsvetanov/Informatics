#include <iostream>
#include <memory>
#define MAX_CAP 201

using namespace std;

char dp[MAX_CAP][MAX_CAP][MAX_CAP]; // 0 ili 1 - pokazva dali [a][b][c] e dostijima konfiguraciq

char used[3 * MAX_CAP];

int x, y, z;

void calc(int a, int b, int c)
{
// smqtame ot konfiguraciq [a][b][c] kakvi litraji mojem da poluchim
if (!used[a]) used[a] = 1;
if (!used[b]) used[b] = 1;
if (!used[c]) used[c]  = 1;
if (!used[a + b]) used[a + b] = 1;
if (!used[a + c]) used[a + c] = 1;
if (!used[b + c]) used[b + c] = 1;
if (!used[a + b + c]) used[a + b + c] = 1;

// pylnim ot cisternata
if (! dp[x][b][c]) dp[x][b][c] = 1, calc(x, b, c);
if (! dp[a][y][c]) dp[a][y][c] = 1, calc(a, y, c);
if (! dp[a][b][z]) dp[a][b][z] = 1, calc(a, b, z);

// prehvurlqme ot tuba v tuba
int r;

// ot b v a
r = a + b;
if (r > x) r = x;
if (b - r + a >= 0 && !dp[r][b - r + a][c]) dp[r][b - r + a][c] = 1, calc(r, b - r + a, c);

// ot a v b
r = a + b;
if (r > y) r = y;
if (a - r + b >= 0 && !dp[a - r + b][r][c]) dp[a - r + b][r][c] = 1, calc(a - r + b, r, c);

// ot c v a
r = a + c;
if (r > x) r = x;
if (c - r + a >= 0 && !dp[r][b][c - r + a]) dp[r][b][c - r + a] = 1, calc(r, b, c - r + a);

// ot a v c
r = a + c;
if (r > z) r = z;
if (a - r + c >= 0 && !dp[a - r + c][b][r]) dp[a - r + c][b][r]  = 1, calc(a - r + c, b, r);

// ot c v b
r = b + c;
if (r > y) r = y;
if (c - r + b >= 0 && !dp[a][r][c - r + b]) dp[a][r][c - r + b] = 1, calc(a, r, c - r + b);

// ot b v c
r = b + c;
if (r > z) r = z;
if (b - r + c >= 0 && !dp[a][b - r + c][r]) dp[a][b - r + c][r] = 1, calc(a, b - r + c, r);
}

int main()
{
  ans = 0;
  scanf("%d%d%d", &x, &y, &z);

  dp[0][0][0] = 1;
  calc(0, 0, 0); // mahame 0-ta, tyi kato e otmerena, a po uslovie ne se vkluchva
  int ans = 0;
  for (int i = 1; i < 3 * MAX_CAP; ++i) if (used[i]) ++ans;
  printf("%d\n", ans);
  return 0;
}
