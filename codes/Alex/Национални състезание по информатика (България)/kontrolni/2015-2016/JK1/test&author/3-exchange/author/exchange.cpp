#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N_max=202;
long long int a[N_max];
long long int b[N_max];
long long int aa[N_max];
long long int bb[N_max];
int n;
const int S_max=2002;
long long int s;

const int L_max=50;
long long int t[S_max][N_max][L_max];

int mod=(int)1e6;
string ss="000000";

void init0(int i, int j)
{
  t[i][j][0]=1; t[i][j][1]=0;
}

void init1(int i, int j)
{
  t[i][j][0]=1; t[i][j][1]=1;
}


void add(int i0, int j0, int i1, int j1, int i2, int j2)
{
  int n1=t[i1][j1][0];
  int n2=t[i2][j2][0];
  int n0=max(n1,n2);

  int c=0;
  for(int p=1;p<=n0;p++)
  {
    int v=t[i1][j1][p]+t[i2][j2][p]+c;
    t[i0][j0][p]= v%mod;
    c = v/mod;
  }

  if(c>0){n0++; t[i0][j0][n0]=c;}

  t[i0][j0][0]=n0;
}

void show(int i, int k)
{


  string s;
  s.clear();

  int nik=t[i][k][0];
 // cout << "nik=" << nik << endl;
  for(int p=1; p<=nik; p++)
  {
    string st=ss;
    int j=0;
    int v=t[i][k][p];
 //  cout << "v=" << v << endl;
    while(v>0){st[j]=char(v%10+(int)'0'); v = v/10; j++;}
    s = s.append(st);
  }
 // cout << "s=" << s << endl;
  reverse(s.begin(),s.end());
  while(s[0]=='0')
    { if(s.size()==1) break;
      s.erase(0,1);
    }
  cout << s << endl;
}


void f(int s, int i)
{
  if(t[s][i][0]>-1) return;
  if(i==n-1)
  {
   init0(s,i);
   if(s%a[i]==0)
   {
     int m=s/a[i];
     if(b[i]>=m) init1(s,i);
   }
  }
  else
  {
   init0(s,i);
   long long int m=s/a[i];
   if(b[i]<m) m=b[i];
   for(long long int k=0;k<=m;k++)
   {
    f(s-k*a[i],i+1);
    add(s,i,s,i,s-k*a[i],i+1);
   }
  }
}

int main()
{

  cin >> s >> n;
  for(int i=0;i<n;i++) cin >> aa[i];
  for(int i=0;i<n;i++) cin >> bb[i];

  int j=-1;
  for(int i=0;i<n;i++)
  {
    if(aa[i]!=0)
     {j++;a[j]=aa[i];b[j]=bb[i];aa[i]=0;
      for(int k=i+1;k<n;k++)
       if(aa[k]==a[j]){aa[k]=0;b[j] += bb[k];}
     }
  }

  n=j+1;
/*
  cout << "s=" << s << endl;
  cout << "n=" << n << endl;
  for(int i=0;i<n;i++) cout << a[i] << " ";
  cout << endl;
  for(int i=0;i<n;i++) cout << b[i] << " ";
  cout << endl;
*/
  for(int i=0;i<=s;i++)
  for(int j=0;j<n;j++)
  t[i][j][0]=-1;


//  memset(t, -1, sizeof t);


  f(s,0);

/*
  t[0][0][0]=2;
  t[0][0][1]=500000;
  t[0][0][2]=600000;
  show(0,0);

  t[1][2][0]=2;
  t[1][2][1]=500000;
  t[1][2][2]=600000;
  show(1,2);

  add(0,0,0,0,1,2);

  show(0,0);

*/



  show(s,0);


  //cout << t[s][0] << endl;
}
