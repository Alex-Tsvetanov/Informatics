#include <iostream>
#define lmax 1500

using namespace std;

void sum(int a[],int b[],int s[])
{
 int i,t=0;
 for(i=0;i<lmax;i++)
 {
  s[i]=a[i]+b[i]+t;
  t=s[i]/10;
  s[i]=s[i]%10;
 }
}

void prod(int a[],int x,int p[])
{
 int i,r,t=0;
 for(i=0;i<lmax;i++)
 {
  p[i]=a[i]*x+t;
  t=p[i]/10;
  p[i]=p[i]%10;
 }
}

int main()
{
 int nr1[lmax],nr2[lmax],nr1v[lmax],nr2v[lmax],aux[lmax];
 int n,p,i,x,k;
 cin>>n>>p;

 for(i=0;i<lmax;i++)
  nr1[i]=nr2[i]=nr1v[i]=nr2v[i]=0;

 nr1v[0]=2;
 x=n-2;
 i=0;
 while(x)
 {
  nr2v[i++]=x%10;
  x=x/10;
 }

 for(k=2;k<=p;k++)
 {
  for(i=0;i<lmax;i++) aux[i]=0;
  prod(nr2v,2,aux);
  sum(nr1v,aux,nr1);

  for(i=0;i<lmax;i++) aux[i]=0;
  sum(nr1v,nr2v,aux);
  prod(aux,n-2,nr2);

  for(i=0;i<lmax;i++)
  {
   nr1v[i]=nr1[i];
   nr2v[i]=nr2[i];
  }
 }
 for(i=0;i<lmax;i++) aux[i]=0;
 sum(nr1,nr2,aux);

 i=lmax-1;
 while(!aux[i]) i--;
 while (i>=0)
       cout<<aux[i--];
 cout<<'\n';
 return 0;
}
