#include<iostream>
using namespace std;
bool tab[100][100];
struct Notices{
  int x, y, l, h;
};
int main(){
  int l, h, n, x, y, v, sh, ngs=0, xx, yy, x1, y1, i;
  cin>>l>>h>>n;
  Notices nots[n];
  bool tab[l][h];
  for(i=0;i<n;i++){
    cin>>nots[i].x>>nots[i].y>>nots[i].l>>nots[i].h;
  }
  for(y=0;y<h;y++){
    for(x=0;x<l;x++){
      tab[x][y]=false;
    }
  }
  for(i=0;i<n;i++){
    for(x=nots[i].x;x<nots[i].l+nots[i].x;x++){
      for(y=nots[i].y;y<nots[i].h+nots[i].y;y++){
        tab[x][y]=true;
      }
    }
  }
  for(x=0;x<l;x++){
    for(y=0;y<h;y++){
      if(tab[x][y]==true)continue;
      for(xx=x;xx<l;xx++){
        for(yy=y;yy<h;yy++){
          if(x==xx and y==yy)continue;
          for(x1=x;x1<=xx;x1++){
            for(y1=y;y1<=yy;y1++){
              if(tab[x1][y1]==true)goto tuk;
            }
          }
          if((xx-x+1)*(yy-y+1)>ngs){
            ngs=(xx-x+1)*(yy-y+1);
          }
          tuk:;
        }
      }
    }
  }
  cout<<ngs<<endl;
  return 0;
}
