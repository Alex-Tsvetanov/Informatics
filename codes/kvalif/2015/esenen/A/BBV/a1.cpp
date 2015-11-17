#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct point{
    int n;
    int x;
    int y;
};

struct angle{
    point p;
    double cos;
};

bool cmp( point a, point b )
{
    if( a.y < b.y )
    {
        return true;
    }
    else if( b.y < a.y )
    {
        return false;
    }
    else if( a.x > b.x )
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<point> P( n );
    point s;
    s.n = 0;
    cin >> s.x >> s.y;

    for( int i = 0; i < n; ++i )
    {
        int x, y;
        cin >> x >> y;
        P[i].n = i + 1;
        P[i].x = x - s.x;
        P[i].y = y - s.y;
    }

    s.x = 0; s.y = 0;

    sort( P.begin(), P.end(), cmp );

    vector<pair<int, int> > A;

    for( int i = 0; i < P.size() - 1; ++i )
    {
        int a1 = P[i].n;
        int a2 = P[i+1].n;
        if( a1 > a2 )
            swap( a1, a2 );
        A.push_back( { a1, a2 } );
    }

    sort( A.begin(), A.end() );

    for( int i = 0; i < A.size(); ++i )
    {
        cout << A[i].first << " " << A[i].second << endl;
    }

    return 0;
}
