#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,ch[201][201],p,br,br1;
int main ()
{
    cin >> n >> m;
    br1=0;
    for ( i=0; i<n; i++ )
    {
        for ( j=0; j<m; j++ )
        {
            cin >> ch[i][j];
            if ( ch[i][j]==1 ) br1++;
        }
    }
    p=2;
    ch[0][0]=2;
    br=1;
    while(1)
    {
        for ( i=0; i<n; i++ )
        {
            for ( j=0; j<m; j++ )
            {
                if ( j!=0 && ch[i][j-1]==0 ) { br++; if ( br==m*n-br1 ) break; ch[i][j-1]=p; }
                if ( j!=m-1 && ch[i][j+1]==0 ) { br++; if ( br==m*n-br1 ) break; ch[i][j+1]=p; }
                if ( i!=0 && ch[i-1][j]==0 ) { br++; if ( br==m*n-br1 ) break; ch[i-1][j]=p; }
                if ( i!=n-1 && ch[i+1][j]==0 ) { br++; if ( br==m*n-br1 ) break; ch[i+1][j]=p; }
                if ( j!=m-1 && ch[i][j+1]==1 ) i++;
            }
            if ( br==m*n-br1 ) break;
        }
        if ( br==m*n-br1 ) break;
        p++;
    }
    cout << p-1 << endl;
    return 0;
}
/**
2 4 0 1 1 0 0 0 1 1
*/
