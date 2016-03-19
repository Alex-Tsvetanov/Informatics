#include<iostream>
using namespace std;
int a[40002];
int m,n;
int main()
{
 cin>>m>>n;
 int p=m*n,d,k=1;
 for(int i=0; i<p; i++)
  {
   cin>>d;
   a[i]=d;
  }
 for(int i=0; i<p; i++)
  if(a[i]==1) a[i]=209;
   a[0]=1;
 if(a[1]==0) a[1]=1;
 for(int i=1;i<=m;i++)
  {
   if(a[n*i]==0) a[n*i]=1;
  }
 if(a[0+n]==0) a[0+n]=1;
 for(int u=0; u<p*2; u++)
 {for(int i=0; i<m; i++)
  for(int j=1+n*i; j<n+n*i; j++)
   {
    if(i==0)
     if(a[j]==0)
     {
      if(a[j+n]>0&&a[j+n]<209) a[j]=a[j+n];
      if(a[j-1]>0&&a[j-1]<209&&j-1<j+n*i) a[j]=a[j-1];
      if(a[j+1]>0&&a[j+1]<209&&j+1<m) a[j]=a[j+1];
     }
    if(i>0)
    {
    //cout<<"io"<<" "<<j<<endl;
     if(a[j]==0)
      {
      // cout<<a[j]<<" "<<a[j-1]<<endl;
       if(a[j-1]>0&&a[j-1]<209) a[j]=a[j-1];
       if(a[j-n]>0&&a[j-n]<209) a[j]=a[j-n];
       if(a[j+1]>0&&a[j+1]<209) a[j]=a[j+1];
       if(a[j+n]>0&&a[j+n]<209) a[j]=a[j+n];
       //cout<<"io"<<endl;
      }
   }}
   // cout<<a[5]<<" "<<a[4]<<endl;
   if(u>2)
    {k++;
    for(int h=0; h<p; h++)
     if(a[h]==0)
      {
       a[h]=k;
       break;
      }}
  }
 //for(int j=0; j<p; j++)
 // {
  // cout<<a[j]<<" ";
 // }

  int max1=0;
  for(int i=0;i<p;i++)
    if(max1<a[i]&&a[i]<209) max1=a[i];
  cout<<max1<<endl;
  return 0;
}
