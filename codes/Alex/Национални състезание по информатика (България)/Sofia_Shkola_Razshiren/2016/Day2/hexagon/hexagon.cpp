//Task hexagon
//Authors Emil Kalawedgiev, Pano Panov
#include<iostream>
#include<iomanip>
using namespace std;

const int N=1000;

int a[N][2*N];
int b[N][2*N];
int k;
int ct;
int n;

void input()
{
  cin >> k;
  int d=3;
  int v;
  int pi=1;
  int pj=k;
  for(int i=1;i<=k;i++)
  {
    int pj0=pj;
    for(int j=1;j<=d;j++)
    {
      cin >> a[pi][pj0];
      ct++; b[pi][pj0]=ct; pj0 = pj0+2;
    }
    d++;
    pi++;
    pj--;

  }
  d--;
  pj=2;
  for(int i=1;i<=k-1;i++)
  {
    d--;
    int pj0=pj;
    for(int j=1;j<=d;j++)
     {
      cin >> a[pi][pj0];
      ct++; b[pi][pj0]=ct; pj0 = pj0+2;
     }
    pi++;
    pj++;
  }
  n=ct;
}


bool inside(int i, int j)
{
 if(i<1) return false;
 if(i>2*k-1) return false;
 if(j<1) return false;
 if(j>2*(3+k-1)-1) return false;
 if(b[i][j]==0) return false;
 return true;
}

bool e(int d, int v)
{
  int p=1;

  while(p<=32)
  {
   if(v%2==1) if(p==d) return true;
   v = v/2;
   p = 2*p;
  }
  return false;
}


int s[N*N][7];

void makegraph()
{
 for(int i=1;i<=2*k-1;i++)
 {
   for(int j=1;j<=2*(3+k-1)-1;j++)
   if(b[i][j] > 0)
   {
     if(inside(i-1,j-1))
      {
        if(e(32,a[i][j])&&e(4,a[i-1][j-1]))
         {
           s[b[i][j]][0]++; s[b[i][j]][s[b[i][j]][0]]=b[i-1][j-1];
         }
      }
     if(inside(i-1,j+1))
      {
       if(e(1,a[i][j])&&e(8,a[i-1][j+1]))
       {
        s[b[i][j]][0]++; s[b[i][j]][s[b[i][j]][0]]=b[i-1][j+1];
       }
      }
     if(inside(i,j-2))
      {
       if(e(16,a[i][j])&&e(2,a[i][j-2]))
        {
         s[b[i][j]][0]++; s[b[i][j]][s[b[i][j]][0]]=b[i][j-2];
        }
      }
     if(inside(i,j+2))
      {
       if(e(2,a[i][j])&&e(16,a[i][j+2]))
        {
         s[b[i][j]][0]++; s[b[i][j]][s[b[i][j]][0]]=b[i][j+2];
        }
      }
     if(inside(i+1,j-1))
      {
       if(e(8,a[i][j])&&e(1,a[i+1][j-1]))
        {
         s[b[i][j]][0]++; s[b[i][j]][s[b[i][j]][0]]=b[i+1][j-1];
        }
      }
     if(inside(i+1,j+1))
      {
       if(e(4,a[i][j])&&e(32,a[i+1][j+1]))
        {
          s[b[i][j]][0]++; s[b[i][j]][s[b[i][j]][0]]=b[i+1][j+1];
        }
      }
   }
 }
}


int p[N*N];
int rec=0;;
int m;

void dfs(int j)
{
  m++; p[j]=m;
  for(int i=1;i<=s[j][0];i++)
  if(p[s[j][i]]==0) dfs(s[j][i]);
}


void find()
{
 for(int j=1;j<=n;j++)
 if(p[j]==0)
 {
   m=0;
   dfs(j);
   if(rec < m) rec=m;
 }
}

int main()
{
  input();
  makegraph();
  find();
  cout << rec << endl;
}
