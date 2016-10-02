#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define MAXN (1 << 10)
using namespace std;

FILE *in, *out, *sol;
	
int n, m;
char grid[MAXN][MAXN];

inline bool simulate(int answer) {
	int col = 0;
	int val = fscanf(out, "%d", &col);
	if (val != 1) return false;
	if (col < 1 || col > m) return false;
	
	char c[2 * MAXN];
	val = fscanf(out, "%s", c);
	
	if (val != 1) return false;
	int len = strlen(c);
	if (len != n-1) return false;
	
	int x = 0, y = col-1;
	int curAnswer = 0;
	if (grid[x][y] >= '0' && grid[x][y] <= '9')
		curAnswer += int(grid[x][y] - '0');
	
	for (int i=0; i < len; ++i) {
		if (c[i] == 'L') {
			if (grid[x][y] != 'L' && grid[x][y] != 'X')
				return false;
			y --;
		} else if (c[i] == 'R') {
			if (grid[x][y] != 'R' && grid[x][y] != 'X')
				return false;
			y ++;
		} else if (c[i] == 'D') {
			if (grid[x][y] == 'R' || grid[x][y] == 'L')
				return false;
		} else return false;
		
		x ++;
		if (grid[x][y] >= '0' && grid[x][y] <= '9')
			curAnswer += int(grid[x][y]-'0');
	}
	
	if (curAnswer != answer) return false;
	return true;
}

inline void readInput() { // assuming input file has been checked with the input validator
	int val = fscanf(in, "%d%d", &n, &m);
	
	if (val != 2) {
		printf("Problems with input file!\n");
		exit(0);
	}
	
	for (int i=0; i < n; ++i) {
		int cur = fscanf(in, "%s", grid[i]);
		if (cur != 1) {
			printf("0\nProblems with input file!\n");
			exit(0);
		}
		if (strlen( grid[i] ) != m) {
			printf("0\nProblems with input file!\n");
			exit(0);
		}
	}
}

inline int getPoints(char* ch) {
	int ret = 0;
	int len = strlen(ch);
	for (int i=0; i < len; ++i)
		ret = ret * 10 + (ch[i]-'0');
		
	return ret;
}

int main(int argc, char* argv[]) {
	
	if (argc < 4) {
		printf("Not enough arguments!\nExpected: in file, out file, solution file, points for test (optional)\n");
		return 0;
	}
	
	in = fopen(argv[1], "r"); // input file
	out = fopen(argv[2], "r"); // out (contestant file)
	sol = fopen(argv[3], "r"); // solution
	int pointsForTest = 10;
	if (argc > 4)
		pointsForTest = getPoints(argv[4]);
	
	readInput();
	
	int answer, contestantAnswer;
	
	int val = fscanf(out, "%d", &contestantAnswer);
	if (val != 1) {
		printf("0");
		return 0;
	}
	
	fscanf(sol, "%d", &answer);
	
	if (answer == contestantAnswer) {
		bool ret = simulate(answer);
		
		if (ret == true) {
			printf("%d", pointsForTest);
		} else {
			printf("%d", (pointsForTest * 3) / 5); // 60% of the points
		}
	} else printf("0");
	
	return 0;
}
