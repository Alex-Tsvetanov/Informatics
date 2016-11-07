#include<iostream>
using namespace std;
long long a[1000000];
int main()
{long long n=0,i,j,br=0;
cin>>n;
for(i=0;i<n;i++)
cin>>a[i];
for(i=0;i<n;i++)
{
    if(br==n-(i))cout<<a[i-1]<<" ";
br=0;
for(j=n-1;j>i;j--)

if(a[i]>=a[j])br++;
}
cout<<a[n-1];
return 0;
}