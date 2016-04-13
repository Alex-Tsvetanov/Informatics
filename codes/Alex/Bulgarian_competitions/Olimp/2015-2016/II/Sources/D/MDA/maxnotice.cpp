#include<iostream>
using namespace std;
int l,h,n;
int i,j,k,p,ms=-1,s,g;
int a,b,x,y;
int t[101][101];
int r( int c , int d )
{
    k = c;
    p = d;
    for( ;; )
    {
        if( k == h || t[k+1][p] == 1 )
        {
            p++;
            b++;
            k = c;
        }
        else
        {
            a ++;
        }
        k ++;
    }
    s = a*b;
    return s;
}
void read()
{
    cin >> l >> h >> n ;
    for( i = 0 ; i < n ; i ++ )
    {
        cin >> x >> y >> a >> b;
        j = x;
        k = y;
        for( k = 0 ; k < a ; k ++ )
            for( j = 0 ; j < b ; j ++ ) t[k][j] = 1;
    }
}
void solve()
{
    for( k = 0 ; k < a ; k ++ )
        for( j = 0 ; j < b ; j ++ )
        {
            g = r(i,j) ;
            if( g > ms )
            {
                ms = g;
            }
        }
}
int main()
{
    read();
    solve();
    cout << g << endl;
}
