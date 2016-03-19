#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAXN 3010
vector<int> v[MAXN];
vector<int> vec;
long long m, n;
long long level[MAXN];
int  a, b;
long long plk=0;
long long bfs(int u){
    long long maxl=-1;
    queue<int> q;
    q.push(u);
    level[u]=1;
    while(!q.empty()){
        plk++;
        u=q.front();
        q.pop();
        if(level[u]>maxl){
            maxl=level[u];
        }
        int k=v[u].size();
        for(int i=0;i<k;i++){
            int l=v[u][i];
            if(level[l]==0){
                level[l]=level[u]+1;
                q.push(l);
            }
        }
    }
    return maxl;
}
int main(){
    scanf("%lld %lld", &n, &m);
    for(long long i=0;i<m;i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
    }
    long long mini=500000;
    for(long long i=0;i<n;i++){
        plk=0;
        memset(level,0,sizeof(level));
        long long p=bfs(i);
        if(plk==n){
            if(p==mini){
                vec.push_back(i);
            }
            if(p<mini){
                mini=p;
                vec.clear();
                vec.push_back(i);
            }
        }
    }
    long long sv=vec.size();
    printf("%lld\n", sv);
    sort(vec.begin(), vec.end());
    for(long long i=0;i<sv;i++){
        printf("%d", vec[i]);
        if(i==sv-1) printf("\n");
        else printf(" ");
    }
    return 0;
}
/*
8 13
0 1
0 2
1 3
3 0
7 1
3 5
4 1
4 5
7 5
5 2
5 6
4 7
7 4

*/
