#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector <int> v[3000];
bool ans[3000];
queue <int> q;
bool marked[3000];
void null(int n){
    for(int i=0;i<n;i++){
        marked[i]=false;
    }
}
int main (){
int n,m,a,b,c,br=0,br2=0;
cin>>n>>m;
for(int i=1;i<=m;i++){
    cin>>a>>b;
    v[a].push_back(b);
}
for(int i=0;i<n;i++){
    q.push(i);
    br=1;
    marked[i]=true;
    while(!q.empty()){
        int index=q.front();
        marked[index]=true;
        q.pop();
        for(int j=0;j<v[index].size();j++){
            if(!marked[v[index][j]]){
                br++;
                marked[v[index][j]]=true;
                q.push(v[index][j]);
            }
        }
    }
    null(n);
    if(br==n){
        br2++;
        ans[i]=true;
    }
}
cout<<br2<<endl;
for(int i=0;i<=n;i++){
    if(ans[i]) cout<<i<<" ";
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
