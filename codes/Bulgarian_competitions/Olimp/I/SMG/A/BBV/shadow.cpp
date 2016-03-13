#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int count( int x );

int main()
{
    double a, b;
    cin >> a >> b;
    if( a == b )
    {
        double sum = a * a + ( a * a ) / 8;
        int whole = floor( sum );
        int digits = count( whole );
        cout.precision( 3 );
        cout << std::fixed << sum << endl;
    }
    else
    {
        double side = max( a, b ) - min( a, b );

        cout << a * b + side * min( a, b ) << endl;
    }

    return 0;
}

int count( int x )
{
    int br = 0;
    while( x > 0 )
    {
        ++br;
        x /= 10;
    }

    return br;
}
