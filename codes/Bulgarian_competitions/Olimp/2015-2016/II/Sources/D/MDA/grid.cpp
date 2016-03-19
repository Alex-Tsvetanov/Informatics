#include<iostream>
#define endl '\n'
using namespace std;
int t[201][201];
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,raz,i,j,p=1;
    cin >> m >> n;
    for( i = 0 ; i < m ; i ++ )
        for( j = 0 ; j < n ; j ++ ) cin >> t[i][j];

    for( i = 0 ; i < m ; i ++ )
    {
        for( j = 0 ; j < n ; j ++ )
        {
            if( t[i][j] == p )
            {
                if( t[i+1][j]  == 0 && i != m-1 ) t[i+1][j] = p + 1;
                if( t[i-1][j]  == 0 && i != 0  ) t[i-1][j] = p + 1;
                if( t[i][j+1]  == 0 && j != n-1 ) t[i][j+1] = p + 1;
                if( t[i][j-1]  == 0 && j != 0 ) t[i][j-1] = p + 1;
            }
        }
        p ++;
    }

    cout << p-1 << endl;
}
