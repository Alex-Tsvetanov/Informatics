#include <iostream>
#include <map>
#include <cmath>
using namespace std;
map < pair < long long , long long >, long long > m;
long long k;

long long get( long long d, long long n ) {
    return (n+k+d)/(2*n+1);
}

bool check( long long i, long long j ) {
    if ( i <= 0 || j <= 0 )  { return 0; }
    long long nK = (i+1)*j + (j+1)*i;
    if ( i >= j) {
        nK -= (2*j-1);
    }else {
        nK -= 2*i;
    }
    return nK==k;
}

int main () {
    cin >> k;
    for ( long long i = 1 ; (i-1)*(i-1) <= k ; i ++ ) {

        long long c1 = get( -1, i );
        long long c2 = get( 0, i );
//        cout << "- "<< i << " "<< c1 << "\n";
        if ( check( c1, i ) ) { m[make_pair( c1, i )] = 1; }
        if ( check( i, c1 ) ) { m[make_pair( i, c1 )] = 1; }

        if ( check( c2, i ) ) { m[make_pair( c2, i )] = 1; }
        if ( check( i, c2 ) ) { m[make_pair( i, c2 )] = 1; }
    }
    cout << m.size() << "\n";
    for ( map< pair < long long , long long >, long long >::iterator it = m.begin () ; it != m.end() ; it ++ ) {
        cout << ( it->first.first ) << " " << (it->first.second) << "\n";
    }

    return 0;
}
