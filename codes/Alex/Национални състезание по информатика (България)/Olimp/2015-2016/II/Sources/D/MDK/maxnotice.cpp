#include<iostream>
#include<algorithm>
using namespace std;
bool t[103][103];
int st[103][103];
int l,h,a,b,c,d;
int st1(int A,int B)
{
if(-1<A&&-1<B)return st[A][B];
return 0;
}
int main()
{
int i,j,i1,j1,k;
cin>>l>>h;
int n;
cin>>n;
for(i=0;i<n;i++)
{
cin>>b>>a;
cin>>d>>c;
for(j=a;j<a+c;j++)
for(k=b;k<b+d;k++)t[j][k]=1;
}
st[0][0]=t[0][0];
for(i=1;i<l;i++)st[0][i]=st[0][i-1]+t[0][i];
for(j=1;j<h;j++)st[j][0]=st[j-1][0]+t[j][0];
for(i=1;i<h;i++)
{
for(j=1;j<l;j++)st[i][j]=st[i][j-1]+st[i-1][j]-st[i-1][j-1]+t[i][j];
}
int ans=0;
for(i=0;i<h;i++)
for(j=0;j<l;j++)
{
if(t[i][j]==0)
{


for(i1=i+ans/(l-j);i1<h;i1++)
for(j1=j+ans/(i1-i+1);j1<l;j1++)
{
if(st1(i1,j-1)+st1(i-1,j1)==st[i1][j1]+st1(i-1,j-1))ans=max(ans,(i1-i+1)*(j1-j+1));
}
}
}
cout<<ans<<endl;
return 0;
}
