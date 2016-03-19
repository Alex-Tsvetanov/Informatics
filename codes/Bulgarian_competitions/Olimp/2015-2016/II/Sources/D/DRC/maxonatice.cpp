#include<iostream>
using namespace std;
int main ()
{
long long n,i,a[100000],max,j,flag=0;
cin>>n;
for (i=0;i<n;i++)
cin>>a[i];
for (i=0;i<n;i++)
{ max=a[i];
for (j=i+1;j<n;j++)
if (a[j]>max) flag++;
if (i!=n-1 && flag==0) cout<<a[i]<<" ";
else if (flag==0) cout<<a[i]<<endl;
flag=0;}
return 0;
}



