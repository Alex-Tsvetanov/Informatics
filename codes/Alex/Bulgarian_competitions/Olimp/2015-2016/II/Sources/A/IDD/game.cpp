#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
struct point{
    int x;
    int y;
};
int n,m,q;
point mark[16];
point cir[10200];
int r[10200];
double dist[16][10200];
double d(point a, point b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
int main(){
    cin>>n>>m>>q;
    for (int i=0; i<n; ++i){
        cin>>cir[i].x>>cir[i].y>>r[i];
    }
    for (int i=0; i<m; ++i){
        cin>>mark[i].x>>mark[i].y;
    }

    for (int i=0;i<m;++i){
        for (int j=0;j<n;++j){
            dist[i][j] = d(mark[i], cir[j]) + r[j];
        }
        sort(dist[i], dist[i]+n);
    }

    int ans=0, cans, curr;
    bool prev=0;
    for (int i=0; i<q; ++i){
        cans=0;
        cin>>curr;
        if (prev){curr*=2;}
        for (int j=0;j<m;++j){
            double* p = lower_bound(dist[j], dist[j]+n, curr);
            cans += p - dist[j];
        }
        ans += cans;
        prev = cans%2==0;
        //cout<<cans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
