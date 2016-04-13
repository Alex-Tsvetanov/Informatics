#include<iostream>
using namespace std;
int main(){
long long int m,n,c[200],a[200][200],br=1,br1=0,max=0,b[40000],v=0,k=0,g=0;
cin>>m>>n;
for(long long int i=0;i<m;i++)
{for(long long int j=0;j<n;j++)
{cin>>a[i][j];
}}
for(long long int i=0;i<m;i++)
{for(long long int j=0;j<n;j++)
{if(a[i][j]==1) a[i][j]==-1;}}

while(br!=0)
{br=0;
if(a[0][0]==0) {a[0][0]=1; br++;}
br1++;
if((a[i+1][j]==br1 || a[i-1][j]==br1 || a[i][j+1]==br1 || a[i][j-1]==br1) && a[i][j]==0)
for(long long int i=1;i<m;i++)
{for(long long int j=1;j<n;j++)
{if(a[i][j]==0 && br==0) { br++; b[j]=i; j++;}
if((a[j][j]==br1 || a[i-1][j]==br1 || a[i][j+1]==br1 || a[i][j-1]==br1) && a[i][j]==0) { br++; c[v]=j; b[v]=i; v++;}}}

for(long long int o=0;o<v;o++)
{k=b[o];
g=c[o];
a[k][g]=br1;
}
}
max=a[0][0];
for(long long int i=0;i<m;i++)
{for(long long int t=0;t<m;t++)
{if(a[i][t]>max) max=a[i][t];}}
cout<<max<<endl;
return 0;
}
