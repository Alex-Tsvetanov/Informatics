#include <iostream>
using namespace std;
long long a[10000000],b[100000000],c[100000000];
int main()
{ int n, k; 
long long max=-2000000000, min=2000000000, s=0;
  cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
  cin>>a[i]; s=s+a[i]; 
  }
  for(int i=1;i<=n;i++)b[i]=s-a[i];
  
  for(int j=1;j<k;j++)
  {s=0;
  {
   for(int i=1;i<=n;i++)
   s=s+b[i]; 
   for(int i=1;i<=n;i++)
   {c[i]=s-b[i];b[i]=c[i];}
  }
}
if(k==1)
{
for(int i=1;i<=n;i++)
{ 
  if(max<b[i]) max=b[i];
  if(min>b[i]) min=b[i];
  } 
} else
{
for(int i=1;i<=n;i++)
{ 
  if(max<c[i]) max=c[i];
  if(min>c[i]) min=c[i];
  }
}
  cout<<max-min<<endl;
  
}
