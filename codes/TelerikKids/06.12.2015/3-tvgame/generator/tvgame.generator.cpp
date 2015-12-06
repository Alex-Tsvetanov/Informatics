#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN (1 << 10)
using namespace std;

const int n = 505;
const int m = 450;

char grid[MAXN][MAXN];

inline void print() {
	for (int i=0; i < n; ++i)
		printf("%s\n", grid[i]);
}

char get(int val) { // mod 16
	if (val == 0) return '.';
	if (val == 1) return 'L';
	if (val == 2) return 'R';
	if (val == 3 || val == 4 || val == 5) return 'X';
	return char( val-6 + '0' );
}

int main() {
	srand(23);
	
	printf("%d %d\n", n, m);
	
	/*for (int i=0; i < n; ++i) {
		grid[i][0] = '0';
		grid[i][m-1] = '0';
		if (i+1 == n) {
			for (int j=0; j < m; ++j)
				grid[i][j] = char( rand()%10 + '0' );
		} else {
			for (int j=1; j < m-1; ++j)
				if ((i + j) & 1) {
					int now = rand() % 3;
					if (now == 2) grid[i][j] = 'R';
					else if (now == 1) grid[i][j] = 'L';
					else grid[i][j] = '.';
				} else {
					grid[i][j] = char( (rand() + i + j) % 10 + '0' );
				}
		}
	}*/
	
	/* for (int i=0; i < n; ++i) {
		grid[i][0] = '0';
		grid[i][m-1] = '0';
		if (i+1 == n) {
			for (int j=0; j < m; ++j)
				grid[i][j] = char( rand()%10 + '0' );
		} else {
			for (int j=1; j < m-1; ++j)
				grid[i][j] = get(rand() % 16);
		}
	}*/
	for (int i=0; i < n; ++i)
		for (int j=0; j < m; ++j)
			grid[i][j] = '1';
	
	for (int i=0; i+2 < m; ++i) {
		grid[i][i+1] = 'X';
		if (i+3 == m) grid[i][i+2] = 'L';
		else grid[i][i+2] = 'R';
	}
	
	int t = 0;
	for (int i=m-2; i < n; ++i) {
		t += 9;
		grid[i][m-1] = '9';
		if (i != n-1)
			for (int j=1; j < m-2; ++j)
				if ( (i+j) & 1 )
					grid[i][j] = 'X';
	}
		
	//printf("%d\n", t);
	print();
	return 0;
}