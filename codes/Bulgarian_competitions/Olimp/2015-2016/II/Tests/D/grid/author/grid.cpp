#include<iostream>
using namespace std;

int t[202][202];
int M, N;

void input()
{
 cin >> M >> N;
 for(int i=1;i<=M;i++)
 for(int j=1;j<=N;j++)
 { int v;
   cin >> v;
   t[i][j]=-v;
 }
}

bool find(int &i0, int &j0)
{
 for(int i=1;i<=M;i++)
 for(int j=1;j<=N;j++)
  if(t[i][j]==0)
   { i0=i; j0=j; return true; }
 return false;
}

int c;

int pi[]={1,-1,0,0};
int pj[]={0,0,1,-1};

void proc(int i, int j)
{
 t[i][j]=c;
 for(int k=0;k<4;k++)
 {
   int it=i+pi[k];
   int jt=j+pj[k];
   if(it>0)if(it<=M)if(jt>0)if(jt<=N)
   if(t[it][jt]==0) proc(it,jt);
 }
}

int main()
{
  input();
  int i0,j0;
  c=0;
  while(find(i0,j0)){c++; proc(i0,j0);}
  cout << c << endl;
}
