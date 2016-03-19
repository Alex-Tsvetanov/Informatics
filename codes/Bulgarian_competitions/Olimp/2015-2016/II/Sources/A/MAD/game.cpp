#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

struct circle
{
    int x;
    int y;
    int r;
};

struct point
{
    int x;
    int y;
};

circle A[10000];
circle a;
point B[10];
point b;
int C[10000];
double s;
double dist[10][10000];
bool doubleR = false;
int score = 0;

void print_arr(int n, int m)
{
    for(int i = 0; i < n; ++i)
    {
        cout<<dist[m][i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int m, n, q;
    cin>>n>>m>>q;

    for(int i=0; i<n; ++i)
    {
        cin>>a.x>>a.y>>a.r;
        A[i] = a;
    }

    for(int i=0; i<m; ++i)
    {
        cin>>b.x>>b.y;
        B[i] = b;
        for(int j=0; j<n; ++j)
        {
            int dx, dy;
            dx = b.x - A[j].x;
            dy = b.y - A[j].y;
            dist[i][j] = sqrt(dx*dx + dy*dy) + A[j].r;
        }
        sort(dist[i], dist[i] + n);
        //print_arr(n, i);
    }

    for(int i=0; i<q; ++i)
    {
        cin>>s;

        if(doubleR)
        {
            s = s*2;
        }
        int scoreNow = 0;
        for(int j = 0; j<m; ++j)
        {
            double* k = upper_bound(dist[j], dist[j] + n, s);
            int st = k - dist[j];
            //cout<<"st"<<st<<"s = "<<s<<'\n';
            scoreNow += st;
        }
        if(scoreNow % 2 == 0)
        {
            doubleR = true;
        }
        else
        {
            doubleR = false;
        }
        //cout<<scoreNow<<endl;
        score += scoreNow;
    }

    cout<<score<<'\n';
    /*for(int i=0; i<n; ++i)
    {
        cout<<A[i].x<<" ;  "<<A[i].y<<" ;  "<<A[i].r<<'\n';
    }*/
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
