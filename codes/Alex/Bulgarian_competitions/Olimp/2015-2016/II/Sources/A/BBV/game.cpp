#include <iostream>
#include <cmath>

using namespace std;

struct circle
{
    int x;
    int y;
    int r;
};

struct point
{
    int x;
    int y;
};

int min_r( point& p, circle& c );

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    circle C[ n ];
    point P[ m ];
    int S[ q ];

    for( int i = 0; i < n; ++i )
    {
        int x, y, r;
        cin >> x >> y >> r;
        C[i].x = x; C[i].y = y; C[i].r = r;
    }

    for( int i = 0; i < m; ++i )
    {
        int x, y;
        cin >> x >> y;
        P[i].x = x; P[i].y = y;
    }

    for( int i = 0; i < q; ++i )
    {
        int s;
        cin >> s;
        S[i] = s;
    }

    int dp[ m ][ n ];

    for( int i = 0; i < m; ++i )
    {
        for( int j = 0; j < n; ++j )
        {
            dp[ i ][ j ] = min_r( P[ i ], C[ j ] );
        }
    }

    int prev_score = 1;
    int total_score = 0;
    for( int i = 0; i < q; ++i )
    {
        int r = S[i];
        int score = 0;
        if( prev_score % 2 == 0 )
            r *= 2;

        for( int j = 0; j < m; ++j )
        {
            for( int k = 0; k < n; ++k )
            {
                if( dp[ j ][ k ] <= r )
                    ++score;
            }
        }

        prev_score = score;
        total_score += score;
    }

    cout << total_score << endl;

    return 0;
}

int min_r( point& p, circle& c )
{
    int x = p.x - c.x;
    int y = p.y - c.y;

    int c_dist = ceil( sqrt( x*x + y*y ) );

    int m_r =  c_dist + c.r;

    return m_r;
}
