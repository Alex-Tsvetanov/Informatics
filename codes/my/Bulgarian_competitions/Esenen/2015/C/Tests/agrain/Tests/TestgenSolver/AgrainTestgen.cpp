/*
ID: espr1t
TASK: Agrain
KEYWORDS: Testgen and Solver
*/

#include <cstdio>
#include <ctime>
#include <vector>
#include <random>
#include <queue>
#include <algorithm>

using namespace std;

mt19937 mt;
int rand() {
    int val = mt();
    return val < 0 ? -val : val;
}

struct Test {
    int n, l, d, x, a, b;
    Test(int n_ = 0, int l_ = 0, int d_ = 0, int x_ = 0, int a_ = 0, int b_ = 0) :
        n(n_), l(l_), d(d_), x(x_), a(a_), b(b_) {}
};
vector <Test> tests;

int solveLi(int N, int L, int D, int X, int A, int B) {
    if ((long long)(N + 1) * D < (long long)L)
        return -1;
    
    vector <int> minn(L / D + 1, L), maxx(L / D + 1, 0);
    int drop = 0, rem = L / D;
    while (rem > 0 && ++drop <= N) {
        int idx = X / D;
        if (idx - 1 >= 0     && minn[idx] - maxx[idx - 1] > D && X - maxx[idx - 1] <= D) rem--;
        if (idx + 1 <= L / D && minn[idx + 1] - maxx[idx] > D && minn[idx + 1] - X <= D) rem--;
        minn[idx] = min(minn[idx], X), maxx[idx] = max(maxx[idx], X);
        X = ((long long)X * A + B) % (L + 1);
    }
    return drop > N ? -1 : drop;
}

int solvePQ(int N, int L, int D, int X, int A, int B) {
    priority_queue < int, vector<int>, greater<int> > q;
    int pos = 0, at = 0;
    while (pos + D < L && at < N) {
        at++;
        if (X > pos) {
            q.push(X);
            while (!q.empty() && pos + D >= q.top()) {
                pos = q.top();
                q.pop();
            }
        }
        X = ((long long)X * A + B) % (L + 1);
    }
    return pos + D >= L ? at : -1;
}

