#include <iostream>
using namespace std;

int main()
{
    int m,n;
    cin>> n >> m;
    int uch1, uch2;
    bool pozn[501][501] = {0};
    int br=0;
    for(int i=1; i<=m; i++)
    {
        cin >> uch1 >> uch2;
        pozn[uch1][uch2]=1;
        pozn[uch2][uch1]=1;
    }
    for(int i=1; i<=n; i++)
    {
        pozn[i][i]=1;
        for(int j=1; j<=n; j++)
        {
            for(int k=1; k<=n; k++)
            {
                if(j!=k && i!=j && j!=k)
                {
                    if(pozn[i][j]==1 || pozn[j][i]==1 || pozn[j][k]==1 || pozn[k][j]==1 || pozn[i][k]==1 || pozn[k][i]==1)
                    {
                        pozn[i][j]=1;
                        pozn[i][k]=1;
                        pozn[j][k]=1;
                        pozn[j][i]=1;
                        pozn[k][i]=1;
                        pozn[k][j]=1;
                    }
                }

            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        pozn[0][i]=1;
        pozn[i][0]=1;
        pozn[0][0]=1;
        for(int j=1; j<=n; j++)
        {
            if(pozn[i][j]==0 && pozn[j][i]==0) br++;
        }
    }
    cout <<  br;
    return 0;
}
