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

inline void solve() {
	// make some initial values for L and R cells; 
	for (int i=0; i < n; ++i)
		for (int j=0; j < m; ++j) 
			if (grid[i][j] == 'L') from[i][j] = 0;
			else if (grid[i][j] == 'R') from[i][j] = 2;
			else from[i][j] = 1;
	
	for (int i=n-1; i > 0; --i) {
		for (int j=0; j < m; ++j) {
			if (grid[i][j] >= '0' && grid[i][j] <= '9')
				dp[i][j] += grid[i][j]-'0';
			
			if ((grid[i-1][j] >= '0' && grid[i-1][j] <= '9') || grid[i-1][j] == 'X' || grid[i-1][j] == '.')
				if (dp[i-1][j] < dp[i][j]) {
					dp[i-1][j] = dp[i][j];
					from[i-1][j] = 1;
				}
				
			if (j-1 >= 0)
				if (grid[i-1][j-1] == 'R' || grid[i-1][j-1] == 'X')
					if (dp[i-1][j-1] < dp[i][j]) {
						dp[i-1][j-1] = dp[i][j];
						from[i-1][j-1] = 2;
					}
				
			if (j+1 < m)
				if (grid[i-1][j+1] == 'L' || grid[i-1][j+1] == 'X')
					if (dp[i-1][j+1] < dp[i][j]) {
						dp[i-1][j+1] = dp[i][j];
						from[i-1][j+1] = 0;
					}
		}
	}
	
	for (int i=0; i < m; ++i)
		if (grid[0][i] >= '0' && grid[0][i] <= '9')
			dp[0][i] += grid[0][i]-'0';
	
	int answer = dp[0][0], col = 0;
	for (int i=0; i < m; ++i)
		if (dp[0][i] >= answer)
			answer = dp[0][i],
			col = i;
	
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