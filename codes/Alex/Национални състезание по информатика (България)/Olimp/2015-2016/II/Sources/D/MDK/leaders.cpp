#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int gg=1000024;
int n,m[gg],m1[gg];
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)scanf("%i",&m[i]);
m1[n]=m[n];
for(int i=n-1;i>=1;i--)m1[i]=max(m1[i+1],m[i]);
for(int i=1;i<n;i++)
{
if(m[i]==m1[i])
{
printf("%i",m[i]);
printf("%c",' ');
}
}
cout<<m[n]<<endl;
return 0;
}
