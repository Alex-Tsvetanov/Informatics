#include<iostream>
#include<queue>
using namespace std;
bool matrix[500][500],poseteni[500],krai=false;
queue <int> q;
int main (){
long long n,x,y,i,j,m,izberi=1,answ=1;
cin>>n>>m;
for(i=0;i<m;i++){
  cin>>x>>y;
  matrix[x][y]=true;
  matrix[y][x]=true;
}
while(!krai){
  q.push(izberi);
  poseteni[q.front()]=true;
  while(!q.empty()){
      for(j=1;j<=n;j++){
        if(matrix[q.front()][j] and !poseteni[j]){
          q.push(j);
          poseteni[j]=true;
        }
      }
      q.pop();
  }
  krai=true;
  for(i=1;i<=n;i++){
    if(!poseteni[i]){
      izberi=i;
      answ++;
      krai=false;
      break;
    }
  }
}
cout<<answ<<endl;
return 0;
}