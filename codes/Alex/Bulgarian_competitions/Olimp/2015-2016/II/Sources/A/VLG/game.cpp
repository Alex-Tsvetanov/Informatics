#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m, q;

const int MAXN= 10010, MAXM= 16;
double eps= 0.0000000001;

struct point {
    int x, y;
    int r;
};

point p[MAXN];

int strenght(int x1, int y1, int x2, int y2, int r2) {

    double a= sqrt(double(x1-x2)*double(x1-x2) + double(y1-y2)*double(y1-y2)) + double(r2);
    double b= ceil(a);

    if((b-a) < eps) return b+1;

    return b;
}

int h[MAXM][MAXN];

int bin_search(int i, int x) {
    int l=-1, r= n, mid;

    while((r-l) > 1) {
        mid= (l+r)/2;

        if(h[i][mid] > x) r=mid;
        else l= mid;
    }

    return r;
}

void read() {
    int i, j, x, y;

    scanf("%d%d%d", &n, &m, &q);

    for(i=0; i<n; i++) {
        scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].r);
    }

    for(i=0; i<m; i++) {
        scanf("%d%d", &x, &y);

        for(j=0; j<n; j++) {
            h[i][j]= strenght(x, y, p[j].x, p[j].y, p[j].r);
        }

        sort(h[i], h[i]+n);
    }

    int s, pos;
    int curans=0, ans= 0;
    bool l=0;

    for(i=0; i<q; i++) {
        scanf("%d", &s);

        if(l == 1) {
            s*= 2;
            l= 0;
        }

        curans= 0;

        for(j=0; j<m; j++) {
            pos= bin_search(j, s);

            ans+= pos;
            curans+= pos;
        }

        if(curans % 2 == 0) l= 1;
    }

    printf("%d\n", ans);
}

int main() {

    read();

    return 0;
}
