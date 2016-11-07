#include<iostream>
#include<cmath>
#include<vector>
#include<cstdio>
using namespace std;
struct circle{
    int x, y, r;
};
struct score{
    int x, y;
};

int n, m, q, x, y, r, p, ans;
vector<circle>a;
vector<score>b;


int main ()
{
    scanf("%d %d %d", &n, &m, &q);
    circle c;
    for(int i=0; i<n; i++){
        scanf("%d %d %d", &x, &y, &r);
        c.x=x;
        c.y=y;
        c.r=r;
        a.push_back(c);
    }
    score s;
    for(int i=0; i<m; i++){
        scanf("%d %d", &x, &y);
        s.x=x;
        s.y=y;
        b.push_back(s);
    }

    double R;
    r=-1;
    for(int k=0; k<q; k++){
        scanf("%d", &p);
        if(r%2==0)r=2*p;
        else r=p;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                x=abs(a[j].x-b[i].x);
                y=abs(a[j].y-b[i].y);
                R=sqrt(x*x+y*y)+a[j].r;
                if(R<=r){
                    ans++;
                }
            }
        }
        r=p;
    }
    printf("%d\n", ans);

    return 0;
}

/*
4 1 3
2 2 1
3 5 2
6 2 3
8 8 1
4 4
4 3 3
*/
