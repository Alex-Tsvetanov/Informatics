/*
ID: espr1t
TASK: Spaceships
KEYWORDS: Easy, Bruteforce, Simulation
*/

#include <cstdio>

const int MAX = 104;
FILE *in = stdin, *out = stdout;

int numRows, numCols;
char board[MAX][MAX], a[MAX][MAX];
int dir[4][2] = { {0, -1}, {-1, 0}, {0, +1}, {+1, 0} };

int getType(char ship) {
    if (ship == '<') return 0;
    if (ship == '^') return 1;
    if (ship == '>') return 2;
    if (ship == 'v') return 3;
    return -1;
}

int simulate(int row, int col) {
    for (int i = 0; i < numRows; i++)
        for (int c = 0; c < numCols; c++)
            a[i][c] = board[i][c];
    
    int moves = 0, type = -1;
    while (row >= 0 && row < numRows && col >= 0 && col < numCols) {
        moves++;
        if (a[row][col] != '.') {
            type = getType(a[row][col]);
            a[row][col] = '.';
        }
        row += dir[type][0], col += dir[type][1];
    }
    return moves;
}

int eval() {
    int ans = 0;
    for (int srow = 0; srow < numRows; srow++) {
        for (int scol = 0; scol < numCols; scol++) {
            if (board[srow][scol] != '.') {
                int cur = simulate(srow, scol);
                ans = ans < cur ? cur : ans;
            }
        }
    }
    return ans;
}

int main(void) {
    fscanf(in, "%d %d", &numRows, &numCols);
    for (int row = 0; row < numRows; row++)
        fscanf(in, "%s", board[row]);
    fprintf(out, "%d\n", eval());
    return 0;
}
