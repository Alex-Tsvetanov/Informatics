#include<iostream>
using namespace std;

const int N_max=1000;
long long int a[N_max], b[N_max], aa[N_max], bb[N_max];
int n;
const int S_max=10001;
long long int s;

long long int t[S_max][N_max];

long long int f(int s, int i)
{
  //cout << "s=" << s << " i=" << i << endl;
  if(t[s][i]>-1) return t[s][i];
  if(i==n-1)
   {
    t[s][i]=0;
    if(s%a[i]==0)
     if(s/a[i]<=b[i]) t[s][i]=1;
    return t[s][i];
   }
  else
  {
   long long int bb=0;
   long long int m=s/a[i];
   if(m>b[i]) m=b[i];
   for(int k=0;k<=m;k++)
   {
    //b[i]=k;
    bb += f(s-k*a[i],i+1);
   }
   t[s][i]=bb;
   return bb;
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

  for(int i=0;i<=s;i++)
  for(int j=0;j<n;j++)
  t[i][j]=-1;

  long long int r=f(s,0);
  cout << r << endl;
}
