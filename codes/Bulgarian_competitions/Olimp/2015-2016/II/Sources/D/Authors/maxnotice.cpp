// Task maxnotice
#include<iostream>
#include<iomanip>
using namespace std;

const int MAXVAL=(int)1e9;

int n,m,k;
int t[102][102];
int maxs;

int main()
{
  cin >> m >> n >> k;
  for(int p=1;p<=k;p++)
  {
    int i0,j0,id,jd;
    cin >> j0 >> i0 >> jd >> id;
    for(int i=i0;i<=i0+id-1;i++)
    for(int j=j0;j<=j0+jd-1;j++) t[i][j]=1;
  }
  for(int i=0;i<n;i++)
  for(int j=0;j<m;j++)
  if(t[i][j]==0)
  { int s=0;
    int w=MAXVAL;
    int h=0;
    for(int it=i;it<n;it++)
     {if(t[it][j]==1) break;
      h++;
      int c=0;
      for(int jt=j;jt<m;jt++)
       {if(t[it][jt]==1) break; c++;}
      if(w>c)w=c;
      if(h*w>s) s=h*w;
     }
    if(maxs<s) maxs=s;
  }
  cout << maxs << endl;
}
