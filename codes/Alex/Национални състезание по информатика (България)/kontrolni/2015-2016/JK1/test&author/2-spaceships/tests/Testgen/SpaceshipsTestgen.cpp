/*
ID: espr1t
TASK: EllysGame
KEYWORDS: Testgen
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

const int MAX = 202;

int numRows, numCols;
char board[MAX][MAX];
int dir[4][2] = { {0, -1}, {0, +1}, {-1, 0}, {+1, 0} };

int getType(char ship) {
    if (ship == '<') return 0;
    if (ship == '>') return 1;
    if (ship == '^') return 2;
    if (ship == 'v') return 3;
    return -1;
}

class Dummy {
    public:
    int a[MAX][MAX];

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
};

class Author {
    public:
    int links[MAX][MAX][4], cur[MAX][MAX][4];
        
    int simulate(int row, int col) {
        for (int i = 0; i < numRows; i++)
            for (int c = 0; c < numCols; c++)
                for (int d = 0; d < 4; d++)
                    cur[i][c][d] = links[i][c][d];
    
        int moves = 0;
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
};

struct Test {
    vector <string> board;
    Test(vector <string> board_) : board(board_) {}
};
vector <Test> tests;

void init(const vector <string>& brd) {
    numRows = (int)brd.size(), numCols = (int)brd[0].size();
    for (int row = 0; row < numRows; row++)
        for (int col = 0; col < numCols; col++)
            board[row][col] = brd[row][col];
}

char ships[4] = {'<', '^', '>', 'v'};

void randomTest(int n, int m, int fillRate) {
    vector <string> board(n, string(m, '.'));
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < m; c++) {
            if (rand() % 100 < fillRate) {
                board[i][c] = ships[rand() % 4];
            }
        }
    }
    tests.push_back(Test(board));
}

void sampleInput() {
    /*
    Pressing the ship in the upper left corner would lead to game lasting for 16 seconds:
    <ol>
      <li>The first ship will fly downwards for two seconds until crashing into the one at (2, 0).</li>
      <li>The second ship will fly to the right for one second, until crashing into the one at (2, 1).</li>
      <li>The third one will fly to the right for two seconds, until crashing into the one at (2, 3).</li>
      <li>The fourth one will fly upwards for one second, until crashing into the one at (1, 3).</li>
      <li>The fifth one will fly to the left for two seconds, until crashing into the one at (1, 1).</li>
      <li>The sixth one will fly upwards for one second, until crashing into the one at (0, 1).</li>
      <li>The seventh one will fly downwards for three seconds, until crashing into the one at (3, 1).
          Please note that the ships at (1, 1) and (2, 1) have already moved (and crashed), thus the fields are now empty.</li>
      <li>The eight one will fly upwards for four seconds, until leaving the board. At that point the game ends.</li>
    </ol>
    However, it is better to click the ship at (2, 3), which would lead to a game of length 21 seconds.
    */
    tests.push_back(Test({
        "vv.^>>",
        ".^.<>.",
        ">>.^>v",
        ".^v>..",
        "^^...<"
    }));
}

void smallHandTest() {
    tests.push_back(Test({
        ".^.",
        "<.>",
        ".v."
    }));
}

void singleChoice() {
    vector <string> board(13, string(13, '.'));
    board[4][2] = 'v';
    tests.push_back(Test(board));
}

void singleRow(int size) {
    vector <string> board;
    board.push_back("");
    for (int i = 0; i < size / 2; i++)
        board.back() += ">";
    for (int i = size / 2; i < size; i++)
        board.back() += "<";
    tests.push_back(Test(board));
}

void singleCol(int size) {
    vector <string> board;
    for (int i = 0; i < size / 2; i++)
        board.push_back("v");
    for (int i = size / 2; i < size; i++)
        board.push_back("^");
    tests.push_back(Test(board));
}

void longPath1(int n) {
    // Expected O(N^2)
    vector <string> board(n, string(n, '.'));
    
    board[0][0] = '>';
    board[0][n - 1] = 'v';
    board[n - 1][n - 1] = '<';
    board[n - 1][0] = '^';
    for (int i = 1; i < n / 2; i++) {
        board[i][i - 1] = '>';
        board[i][n - 1 - i] = 'v';
        board[n - 1 - i][n - 1 - i] = '<';
        board[n - 1 - i][i] = '^';
    }
    tests.push_back(Test(board));
}

