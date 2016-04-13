#include<iostream>
#include<stdio.h>
using namespace std;
int circles[10001][3];
int btree[11][20001];
int update (int ind, int x) {
    for (;;) {
        btree[ind][x]+=1;
        x+=x&(-x);
        if (x>20000) break;
        }
}
int find (int ind, int x) {
    int sb=0;
    for (;;) {
        sb+=btree[ind][x];
        x-=x&(-x);
        if (x==0) break;
        }
    return sb;
}
int main () {
    int n,m,q,i,j,x,y,l,r,mid,ans,dist,d,curp=0,prev1;
    scanf("%d%d%d",&n,&m,&q);
    for (i=0; i<n; i++) {
        scanf("%d%d%d",&circles[i][0],&circles[i][1],&circles[i][2]);
        }
    for (i=0; i<m; i++) {
        scanf("%d%d",&x,&y);
        for (j=0; j<n; j++) {
            l=0; r=20001;
            dist=(circles[j][0]-x)*(circles[j][0]-x)+(circles[j][1]-y)*(circles[j][1]-y);
            for (;;) {
                if (l==r-1) break;
                mid=(l+r)/2;
                if (mid*mid>=dist) {
                   ans=mid;
                   r=mid;
                   }
                else l=mid;
                }
            d=ans+circles[j][2];
            update(i,d);
            }
        }
    prev1=1;
    for (i=0; i<q; i++) {
        scanf("%d",&x);
        if (prev1%2==0) x*=2;
        prev1=0;
        for (j=0; j<m; j++) {
            prev1+=find(j,x);
            }
        curp+=prev1;
        }
    cout << curp ;
    cout << endl ;
    return 0;
}
