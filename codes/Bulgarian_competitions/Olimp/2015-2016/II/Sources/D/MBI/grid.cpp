#include<iostream>
using namespace std;
int m,n,a[200][200],brc=1,br=0,p=1,ost,vs,b=0;
int main ()
{
    cin>>m>>n;
    int i,j,d;
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            if (a[i][j]==0)vs++;
        }
    }
    if (vs==m*n) {cout<<"1"<<endl;return 0;}
    if (vs==1) {cout<<"1"<<endl;return 0;}
    
    for (i=0;i<m;i++)
    {
        for (j=0;i<n;i++)
        {
            if(a[i][j]==0) {brc+=0,br++;}
            else 
            {
                if (a[p][j]==0) {brc+=0,br++;}
                else 
                {
                    brc++,ost=vs-br,br=0;
                }
            }
        }
    }
    cout<<brc<<endl;
    return 0;
}