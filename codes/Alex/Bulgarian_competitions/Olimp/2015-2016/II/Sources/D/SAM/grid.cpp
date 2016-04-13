#include<iostream>
using namespace std;
int a[200][200];
int n,m;
void Zapalvane(int i,int j)
{
    bool f=false;
    a[i][j]=1;
    if(a[i+1][j]==0&&(i!=n-1)) {Zapalvane(i+1,j);f=true;}
    if(a[i-1][j]==0&&(i!=0)) {Zapalvane(i-1,j);f=true;}
    if(a[i][j+1]==0&&(j!=m-1)) {Zapalvane(i,j+1);f=true;}
    if(a[i][j-1]==0&&(j!=0)) {Zapalvane(i,j-1);f=true;}
    if(f==false) return;
}
void Read()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
}
void Solve()
{
    int br=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
              if(a[i][j]==0)
            {
                br++;
                Zapalvane(i,j);
            }
        }
    }
    cout<<br<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    Read();
    Solve();
    return 0;
}
