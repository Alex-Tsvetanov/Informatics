#include<iostream>
using namespace std;
int main(){
long long int n,a[155555],max=-1000000001;
cin>>n;
for(long long int i=0;i<n;i++)
{cin>>a[i];
}
for(long long int i=0;i<n;i++)
{max=-1000000001;
for(long long int j=i+1;j<n;j++)
{if(a[j]>a[i]) max=a[i];}
if(max==-1000000001) cout<<a[i]<<" ";}
cout<<endl;
return 0;
}
