#include<iostream>
using namespace std;
char mas[201][201];
long long n,m,br=0;
void rec(long long x,long long y)
{
    if(mas[x+1][y]=='0' && x<n){mas[x][y]='1';rec(x+1,y);}
    if(mas[x-1][y]=='0'){mas[x][y]='1';rec(x-1,y);}
    if(mas[x][y+1]=='0' && y<m){mas[x][y]='1';rec(x,y+1);}
    if(mas[x][y-1]=='0'){mas[x][y]='1';rec(x,y-1);}
    mas[x][y]='1';
    return ;
}
int main ()
{
cin>>n>>m;
for(int i=0;i<n;i++)
for(int j=0;j<m;j++)
cin>>mas[i][j];

for(int i=0;i<n;i++)
{
   for(int j=0;j<m;j++)
    {
    if(mas[i][j]=='0')
    {
        rec(i,j);
        br++;

    }
    }
}

cout<<br<<endl;
return 0;

}

