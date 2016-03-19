#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<stack>
using namespace std;
queue<long long>Q;
queue<long long>S;
long long n,m;
long long graf[3001][3001],a,b,p[3001],vreme[2][3001],l=0,s=0,k,otg[3001],d0=0,ng=999999999,g=0,d[3001];
long long bfs(){
    d[Q.front()]=1;
while(Q.empty()==0){
for(long long i=0;i<p[Q.front()];i++){
       // cout<<graf[Q.front()][i]<<" "<<S.front()<<" ";
    if(d[graf[Q.front()][i]]==0){
        d[graf[Q.front()][i]]=1;
        s++;
        if(s==n-1){
          long long res=S.front();
          //cout<<S.front();
          while(Q.empty()==0){
            Q.pop();
            S.pop();
          }
          return res;
        }
        Q.push(graf[Q.front()][i]);
        S.push(S.front()+1);
    }
}
//cout<<"tuk";
Q.pop();
S.pop();
}
return 999999999999;
}
bool dali[3001];
int main(){
ios::sync_with_stdio(false);
cin>>n>>m;
for(long long i=0;i<m;i++){
cin>>a>>b;
graf[a][p[a]]=b;
p[a]++;
}
//cout<<graf[1][0];
for(long long i=0;i<n;i++){
        s=0;
        Q.push(i);
        //cout<<Q.front();
        S.push(0);
        g=bfs();
        for(long long r=0;r<n;r++){
            d[r]=0;
        }
if(d0==0 or g==ng){
otg[d0]=i;
d0++;
}
if(g<ng){
    //cout<<g;
        ng=g;
d0=0;
otg[d0]=i;
d0++;
}
}
//cout<<ng<<" ";
cout<<d0<<"\n";
//sort(otg+0,otg+d0);
for(long long i=0;i<d0;i++){
    cout<<otg[i]<<" ";
}
cout<<"\n";
return 0;
}
