#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std ;

int k ;
#define VAC 100000

vector < pair < int , int > > v ;

void input ( ) {
    scanf ( "%d" , &k ) ;
}

void solve ( ) {
    int i ;
    int n , m ;
    int tot = 0 ;
    for ( i = 1 ; i <= VAC ; i ++ ) {
        tot = ( i + k ) ;
        if ( ( i % 2 ) == 0 ) { /// n < m
            n = i / 2 ;
            m = ( tot - n ) / ( 2 * n + 1 ) ;
            if ( ( m * ( 2 * n + 1 ) ) == ( tot - n ) ) {
                if ( n < m ) {
                    v.push_back ( make_pair ( n , m ) ) ;
                }
            }
        }
        else { /// n >= m
            m = ( ( i + 1 ) / 2 ) ;
            n = ( tot - m ) / ( 2 * m + 1 ) ;
            if ( ( n * ( 2 * m + 1 ) ) == ( tot - m ) ) {
                if ( n >= m ) {
                    v.push_back ( make_pair ( n , m ) ) ;
                }
            }
        }
    }
    sort ( v.begin ( ) , v.end ( ) ) ;
    int sz = v.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        printf ( "%d %d\n" , v[ i ].first , v[ i ].second ) ;
    }
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
