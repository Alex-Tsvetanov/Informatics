#include<iostream>
using namespace std;
const int gg=203;
int m,n,t[gg][gg];
void Remove_The_Island(int i,int j)
{
if(t[i][j]==1)return;
t[i][j]=1;
Remove_The_Island(i+1,j);
Remove_The_Island(i-1,j);
Remove_The_Island(i,j-1);
Remove_The_Island(i,j+1);
}
int main()
{
    for(int i=0;i<gg;i++)
        for(int j=0;j<gg;j++)t[i][j]=1;
cin>>m>>n;
for(int i=1;i<=m;i++)
for(int j=1;j<=n;j++)cin>>t[i][j];
int br=0;
for(int i=1;i<=m;i++)
for(int j=1;j<=n;j++)
{
 if(t[i][j]==0){Remove_The_Island(i,j);br++;}
}
cout<<br<<endl;
return 0;
}
