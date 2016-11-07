#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct point_t {
    int x,y;
    double distanceTo(point_t p) {
        int dx = p.x - x;
        int dy = p.y - y;
        return sqrt(dx*dx + dy*dy);
    }
    point_t(int xx, int yy) : x(xx), y(yy) {}
    point_t() {}
};


struct circle_t {
    point_t p;
    int r;
    bool isInside(circle_t c) {
        return (p.distanceTo(c.p)+r) <= c.r;
    }
    circle_t(point_t pp, int rr) : p(pp), r(rr) {}
    circle_t() {}
};

void readCircles(int N, vector<circle_t>& v) {
    for(int i=0;i<N;i++) {
        int x,y,r;
        cin >> x >> y >> r;
        v.push_back(circle_t(point_t(x,y),r));
    }
}

void readPoints(int M, vector<point_t>& v) {
    for(int i=0;i<M;i++) {
        int x,y;
        cin >> x >> y;
        v.push_back(point_t(x,y));
    }
}

int main() {
    int N,M,Q;
    cin >> N >> M >> Q;
    vector<circle_t> c;
    vector<point_t> p;
    readCircles(N, c);
    readPoints(M, p);
    bool double_s = 0;
    int points = 0;
    for(int l=0;l<M;l++) {
        for(int i=0;i<Q;i++) {
            int s;
            cin >> s;
            if(double_s) s += s;
            int n_points = 0;
            for(int j=0;j<N;j++) {
                n_points += c[j].isInside(circle_t(p[l], s));
            }
            double_s = !(n_points%2);
            points += n_points;
        }
    }
    cout << points;
    return 0;
}
