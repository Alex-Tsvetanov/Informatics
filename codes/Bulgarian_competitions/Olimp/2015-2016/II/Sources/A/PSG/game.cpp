#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>
#include<cmath>
using namespace std;

const int MAXN = 16, MAXR = 10007;
int N, Q, M;

struct Circle{
    int x, y, R;
};

vector<Circle> vecCircules;
vector<pair<int, int > > Points;

int PR[MAXN][MAXR];

double Dist (int x1, int y1, int x2, int y2){
    return sqrt ((double) (x1-x2)*(x1-x2)*1.0 + (y1-y2)*(y1-y2)*1.0);
}

void read (){
    scanf ("%d %d %d",&N, &M, &Q);

    int a, b, c;
    for (int i=0; i<N; i++){
        scanf ("%d %d %d",&a, &b, &c);
        Circle help;
        help.x = a; help.y = b; help.R = c;
        vecCircules.push_back (help);
    }

    for (int i=0; i<M; i++){
        scanf ("%d %d",&a, &b);

        Points.push_back (make_pair(a, b));
    }
}

int main (){
    read();

    for (int i=0; i<M; i++)
        for (int j=0; j<N; j++){
            int left = 1, right = MAXR;

            double ans = Dist (Points[i].first, Points[i].second, vecCircules[j].x, vecCircules[j].y)
                                                                            + vecCircules[j].R;

    int ind = ceil (ans);
   // cout << i << " " << j << " "  << ind << endl;
            PR[i][ind]++;
    }

    for (int i=0; i<M; i++)
    for (int j=1; j<MAXR; j++)
    PR[i][j] += PR[i][j-1];

    int ans = 0;
    int r, last = 1;

    for (int i=0; i<Q; i++){
        scanf ("%d",&r);

        for (int j=0; j<M; j++)
        ans += PR[j][r*last];

        if (r%2 == 0) last = 2;
        else last = 1;
    }

    printf ("%d\n",ans);
    return 0;
}
