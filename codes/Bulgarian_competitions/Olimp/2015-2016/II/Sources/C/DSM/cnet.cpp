#include<iostream>
#include<queue>
using namespace std;
queue <long long> q;
long long matrix[3001][3001],timer[3001];
bool visited[3001];
int main(){
long long n,m,i,x,y,time=0;
cin>>n>>m;
for(i=0;i<m;i++){
  cin>>x>>y;
  matrix[x][y] = 1;
}
for(i=0;i<n;i++){
   time = 0;
   for(long long j = 0;j < n;j++){
     visited[j] = false;
   }
   q.push(i);
   while(!q.empty()){
       for(long long j=0;j<n;j++){
         if(matrix[q.front()][j]==1){
           q.push(j);
           time++;
           visited[j] = true;
         }
       }
       q.pop();
       bool AllVisited;
       AllVisited = true;
       for(long long j = 0;j < n;j++){
          if(!visited[j]){
            AllVisited = false;
          }
       }
       if(AllVisited or time>n){
         timer[i] = time;
         break;
       }
   }
}
long long Min=100000000000000,index = 0,Count = 0;
for(i=0;i<n;i++){
   for(long long j=0;j<n;j++){
      if(Min>timer[j]){
        Min = timer[j];
        index = j;
      }
   }
   if(Min<=m){
     Count++;
   }
   timer[index] = 100000000000000000;
   Min = 1000000000000000000;
}
cout<<Count<<endl;
Min=100000000000000,index = 0;
for(i=0;i<n;i++){
   for(long long j=0;j<n;j++){
      if(Min>timer[j]){
        Min = timer[j];
        index = j;
      }
   }
   if(Min<=m){
     cout<<index<<" ";
   }
   timer[index] = 100000000000000000;
   Min = 1000000000000000000;
}
return 0;
}
