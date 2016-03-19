#include<iostream>
using namespace std;
int main()
{
int n,i,sum=0;
cin>>n;
int x[n];
for(i=0;i<n;i++)
{
    cin>>x[i];
}

for(i=1;i<n;i++)
{
    if(x[i]<=x[0])sum++;
}
if(sum==n-1)cout<<x[0]<<" ";
i=1;
while(x[i]!=x[n-1])
{
sum=0;
int j;
for(j=i+1;j<n;j++)
{
    if(x[j]<=x[i])sum++;
}
if(sum==n-(i+1))cout<<x[i]<<" ";
i++;
}
cout<<x[n-1]<<endl;
return 0;
}
