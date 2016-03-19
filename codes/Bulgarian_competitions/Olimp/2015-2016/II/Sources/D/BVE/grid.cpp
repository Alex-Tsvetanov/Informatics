#include<iostream>
using namespace std;
int main()
{
    int a[201][201],cord[201][201],m,n,r1=0,bl=1,br=0,no;
    cin>>m>>n;
    no=n*m;
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    cin>>cord[i][j];
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    a[i][j]=cord[i][j];
cord[0][0]=1;
while(no==0)
{
for(int j=1;j<n-1;j++)
if(a[0][j]==0&&cord[0][j-1]==0&&a[0][j-1]==bl)a[0][j]=bl;
if(a[0][n-1]==0&&cord[0][n-1]==0)a[0][n-1]=bl;
for(int i=1;i<m;i++)
if(a[i][0]==0&&a[i-1][0]==bl&&cord[i-1][0]==0)a[i][0]=bl;
for(int i=1;i<m-1;i++)
for(int j=1;j<n;j++)
{
if(a[i][j]==0&&a[i-1][j]==bl&&cord[i-1][j]==0)a[i][j]=bl;
if(a[i][n-1]==0&&a[i-1][n-1]==bl&&cord[i-1][n-1]==0)a[i][n-1]=bl;
if(a[i][j]==0)no=1;
}
bl++;
}

        cout<<bl+1<<endl;
        return 0;

}
