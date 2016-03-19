#include<iostream>
using namespace std;

int vhod[202][202];
void darvo(int kolko, int x, int y){
  vhod[x][y]=kolko;
  if(vhod[x+1][y]==0)darvo(kolko,x+1, y);
  if(vhod[x-1][y]==0)darvo(kolko,x-1, y);
  if(vhod[x][y+1]==0)darvo(kolko,x, y+1);
  if(vhod[x][y-1]==0)darvo(kolko,x, y-1);
}

int main(){
  int x, y, m, n, a, kolko=1;
  for(y=0;y<202;y++){
    for(x=0;x<202;x++){
      vhod[y][x]=-1;
    }
  }
  cin>>m>>n;
  for(y=1;y<m+1;y++){
    for(x=1;x<n+1;x++){
      cin>>a;
      if(a==0)vhod[y][x]=0;
    }
  }
  for(y=1;y<m+1;y++){
    for(x=1;x<n+1;x++){
      if(vhod[y][x]==0){
        darvo(kolko, y, x);
        kolko++;
      }
    }
  }
  cout<<kolko-1<<endl;
  return 0;
}
