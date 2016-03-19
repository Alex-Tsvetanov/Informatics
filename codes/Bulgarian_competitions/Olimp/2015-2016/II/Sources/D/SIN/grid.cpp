#include<iostream>
using namespace std;
int n,m,tabl[201][201],x=1,br;

int rekursiq (int pozx, int pozy, int ch)
{
    br--;
    tabl[pozx][pozy]=ch;
    if (tabl[pozx+1][pozy]==0 && pozx<n) rekursiq (pozx+1,pozy,ch);
    if (tabl[pozx][pozy+1]==0 && pozy<m) rekursiq (pozx,pozy+1,ch);
    if (tabl[pozx-1][pozy]==0 && pozx>1) rekursiq (pozx-1,pozy,ch);
    if (tabl[pozx][pozy-1]==0 && pozy>1) rekursiq (pozx,pozy-1,ch);
}

int main ()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cin>>tabl[i][j];
            if (tabl[i][j]==0) br++;
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (tabl[i][j]==0)
            {
                rekursiq (i,j,x);
                x++;
            }
        }
        if (br==0) break;
    }
    cout<<x-1<<endl;
    return 0;

}
// 2 4 0 1 1 0 0 0 1 1

/*
4 7
0 1 1 0 1 0 0
0 0 1 0 0 1 1
0 0 1 0 1 0 0
1 0 0 1 1 0 0
*/
