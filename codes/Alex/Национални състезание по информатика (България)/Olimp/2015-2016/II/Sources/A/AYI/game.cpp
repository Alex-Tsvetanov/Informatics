#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

/// TODO: REMOVE DEBUG PRINTS CUZ SHITTY COMPETITION

using namespace std;

struct coord {
    int x;
    int y;
};

struct circle {
    int x;
    int y;
    double r;
};

vector<circle> circles;
vector<coord> points;
vector<int> turnPower;

vector<double> affected[16];


int prevTurn;
int total;

int n, m, q;

void read() {
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 0; i < n; i++) {
        circle foo;
        scanf("%d %d %lf", &foo.x, &foo.y, &foo.r);
        circles.push_back(foo);
    }
    for(int i = 0; i < m; i++) {
        coord foo;
        scanf("%d %d", &foo.x, &foo.y);
        points.push_back(foo);
    }

    for(int i = 0; i < q; i++) {
        int foo;
        scanf("%d", &foo);
        turnPower.push_back(foo);
    }
}

void calcAffected() {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int xx = abs(circles[j].x - points[i].x);
            int yy = abs(circles[j].y - points[i].y);
            double dist = sqrt( xx * xx + yy * yy) + circles[j].r;
            affected[i].push_back(dist);
        }
    }
}

void solve() {
    calcAffected();
    for(int i = 0; i < m; i++) {
        sort(affected[i].begin(), affected[i].end());
    }

    for(int i = 0; i < q; i++) {
        int r = turnPower[i];
        if(i != 0 && prevTurn % 2 == 0) {
            r *= 2;
        }
        prevTurn = 0;
        for(int j = 0; j < m; j++) {
            int added = lower_bound(affected[j].begin(), affected[j].end(), r) - affected[j].begin();
            prevTurn += added;
        }
        total += prevTurn;
    }

    printf("%d\n", total);
}

int main() {
    read();
    solve();
}
