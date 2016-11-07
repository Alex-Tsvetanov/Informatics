#include<iostream>
using namespace std;
int a[101][101],l,h,n,x,y,l1,h1,k,brl,brh,max1,used[101][101],f[101],p[101],min=103;
void search (int i,int j)
{
if(max1<(f[j]-i-1)*(p[i]-j-1)) max1=(f[j]-i-1)*(p[i]-j-1);

}
int main ()
{
 int i,j;
 cin>>l>>h>>n;
 if(n==0) cout<<l*h<<endl;
 else
 {
    for(i=0;i<n;i++)
    {
    cin>>x>>y>>l1>>h1;
    for(k=x;k<=l1;k++)
    for(j=y;j<=h1;j++) a[k][j]=1;
    }
  for(j=0;j<h;j++)
  {
  for(i=0;i<l;i++)
  {
  if(a[i][j]==1) {f[j]=i+1;}
  }
  if(f[j]==0) f[j]=l+1;
  }
   for(i=0;i<l;i++)
  {
  for(j=0;j<h;j++)
  {
  if(a[i][j]==1) {p[i]=j;}
  }
  if(p[i]==0) p[i]=h;
  }
  for(i=0;i<l;i++)
  for(j=0;j<h;j++)
  {
  if(a[i][j]==0) search(i,j);
  }
 cout<<max1<<endl;
 }

 return 0;
}