int solveBS(int N, int L, int D, int X, int A, int B) {
    vector <int> points(N);
    for (int i = 0; i < N; i++) {
        points[i] = X;
        X = ((long long)X * A + B) % (L + 1);
    }
    int left = 1, right = N;
    while (left <= right) {
        int mid = (left + right) / 2;
        vector <int> tmp(points.begin(), points.begin() + mid);
        tmp.push_back(0);
        tmp.push_back(L);
        sort(tmp.begin(), tmp.end());
        bool okay = true;
        for (int i = 1; i < (int)tmp.size(); i++) {
            if (tmp[i] - tmp[i - 1] > D) {
                okay = false;
                break;
            }
        }
        if (okay)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return right + 1 <= N ? right + 1 : -1;
}

vector <int> generate(int N, int L, int D, int X, int A, int B) {
    vector <int> points(N);
    for (int i = 0; i < N; i++) {
        points[i] = X;
        X = ((long long)X * A + B) % (L + 1);
    }
    return points;
}

void printPoints(int N, int L, int D, int X, int A, int B) {
    vector <int> points = generate(N, L, D, X, A, B);
    if (N < 100) {
        fprintf(stderr, "Generated points: {");
        for (int i = 0; i < (int)points.size(); i++)
            fprintf(stderr, "%s%d", i == 0 ? "" : ", ", points[i]);
        fprintf(stderr, "}\n");
    }
    sort(points.begin(), points.end());
    points.resize(unique(points.begin(), points.end()) - points.begin());
    fprintf(stderr, "  >> number of unique points: %d\n", (int)points.size());

    int maxDist = points[0];
    for (int i = 1; i < (int)points.size(); i++)
        maxDist = max(maxDist, points[i] - points[i - 1]);
    maxDist = max(maxDist, L - points.back());
    fprintf(stderr, "  >> max distance: %d\n", maxDist);
    fprintf(stderr, "  >> answer is: %d\n", solveLi(N, L, maxDist, X, A, B));

    /*
    int last = -1;
    for (int left = maxDist, cnt = 1; left < L && cnt < 20; left++, cnt++) {
        int right = L;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (solveLi(N, L, mid, X, A, B) != last)
                right = mid - 1;
            else left = mid + 1;
        }
        left = right + 1;
        if (left >= L)
            break;
        last = solveLi(N, L, left, X, A, B);
        fprintf(stderr, "    -- answer with d = %d: %d\n", left, last);
    }
    */
}

void sampleInput1() {
    /*
    The length of the pot is 23 and there must be no interval longer than 7 without a drop of water.
    The rain drops fall at positions (in order): 14, 19, 12, 17, 10, 15, 8, 13, 6, 11, 4, 9.
    Until the 9-th drop falls at position 6 the interval [0, 8] was unwatered, thus there was
    an interval with length more than 7 that was dry.
    */
    tests.push_back(Test(12, 23, 7, 14, 13, 5));
}

void allDifferentSmall1() {
    int N = 1000, L = 8574, D = 77, X = 42, A = 71, B = 13;
//    printPoints(N, L, D, X, A, B);
    tests.push_back(Test(N, L, D, X, A, B));
}

void allDifferentSmall2() {
    int N = 1000, L = 8574, D = 101, X = 42, A = 71, B = 13;
//    printPoints(N, L, D, X, A, B);
    tests.push_back(Test(N, L, D, X, A, B));
}

void allDifferentMedium1() {
    int N = 100000, L = 5122656, D = 533, X = 1234567, A = 463, B = 179;
//    printPoints(N, L, D, X, A, B);
    tests.push_back(Test(N, L, D, X, A, B));
}

void allDifferentMedium2() {
    int N = 100000, L = 5122656, D = 1047, X = 1234567, A = 463, B = 179;
//    printPoints(N, L, D, X, A, B);
    tests.push_back(Test(N, L, D, X, A, B));
}

void allDifferentLarge1() {
    int N = 1000000, L = 182378338, D = 6116, X = 13, A = 233520, B = 38193139;
//    printPoints(N, L, D, X, A, B);
    tests.push_back(Test(N, L, D, X, A, B));
}

void allDifferentLarge2() {
    int N = 1000000, L = 785646465, D = 10001, X = 666666666, A = 34321981, B = 666421337;
//    printPoints(N, L, D, X, A, B);
    tests.push_back(Test(N, L, D, X, A, B));
}

void allDifferentHuge1() {
    int N = 10000000, L = 182378338, D = 393, X = 13333, A = 233520, B = 38193139;
//    printPoints(N, L, D, X, A, B);
    tests.push_back(Test(N, L, D, X, A, B));
}

void allDifferentHuge2() {
    int N = 10000000, L = 785646465, D = 2015, X = 666, A = 34321981, B = 666421337;
//    printPoints(N, L, D, X, A, B);
    tests.push_back(Test(N, L, D, X, A, B));
}

void lastMakesItOk() {
    int N = 89912, L = 257020532, D = 27039, X = 1, A = 4461535, B = 1048576;
//    printPoints(N, L, D, X, A, B);
    tests.push_back(Test(N, L, D, X, A, B));
}

void lastMakesItFull() {
    int N = 64800, L = 64799, D = 1, X = 1337, A = 40741, B = 14161;
//    printPoints(N, L, D, X, A, B);
    tests.push_back(Test(N, L, D, X, A, B));
}

void oneByOneForward() {
    tests.push_back(Test(1000000, 999999, 42, 0, 1, 1));
}

void twoByTwoForward() {
    tests.push_back(Test(999999, 777776, 1, 0, 1, 2));
}

void twoByTwoForwardHuge() {
    tests.push_back(Test(9999999, 7777776, 1, 0, 1, 2));
}

void oneByOneBackward() {
    tests.push_back(Test(1000000, 999999, 666, 999999, 1, 999999));
}

void oneByOneBackwardHuge() {
    tests.push_back(Test(10000000, 9999999, 666, 9999999, 1, 9999999));
}

void twoByTwoBackward() {
    tests.push_back(Test(1000000, 999998, 1, 999990, 1, 999997));
}

void guidedRandom(int N, bool hasSolution) {
    int L = rand() % 999999999 + 2;
    while (true) {
        int cnt = 0;
        for (int i = 2; i * i <= L; i++)
            if (L % (i * i) == 0)
                cnt++;
        if (cnt >= 2)
            break;
        L = rand() % 999999999 + 2;
    }
    
    int A = 1, tmp = L;
    for (int i = 2; i * i <= tmp; i++) {
        if (tmp % i == 0)
            A *= i;
        while (tmp % i == 0)
            tmp /= i;
    }
    A *= tmp;
    if (L % 4 == 0 && A % 4 != 0)
        A *= 2;
    L--, A++;
    
    int D = rand() % (L - 1) + 1;
    int X = rand() % (L + 1);
    
    int B = rand() % (L + 1);
    while (__gcd(B, L + 1) != 1)
        B = rand() % (L + 1);
    
    vector <int> points = generate(N, L, 1, X, A, B);
    points.push_back(0);
    points.push_back(L);
    sort(points.begin(), points.end());
    int maxDist = 0;
    for (int i = 1; i < (int)points.size(); i++)
        maxDist = max(maxDist, points[i] - points[i - 1]);
    
    if (!hasSolution) {
        D = rand() % maxDist + 1;
    }
    else {
        int goal = N / 3 + rand() % (N / 3) + 1;
        int left = maxDist, right = L;
        while (left <= right) {
            int mid = (left + right) / 2;
            int cur = solveLi(N, L, mid, X, A, B);
            if (cur >= goal)
                left = mid + 1, D = mid;
            else
                right = mid - 1;
        }
    }
    tests.push_back(Test(N, L, D, X, A, B));
}

void totallyRandom(int N) {
    // L is between 0.1 and 100 times N.
    int loadFactor = rand() % 1000 + 1;
    int L = max(2, N * 100 / loadFactor);
    int D = rand() % (L - 1) + 1;
    int X = rand() % (L + 1);
    int A = rand() % (L + 1);
    int B = rand() % (L + 1);
    tests.push_back(Test(N, L, D, X, A, B));
}

void printTests() {
    for (int i = 0; i < (int)tests.size(); i++) {
        fprintf(stderr, "Printing testcase %d...\n", i);

        if (tests[i].n < 1 || tests[i].n > 10000000) {
            fprintf(stderr, "ERROR: Test %d has wrong N: %d\n", i, tests[i].n);
            fprintf(stderr, "  -- test is: %d %d %d %d %d %d\n",
                tests[i].n, tests[i].l, tests[i].d, tests[i].x, tests[i].a, tests[i].b);
        }
        if (tests[i].l < 2 || tests[i].l > 1000000000) {
            fprintf(stderr, "ERROR: Test %d has wrong L: %d\n", i, tests[i].l);
            fprintf(stderr, "  -- test is: %d %d %d %d %d %d\n",
                tests[i].n, tests[i].l, tests[i].d, tests[i].x, tests[i].a, tests[i].b);
        }
        if (tests[i].d < 1 || tests[i].d > tests[i].l - 1) {
            fprintf(stderr, "ERROR: Test %d has wrong D: %d\n", i, tests[i].d);
            fprintf(stderr, "  -- test is: %d %d %d %d %d %d\n",
                tests[i].n, tests[i].l, tests[i].d, tests[i].x, tests[i].a, tests[i].b);
        }
        if (tests[i].a < 0 || tests[i].a > tests[i].l) {
            fprintf(stderr, "ERROR: Test %d has wrong A: %d\n", i, tests[i].a);
            fprintf(stderr, "  -- test is: %d %d %d %d %d %d\n",
                tests[i].n, tests[i].l, tests[i].d, tests[i].x, tests[i].a, tests[i].b);
        }
        if (tests[i].b < 0 || tests[i].b > tests[i].l) {
            fprintf(stderr, "ERROR: Test %d has wrong B: %d\n", i, tests[i].b);
            fprintf(stderr, "  -- test is: %d %d %d %d %d %d\n",
                tests[i].n, tests[i].l, tests[i].d, tests[i].x, tests[i].a, tests[i].b);
        }
        if (tests[i].x < 0 || tests[i].x > tests[i].l) {
            fprintf(stderr, "ERROR: Test %d has wrong X: %d\n", i, tests[i].x);
            fprintf(stderr, "  -- test is: %d %d %d %d %d %d\n",
                tests[i].n, tests[i].l, tests[i].d, tests[i].x, tests[i].a, tests[i].b);
        }
        
        unsigned timeLi = clock();
        int ansLi = solveLi(tests[i].n, tests[i].l, tests[i].d, tests[i].x, tests[i].a, tests[i].b);
        fprintf(stderr, "  >> answer: %d (out of %d)\n", ansLi, tests[i].n);
        fprintf(stderr, "  >> Li execution time: %.3lfs\n", (double)(clock() - timeLi) / CLOCKS_PER_SEC);
        unsigned timePq = clock();
        int ansPq = solvePQ(tests[i].n, tests[i].l, tests[i].d, tests[i].x, tests[i].a, tests[i].b);
        fprintf(stderr, "  >> PQ execution time: %.3lfs\n", (double)(clock() - timePq) / CLOCKS_PER_SEC);
        unsigned timeBs = clock();
        int ansBs = solveBS(tests[i].n, tests[i].l, tests[i].d, tests[i].x, tests[i].a, tests[i].b);
        fprintf(stderr, "  >> BS execution time: %.3lfs\n", (double)(clock() - timeBs) / CLOCKS_PER_SEC);
    
        if (ansLi != ansPq || ansLi != ansBs) {
            fprintf(stderr, "ERROR: solutions' answers differ (%d vs %d vs %d)!\n", ansLi, ansPq, ansBs);
        }
        
        char inpFile[32], solFile[32];
        sprintf(inpFile, "Agrain.%02d.in", i);
        sprintf(solFile, "Agrain.%02d.sol", i);

        FILE* inp = fopen(inpFile, "wt");
        fprintf(inp, "%d %d %d\n", tests[i].n, tests[i].l, tests[i].d);
        fprintf(inp, "%d %d %d\n", tests[i].x, tests[i].a, tests[i].b);
        fclose(inp);
        
        FILE* sol = fopen(solFile, "wt");
        fprintf(sol, "%d\n", ansLi);
        fclose(sol);
    }
    fprintf(stderr, "Printed %d tests.\n", (int)tests.size());
}

int main(void) {
    sampleInput1();
    
    // Small dataset (N <= 10,000)
    allDifferentSmall1();
    allDifferentSmall2();
    guidedRandom(5555, true);
    totallyRandom(8080);
    guidedRandom(9876, false);
    
    // Medium dataset (N <= 100,000)
    allDifferentMedium1();
    allDifferentMedium2();
    lastMakesItOk();
    lastMakesItFull();
    guidedRandom(98765, true); // Has solution
    
    // Large dataset (N <= 1,000,000)
    allDifferentLarge1();
    allDifferentLarge2();
    oneByOneForward();
    twoByTwoForward();
    oneByOneBackward();
    twoByTwoBackward();
    
    // Huge dataset (N <= 10,000,000)
    allDifferentHuge1();
    allDifferentHuge2();
    twoByTwoForwardHuge();
    oneByOneBackwardHuge();
    totallyRandom(5000000);
    totallyRandom(10000000);
    guidedRandom(6661337, true);
    guidedRandom(4242666, false);
    guidedRandom(10000000, true);

    printTests();
    return 0;
}
