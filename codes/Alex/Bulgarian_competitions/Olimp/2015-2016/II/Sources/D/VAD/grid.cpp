#include<iostream>
#define MAXN 202
using namespace std;
int m, n;
bool a[202][202];
void Init ()
{
    for (int i=0; i<MAXN; i++)
        for (int j=0; j<MAXN; j++)
            a[i][j]=false;
    cin>>m>>n;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            if (x==1) a[i][j]=true;
        }
}
void Write_Next (int i, int j)
{
    a[i][j]=false;
    if (i!=0 && a[i-1][j]==true) Write_Next (i-1, j);
    if (j!=0 && a[i][j-1]==true) Write_Next (i, j-1);
    if (i!=(m-1) && a[i+1][j]==true) Write_Next (i+1, j);
    if (j!=(n-1) && a[i][j+1]==true) Write_Next (i, j+1);
}
int Solve ()
{
    int num=1;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
        {
            if (a[i][j]==true)
            {
                num++;
                Write_Next (i, j);
            }
        }
    cout<<num<<endl;
}
int main ()
{
    Init ();
    Solve ();
    return 0;
}
