#include <iostream>
using namespace std;
int main ()
{long long int n,a[100000],br=0;
cin>>n;
for(int i=0;i<n;i++)
cin>>a[i];
for(int i=0;i<n;i++)
{if(br==n-i){cout<<a[i-1]<<" ";br=0;}
for(int j=i+1;j<n;j++)
{
if(a[i]>=a[j])br++;
}
}
cout<<a[n-1]<<endl;
return 0;
}