void longPath2(int n) {
    // Expected O(N^2)
    vector <string> board(n, string(n, '.'));
    
    board[0][0] = 'v';
    board[0][n - 1] = '<';
    board[n - 1][n - 1] = '^';
    board[n - 1][0] = '>';
    for (int i = 1; i < n / 2; i++) {
        board[i][i - 1] = 'v';
        board[i][n - 1 - i] = '<';
        board[n - 1 - i][n - 1 - i] = '^';
        board[n - 1 - i][i] = '>';
    }
    tests.push_back(Test(board));
}

void longPath3(int n) {
    // Expected O(N^2)
    vector <string> board(n, string(n, '.'));
    
    board[0][0] = 'v';
    board[0][n - 1] = '<';
    board[n - 1][n - 1] = '^';
    board[n - 1][0] = '>';
    for (int i = 1; i < n / 2; i++) {
        board[i][i - 1] = 'v';
        board[i][n - 1 - i] = '<';
        board[n - 1 - i][n - 1 - i] = '^';
        board[n - 1 - i][i] = '>';
    }
    
    for (int i = 0; i < (int)board.size(); i++) {
        for (int c = 0; c < (int)board[i].size(); c++) {
            if (board[i][c] == '>') {
                for (int j = c + 1; j < n && board[i][j] == '.'; j++)
                    board[i][j] = '>';
            }
            if (board[i][c] == 'v') {
                for (int j = i + 1; j < n && board[j][c] == '.'; j++)
                    board[j][c] = 'v';
            }
            if (board[i][c] == '<') {
                for (int j = c - 1; j >= 0 && board[i][j] == '.'; j--)
                    board[i][j] = '<';
            }
            if (board[i][c] == '^') {
                for (int j = i - 1; j >= 0 && board[j][c] == '.'; j--)
                    board[j][c] = '^';
            }
        }
    }
    tests.push_back(Test(board));
}

void longPath4(int n) {
    // Expected O(N^3), but actually fast
    vector <string> board(n, string(n, '.'));
    for (int col = 0; col < n / 2; col++) {
        for (int row = 0; row < n / 2; row++)
            board[row][col] = 'v';
        for (int row = n / 2; row < n - 1; row++)
            board[row][col] = '^';
        board[n - 1][col] = '>';
    }
    for (int col = n / 2; col < n; col++) {
        int q = n / 2;
        for (int row = 0; row < q / 2 + q % 2; row++)
            board[row][col] = 'v';
        for (int row = q / 2 + q % 2; row < q; row++)
            board[row][col] = '^';
        board[q][col] = '<';
        board[n - 1][col] = '^';
    }
    board[n - 1][n / 2] = '.';
    tests.push_back(Test(board));
}

void longPath5(int n) {
    // Expected O(N^3)
    vector <string> board(n, string(n, '.'));
    for (int row = 0; row < n / 2; row++)
        for (int col = 0; col < n; col++)
            board[row][col] = 'v';
    for (int row = n / 2; row < n; row++)
        for (int col = 0; col < n; col++)
            board[row][col] = '^';
    
    for (int i = n - 1; i >= 0; i--) {
        if (i % 2 == (n - 1) % 2) {
            board[0][i] = '<';
        } else {
            board[n / 2][i] = '<';
        }
    }
    tests.push_back(Test(board));
}

void longPath6(int n) {
    // Expected O(N^3)
    vector <string> board(n, string(n, '.'));
    for (int row = 1; row < n; row++) {
        for (int col = 0; col < n / 2; col++)
            board[row][col] = '>';
        for (int col = n / 2; col < n; col++)
            board[row][col] = '<';
    }
    for (int row = 1; row < n; row += 2) {
        board[row][n - 1] = '^';
    }
    for (int row = 2; row < n; row += 2) {
        board[row][n / 2] = '^';
    }
    
    for (int row = 0; row < n; row++)
        board[row][0] = 'v';
    for (int col = 0; col <= n / 2; col++)
        board[n - 1][col] = '>';
    for (int col = n / 2 + 1; col < n; col++)
        board[n - 1][col] = '<';
    for (int col = 1; col < n; col++)
        board[0][col] = '<';
    board[n - 1][n / 2] = '^';
    
    tests.push_back(Test(board));
}

