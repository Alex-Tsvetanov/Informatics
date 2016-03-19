#include <iostream>
using namespace std;
long long int tolio[512][512];
int res;
int main()
{
int p,n,s,i;
cin>>p>>n>>s;
tolio[0][0]=1;
for(int i=1;i<=n;i++)
{
    for(int j=0;j<s;j++)
    for(int o=0;o<p&&o<=j;o++)
    tolio[i][j]+=tolio[i-1][j-o];
}
for(int i=0;i<s;i++)res+=tolio[n][i];
cout<<res<<endl;
 return 0;
 }
