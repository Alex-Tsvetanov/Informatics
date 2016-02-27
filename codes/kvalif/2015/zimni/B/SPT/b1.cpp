#include<iostream>
using namespace std;
long long  N,M,n,m, table[1024][1024], X[1024][1024], XY[1024][1024];
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
cin>>N>>M>>n>>m;
for(int y=1;y<=N;y++)
{
    for(int x=1;x<=M;x++)
    {
        cin>>table[x][y];

            X[x][y]=table[x][y]+X[x-1][y];
    }
}
for(int y=0;y<=N;y++)
{
    for(int x=0;x<=M;x++)
    {

            XY[x][y]=X[x][y]+XY[x][y-1];
    }

}
int indX, indY;
long long maxx=0;
for(int y=n;y<=N;y++)
{
    for(int x=m;x<=M;x++)
    {
           long long curr=XY[x][y]-XY[x-m][y]-XY[x][y-n]+XY[x-m][y-n];
           if(curr>maxx)
           {
               maxx=curr;
               indX=x;
               indY=y;
           }
    }
}
cout<<maxx<<endl;//" "<<indX<<" "<<indY<<endl;

return 0;
}
