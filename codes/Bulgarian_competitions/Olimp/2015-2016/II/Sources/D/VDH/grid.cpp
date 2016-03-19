#include <iostream>
using namespace std;
int a[202][202];
int n, m;
void f(int g, int i, int j)
{
   // if (a[i][j]==1 && i==0 && j==0) {f(g, i+1, j); f(g, i, j+1);}
    if (i>=m && j>=n) {if (a[i][j]!=-1) a[i][j]=g;}
    else
    {
        if (a[i][j]==0)
        {
            a[i][j]=g;
            /*if (i==m && j!=n)
            {
                f(g, i, j+1);

            }
            if (i!=m && j==n)
            {
                f(g, i+1, j+1);
            }*/
            if (j<m)f(g, i, j+1);
            if (i<n)f(g, i+1, j);

        }
    }
}
void f1(int i, int j)
{
    if (a[i][j]==1 && i==1 && j==1) {f1(i+1, j); f1(i, j+1);}
    if (i>=m-1 && j>=n-1) {if (a[i][j]!=-1) a[i][j]=1;}
    else
    {
        if (a[i][j]!=-1)
        {
            a[i][j]=1;
            /*if (i==m && j!=n)
            {
                f(g, i, j+1);

            }
            if (i!=m && j==n)
            {
                f(g, i+1, j+1);
            }*/
            if (j<m-1)f1(i, j+1);
            if (i<n-1)f1(i+1, j);

        }
    }
}
int main()
{
    cin>>m>>n;
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            cin>>a[i][j];
            if(a[i][j]==1) a[i][j]=-1;
        }
    }
  //  for (int i=0; i<m; i++)
 //   {
    //    for (int j=0; j<n; j++)
 //       {
            //cout<<a[i]<<" ";
 //       }
        //cout<<endl;
 //   }
    if (a[0][0]==-1) cout<<1<<endl;
    else
    {
        int g=1;
        a[0][0]=1;

        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (i==0 && j==0)
                {
                    f1(i, j);
                    g++;
                }
                if (a[i][j]==0)
                {
                    f(g, i, j);
                    g++;
                }
            }
        }
        int maxg=0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++)if (maxg<a[i][j]) maxg=a[i][j];}
            cout<<maxg<<endl;
    }
    return 0;
}
//2 4 0 1 1 0 0 0 1 1
