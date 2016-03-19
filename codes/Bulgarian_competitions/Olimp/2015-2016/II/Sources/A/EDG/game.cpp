#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,q;
struct da{
    int x,y;
    int r;
};
da a[10100];
int ans[30300];
void read(){
    int x,y;
    int i,j;
    double dist;
    int dapa;
    scanf("%d%d%d",&n,&m,&q);
    for(i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y>>a[i].r;
    }
    for(j=1;j<=m;j++){
        cin>>x>>y;
        for(i=1;i<=n;i++){
            dist=(x-a[i].x)*(x-a[i].x)+(y-a[i].y)*(y-a[i].y);
            dist=sqrt(dist)+a[i].r;
            dapa=ceil(dist);
            ans[dapa]++;
        }
    }
    for(i=1;i<=20;i++){
        ans[i]+=ans[i-1];
//        printf("%d ",ans[i]);
    }
}
void solve(){
    int i,dap,ansu=0,currans;
    scanf("%d",&dap);
    currans=ans[dap];
    ansu=currans;
    for(i=2;i<=q;i++){
        scanf("%d",&dap);
        if(currans%2==0)dap*=2;
        currans=ans[dap];
        ansu+=currans;
    }
    printf("%d\n",ansu);
}
int main(){
    read();
    solve();
    return 0;
}
/**
4 1 3
2 2 1
3 5 2
6 2 3
8 8 1
4 4
4 3 3
**/
