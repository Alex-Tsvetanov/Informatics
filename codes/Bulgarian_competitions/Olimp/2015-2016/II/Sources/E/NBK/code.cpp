#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
  long long m[1000000];
  long long j[1000000];
  long long i,n,k,r,j;
  cin>>m;
  for(i=0;i<=m;i++)
  n=i+1;
  for(j=0;j<=n;j++)
  if(m[i]==m[i+1]) k++;
  if(m[i]!=m[i+1]) {k=k;break;}
  {if(k==0) j=1;
  if(k>0 && k<10) j=2;
  if(k>9 && k<100) j=3;
  if(k>99 && k<1000) j=4;
  if(k>999 && k<10000) j=5;
  if(k>9999 && k<100000) j=6;
  if(k>99999 && k<100000) j=7;
  if(k==1000000) j=8;
  }
  j=j[1]+j[1++];
  r=(n-1)-j;
  cout<<r<<endl;
    return 0;
}
