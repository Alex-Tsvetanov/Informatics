#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const double math_pi = 3.14159265359;

struct point
{
    int x;
    int y;
    int quadrant;
    double tangent;

    bool operator==( point& b ){ return ( b.x == this->x && b.y == this->y ); }
    bool operator< ( point& b ){
        if( this->quadrant < b.quadrant )
            return true;
        else if( this->quadrant == 1 || this->quadrant == 3 )
        {
            if( this->tangent < b.tangent )
                return true;
            else
                return false;
        }
        else
        {
            if( this->tangent > b.tangent )
                return true;
            else
                return false;

        }
    }
};

bool cmp( point& a, point& b ){
        if( a.quadrant < b.quadrant )
            return true;
        else if( a.quadrant == 1 || a.quadrant == 3 )
        {
            if( a.tangent < b.tangent )
                return true;
            else
                return false;
        }
        else
        {
            if( a.tangent > b.tangent )
                return true;
            else
                return false;

        }
}
void add( double& total, point a1, point a2 );
void rm( double& total, point a1, point a2, point b1, point b2, vector<point>& ord );
double abs_tan( double tanX );
int quadrant( point a );
double tan1( double ax, double ay );
double tan2( double tanA, double tanB );
void eq( point& cen, point& a1, point& a2, point& b1, point& b2, point& c1, point& c2 );

void bsort( vector<point>& ord )
{
    for( int i = 0; i < ord.size()-1; ++i )
    {
        for(int j = i+1; j < ord.size(); ++j )
            if( ord[i] < ord[j] )
                swap( ord[i], ord[j] );
    }
}

// is b before a
bool before( vector<point>& ord, point a, point b )
{
    bool found = false;
    for( int i = 0; i < ord.size(); ++i )
    {
        if( ord[i] == b )
        {
            found = true;
            break;
        }
        else if( ord[i] == a )
        {
            break;
        }
    }
    return found;
}

bool between( vector<point>& ord, point a1, point a2, point b )
{
    if( before( ord, a2, b ) && !before( ord, a1, b ) )
        return true;
    else
        return false;
}

int main()
{
    point cen;
    cin >> cen.x >> cen.y;

    point a1, a2, b1, b2, c1, c2;
    cin >> a1.x >> a1.y >> a2.x >> a2.y
        >> b1.x >> b1.y >> b2.x >> b2.y
        >> c1.x >> c1.y >> c2.x >> c2.y;
    eq( cen, a1, a2, b1, b2, c1, c2 );
   // double A1tan, A2tan, B1tan, B2tan, C1tan, C2tan;
    a1.tangent = tan1( a1.x, a1.y ); a2.tangent = tan1( a2.x, a2.y );
    b1.tangent = tan1( b1.x, b1.y ); b2.tangent = tan1( b2.x, b2.y );
    c1.tangent = tan1( c1.x, c1.y ); c2.tangent = tan1( c2.x, c2.y );

    a1.quadrant = quadrant( a1 ); a2.quadrant = quadrant( a2 );
    b1.quadrant = quadrant( b1 ); b2.quadrant = quadrant( b2 );
    c1.quadrant = quadrant( c1 ); c2.quadrant = quadrant( c2 );

    vector<point> ord;
    ord.push_back( a1 ); ord.push_back( a2 ); ord.push_back( b1 );
    ord.push_back( b2 ); ord.push_back( c1 ); ord.push_back( c2 );

    bsort( ord );

    //sort( ord.begin(), ord.end(), cmp );

    double total = 0.0;

    add( total, a1, a2 );
    rm( total, a1, a2, b1, b2, ord );
    rm( total, a1, a2, c1, c2, ord);

    add( total, b1, b2 );
    rm( total, b1, b2, c1, c2, ord );

    add( total, c1, c2 );

    double result = total / (2 * math_pi);

    int res = round( result );

    cout << res << endl;

    return 0;

}

void eq( point& cen, point& a1, point& a2, point& b1, point& b2, point& c1, point& c2 )
{
    a1.x -= cen.x; a1.y -= cen.y; a2.x -= cen.x; a2.y -= cen.y;
    b1.x -= cen.x; b1.y -= cen.y; b2.x -= cen.x; b2.y -= cen.y;
    c1.x -= cen.x; c1.y -= cen.y; c2.x -= cen.x; c2.y -= cen.y;
    cen.x = 0; cen.y = 0;
}

void rm( double& total, point a1, point a2, point b1, point b2, vector<point>& ord )
{
     if( between( ord, a1, a2, b1 ) )
    {
        if( before( ord, b2, a2 ) )
        {
            double tanX = tan2( b1.tangent, a2.tangent );
            tanX = abs_tan( tanX );
            total -= tanX;
        }
        else
        {
            double tanX = tan2( b1.tangent, b2.tangent );
            tanX = abs_tan( tanX );
            total -= tanX;
        }
    }
    else if( between( ord, a1, a2, b2 ) )
    {
        //if( b1 < a1 )
        {
            double tanX = tan2( a1.tangent, b2.tangent );
            tanX = abs_tan( tanX );
            total -= tanX;
        }
        /*else
        {
            double tanX = tan2( b1.tangent, b2.tangent );
            tanX = abs_tan( tanX );
            total -= tanX;
        }*/
    }
}
void add( double& total, point a1, point a2 )
{
    double tanA = tan2( a1.tangent, a2.tangent );
    tanA = abs_tan( tanA );
    total += tanA;
}

double abs_tan( double tanX )
{
    if( tanX < 0 )
        return fabs( atan( tanX ) ) + math_pi / 2;
    else
        return atan(tanX);
}

int quadrant( point a )
{
    if( a.x >= 0 )
    {
        if( a.y >= 0 )
            return 1;
        else
            return 4;
    }
    else
    {
        if( a.y >= 0 )
            return 2;
        else
            return 3;
    }
}

double tan1( double ax, double ay )
{
    return ay / ax;
}

double tan2( double tanA, double tanB )
{
    return ( tanA - tanB ) / ( 1 + tanA * tanB );
}
