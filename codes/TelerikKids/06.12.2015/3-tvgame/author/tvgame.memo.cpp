#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN (1 << 10)
using namespace std;

int n, m;
char grid[MAXN][MAXN];
int dp[MAXN][MAXN];
int from[MAXN][MAXN];

char ch[4] = {'L', 'D', 'R'};
int dy[4] = {-1, 0, 1};

inline void restore(int col) {
	int x = 0, y = col;
	
	while (x < n-1) {
		printf("%c", ch[ from[x][y] ]);
		y += dy[ from[x][y] ];
		x ++;
	}
	
	printf("\n");
}

int go(int x, int y) {
	int &ref = dp[x][y];
	if (ref != -1) return ref;
	if (x == n-1) return ref = int(grid[x][y] - '0');
	
	ref = 0;
	
	int &fr = from[x][y];
	
	if (grid[x][y] == 'L') {
		fr = 0;
		return ref = go(x+1, y-1);
	}
	
	if (grid[x][y] == 'R') {
		fr = 2;
		return ref = go(x+1, y+1);
	}
	
	if (grid[x][y] == 'X') {
		for (int i=0; i < 3; ++i) {
			int cur = go(x+1, y+i-1);
			if (ref < cur)
				ref = cur,
				fr = i;
		}
		return ref;
	}
	
	ref = go(x+1, y);
	fr = 1;
	if (grid[x][y] >= '0' && grid[x][y] <= '9') 
		ref += int(grid[x][y]-'0');
	
	return ref; 
}

inline void solve() {
	memset(dp, -1, sizeof(dp));
	
	int answer = -1, col = -1;
	for (int i=0; i < m; ++i) {
		int cur = go(0, i);
		
		if (cur >= answer)
			answer = cur,
			col = i;
	}
	
	/*for (int i=0; i < n; ++i)
		for (int j=0; j < m; ++j)
			printf("%d%c", from[i][j], (j+1 == m)?'\n':' ');*/
	
	printf("%d\n%d\n", answer, col+1);
	restore(col);
}

inline void read() {
	scanf("%d%d", &n, &m);
	for (int i=0; i < n; ++i)
		scanf("%s", grid[i]);
}

int main() {
	read();
	solve();
	return 0;
}