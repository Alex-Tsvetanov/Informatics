#include<bits/stdc++.h>
using namespace std;
long long a[1010000];
int main()
{long long h=0,j,n,i;
bool f=0;
cin>>n;
for(i=0;i<n;i++)cin>>a[i];
for(i=0;i<n-1;i++)
{for(j=i+1;j<n;j++)
{if(a[i]<a[j]){f=1;break;}
}
if(f==0)cout<<a[i]<<" ";
f=0;
}
cout<<a[n-1]<<endl;
return 0;
}
