#include<iostream>
#include<math.h>
using namespace std;
long long a[40000];
int main()
{int m,n,k=0,i,max=0,j;

cin>>m>>n;

k=m*n;

for(i=0;i<k;i++)
cin>>a[i];

a[1]=a[1]+pow(10,1);

for(j=1;j>=k;j++)
{
for(i=0;i<k;i++)
if(((i/n!=0)&&(i%n!=0))||((i/n!=0)&&(i%n==0)))
{if(a[i-n]==pow(10,j)&&a[i]==0)a[i]=a[i]+pow(10,j);}
else if(((a[i-1]==pow(10,j))&&(a[i]==0))||((a[i+1]==pow(10,j))&&(a[i]==0))&&(a[i]==0))a[i]=a[i]+pow(10,j);    
}
max=a[0];
for(i=0;i<k;i++)
if(a[i]>max)max=a[i];


cout<<max<<endl;
return 0;    
}