#include<iostream>
using namespace std;
char mas[101][101];
long long n,m,br=0,d=0,sh=0,max1;
void rec(long long x,long long y)
{
    int y1=y,x1=x,i=0,j=0,sh1=0,sh2=0,d1=0,d2=0,sum1=0,sum2=0,i1,j1;
    while(mas[x1][y]=='0' && y<m)y++;
    sh1=y-y1+1;
    for(i=x1;i<n;i++)
    {
    for(j=y1;j<y;j++)
    {
        if(mas[i][j]=='1')
        {
            i1=i-x1;
            i=n;
            j=y;
        }
    }
    }
    d1=i1;

    while(mas[x][y1]=='0' && x<n)x++;
    sh2=x-x1+1;
    for(i=x1;i<x;i++)
    for(j=y1;j<m;j++)
    {
        if(mas[i][j]=='1'){j1=j-y1;i=x;j=m;}
    }
    d2=j1;
    sum1=sh1*d1;
    sum2=sh2*d2;
    if(max1<sum1 && sum1<10000)max1=sum1;
    if(max1<sum2 && sum2<10000)max1=sum2;
}





void generate(long long x,long long y,long long a,long long b)
{
    for(int i=x;i<x+a;i++)
    for(int j=y;j<y+b;j++)
    mas[j][i]='1';
}









int main ()
{

long long k,x,y,a,b;


max1=0;
cin>>m>>n>>k;
for(int i=0;i<n;i++)
for(int j=0;j<m;j++)
mas[i][j]='0';
for(int i=0;i<k;i++)
{
cin>>x>>y>>a>>b;
generate(x,y,a,b);
}


for(int i=0;i<n;i++)
for(int j=0;j<m;j++)
{rec(i,j);}




cout<<max1<<endl;
return 0;

}
/*
12 8
2
2 0 3 3
6 1 5 4
*/