void longPath7(int n) {
    // Expected O(N^3)
    vector <string> board(n, string(n, '.'));
    for (int col = 0; col < n; col++) {
        for (int row = 0; row < n / 2; row++)
            board[row][col] = 'v';
        for (int row = n / 2; row < n - 1; row++)
            board[row][col] = '^';
    }
    for (int col = 0; col < n / 2; col++) {
        board[0][col] = '>';
        board[1][col] = '>';
        board[n - 2][col] = '>';
        board[n - 1][col] = '>';
    }
    
    for (int col = n / 2; col < n; col++) {
        board[0][col] = 'v';
        board[1][col] = 'v';
        
        board[n / 2 - 2][col] = '<';
        board[n / 2 - 1][col] = '<';
        board[n / 2][col] = '<';
        board[n / 2 + 1][col] = '<';
        
        board[n - 2][col] = '^';
        board[n - 1][col] = '^';
    }
    tests.push_back(Test(board));
}

void longPath8(int n) {
    // Expected O(N^3)
    vector <string> board(n, string(n, '.'));

    for (int row = 1; row + 2 < n; row += 3) {
        for (int col = 1; col < n / 2; col++) {
            board[row + 0][col] = 'v';
            board[row + 1][col] = '>';
            board[row + 2][col] = '>';
        }
        for (int col = n / 2; col < n - 1; col++) {
            board[row + 0][col] = '<';
            board[row + 1][col] = '^';
            board[row + 2][col] = '<';
        }
        board[row + 1][n - 1] = '^';
        board[row + 2][n / 2] = '^';
        board[row + 2][n - 1] = '<';
    }

    for (int col = 0; col < n; col++)
        board[0][col] = '<';
    for (int row = 0; row < n; row++)
        board[row][0] = 'v';
    for (int col = 0; col < n / 2; col++)
        board[n - 1][col] = '>';
    board[n - 1][n / 2] = '^';
    for (int col = n / 2 + 1; col < n; col++)
        board[n - 1][col] = '<';
    
    tests.push_back(Test(board));
//    for (int row = 0; row < (int)board.size(); row++)
//        fprintf(stderr, "%s\n", board[row].c_str());
}

void solveTests() {
    Dummy dummy;
    Author author;
    
    for (int t = 0; t < (int)tests.size(); t++) {
        fprintf(stderr, "Solving testcase %d...\n", t);

        init(tests[t].board);
        
        unsigned dTime = clock();
        int ansDummy = dummy.eval();
        fprintf(stderr, "  >> dummy's execution time: %.3lfs\n",
            (double)(clock() - dTime) / CLOCKS_PER_SEC);
        
        unsigned aTime = clock();
        int ansAuthor = author.eval();
        fprintf(stderr, "  >> author's execution time: %.3lfs\n",
            (double)(clock() - aTime) / CLOCKS_PER_SEC);
        
        fprintf(stderr, "    -- %d vs %d\n", ansDummy, ansAuthor);
        
        if (ansDummy != ansAuthor) {
            fprintf(stderr, "ERROR: Answers differ!\n");
            system("pause");
            exit(0);
        }
    }
    fprintf(stderr, "All tests solved successfully!\n");
}

void printTests() {
    Author solution;
    for (int t = 0; t < (int)tests.size(); t++) {
        fprintf(stderr, "Printing testcase %d...\n", t);

        char inpFile[32], solFile[32];
        sprintf(inpFile, "Spaceships.%02d.in", t);
        sprintf(solFile, "Spaceships.%02d.sol", t);
        FILE* inp = fopen(inpFile, "wt");
        FILE* sol = fopen(solFile, "wt");
        
        fprintf(inp, "%d %d\n", (int)tests[t].board.size(), (int)tests[t].board[0].size());
        for (int row = 0; row < (int)tests[t].board.size(); row++)
            fprintf(inp, "%s\n", tests[t].board[row].c_str());
        
        init(tests[t].board);
        fprintf(sol, "%d\n", solution.eval());

        fclose(inp), fclose(sol);
    }
}

int main(void) {
    srand(42);
    
    sampleInput();

    // Very small tests (20 points)
    smallHandTest();
    singleChoice();
    randomTest(7, 9, 100);
    randomTest(13, 17, 70);
    
    // Medium tests, solvable by dummy solution (30 points)
    singleRow(50);
    singleCol(49);
    randomTest(47, 42, 95);
    randomTest(64, 28, 77);
    randomTest(33, 91, 83);
    randomTest(50, 50, 50);
    
    // Large tests, dummy still okay (30 points)
    randomTest(89, 76, 80);
    randomTest(100, 100, 100);
    longPath1(100);
    longPath2(100);
    longPath3(100);
    longPath4(100);
    
    // Large tests, dummy times out (20 points)
    longPath5(100);
    longPath6(100);
    longPath7(100);
    longPath8(100);

//    printTests();
    solveTests();
    return 0;
}
