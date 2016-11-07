/*
ID: espr1t
TASK: Spaceships
KEYWORDS: Easy, Bruteforce, Simulation, Linked Lists
*/

#include <cstdio>
#include <cmath>
#include <stdlib.h>

const int MAX = 102;
FILE *in = stdin, *out = stdout;

int numRows, numCols;
char board[MAX][MAX];
int links[MAX][MAX][4], cur[MAX][MAX][4];
int dir[4][2] = { {0, -1}, {0, +1}, {-1, 0}, {+1, 0} };

int getType(char ship) {
    if (ship == '<') return 0;
    if (ship == '>') return 1;
    if (ship == '^') return 2;
    if (ship == 'v') return 3;
    return -1;
}

int simulate(int row, int col) {
    int moves = 0;
    for (int i = 0; i < numRows; i++)
        for (int c = 0; c < numCols; c++)
            for (int d = 0; d < 4; d++)
                cur[i][c][d] = links[i][c][d];

    while (true) {
        int type = getType(board[row][col]);

        if (cur[row][col][type] == -1) {
            if (type == 0) moves += col + 1;
            if (type == 1) moves += numCols - col;
            if (type == 2) moves += row + 1;
            if (type == 3) moves += numRows - row;
            break;
        }

        // Remove current ship and update links
        for (int d = 0; d < 4; d++) {
            if (cur[row][col][d] != -1) {
                int nrow = cur[row][col][d] >> 10;
                int ncol = cur[row][col][d] & ((1 << 10) - 1);
                cur[nrow][ncol][d ^ 1] = cur[row][col][d ^ 1];
            }
        }

        // Go to next position
        int nrow = cur[row][col][type] >> 10;
        int ncol = cur[row][col][type] & ((1 << 10) - 1);
        moves += abs(row - nrow) + abs(col - ncol);
        row = nrow, col = ncol;
    }
    return moves;
}

int eval() {
    // Create neighbors linked lists
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            for (int d = 0; d < 4; d++) {
                links[row][col][d] = -1;
                int crow = row + dir[d][0], ccol = col + dir[d][1];
                while (crow >= 0 && crow < numRows && ccol >= 0 && ccol < numCols) {
                    if (board[crow][ccol] != '.') {
                        links[row][col][d] = (crow << 10) | ccol;
                        break;
                    }
                    crow += dir[d][0], ccol += dir[d][1];
                }
            }
        }
    }

    int ans = 0;
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            if (board[row][col] != '.') {
                int cur = simulate(row, col);
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
