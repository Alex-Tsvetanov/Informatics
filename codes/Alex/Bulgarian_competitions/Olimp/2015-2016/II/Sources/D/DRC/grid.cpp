#include<iostream>
using namespace std;
int main ()
{
long long m,n,a[40000],i,br=0;
cin>>m>>n;
for (i=0;i<m*n;i++)
{cin>>a[i];
if (a[i]==0) br++;}
if (br==1) cout<<1;
if (br==0) cout<<0;
return 0;
}