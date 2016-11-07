#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
using namespace std ;

int t , n , p ;
set < int > s ;
map < int , vector < int > > ZX ;

vector < int > v ;

priority_queue < int > q ;

bool f1 ( ) {
    int sz ;
    int i , j ;
    while ( q.empty ( ) == false ) { q.pop ( ) ; }
    i = 0 ;
    while ( i < t ) {
        if ( ZX.find ( i ) != ZX.end ( ) ) {
            v = ZX[ i ] ;
            int sz = v.size ( ) ;
            for ( j = 0 ; j < sz ; j ++ ) {
                q.push ( (-v[ j ]) ) ;
            }
        }
        if ( ( i % 7 ) >= 5 ) { i ++ ; continue ; }
        int VAC = p ;
        while ( VAC != 0 && q.empty ( ) == false ) {
            int x = q.top ( ) ;
            x = -x ;
            if ( x < i ) { return false ; }
            q.pop ( ) ;
            VAC -- ;
        }
        if ( q.empty ( ) == true ) {
            set < int > :: iterator d ;
            d = s.upper_bound ( i ) ;
            if ( d == s.end ( ) ) { return true ; }
            i = ( (*d) - 1 ) ;
        }
        i ++ ;
    }
    if ( q.empty ( ) == false ) { return false ; }
    return true ;
}

bool f2 ( ) {
    int sz ;
    int i , j ;
    while ( q.empty ( ) == false ) { q.pop ( ) ; }
    i = 0 ;
    while ( i < t ) {
        if ( ZX.find ( i ) != ZX.end ( ) ) {
            v = ZX[ i ] ;
            int sz = v.size ( ) ;
            for ( j = 0 ; j < sz ; j ++ ) {
                q.push ( (-v[ j ]) ) ;
            }
        }
        int VAC = p ;
        while ( VAC != 0 && q.empty ( ) == false ) {
            int x = q.top ( ) ;
            x = -x ;
            if ( x < i ) { return false ; }
            q.pop ( ) ;
            VAC -- ;
        }
        if ( q.empty ( ) == true ) {
            set < int > :: iterator d ;
            d = s.upper_bound ( i ) ;
            if ( d == s.end ( ) ) { return true ; }
            i = ( (*d) - 1 ) ;
        }
        i ++ ;
    }
    if ( q.empty ( ) == false ) { return false ; }
    return true ;
}

void input ( ) {
    scanf ( "%d%d%d" , &t , &n , &p ) ;
    p /= 2 ;
    int i ;
    int x , y ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d%d" , &x , &y ) ;
        x -- ; y -- ;
        s.insert ( x ) ;
        ZX[ x ].push_back ( y ) ;
    }

}

void solve ( ) {
    if ( f1 ( ) == true ) { printf ( "OK\n" ) ; }
    else if ( f2 ( ) == true ) { printf ( "MIXED\n" ) ; }
    else { printf ( "IMPOSSIBLE\n" ) ; }
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
