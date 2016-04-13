#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std ;

#define inf 1000000007
#define MAXN 200007

int n , st , en ;
int dist[ MAXN ] ;
vector < pair < int , int > > v[ MAXN ] ;

struct tuhla {
    int vertex ;
    int cost ;
};

bool operator < ( struct tuhla p1 , struct tuhla p2 ) {
    return ( p1.cost > p2.cost ) ;
}

priority_queue < struct tuhla > q ;

void dijkstra ( ) {
    struct tuhla u , e ;
    u.vertex = st ;
    u.cost = 0 ;
    dist[ st ] = 0 ;
    while ( q.empty ( ) == false ) { q.pop ( ) ; }
    q.push ( u ) ;
    int i , sz ;
    while ( q.empty ( ) == false ) {
        u = q.top ( ) ;
        q.pop ( ) ;
        if ( u.cost != dist[ u.vertex ] ) { continue ; }
        sz = v[ u.vertex ].size ( ) ;
        for ( i = 0 ; i < sz ; i ++ ) {
            int h = v[ u.vertex ][ i ].first ;
            int c = v[ u.vertex ][ i ].second ;
            if ( dist[ h ] > u.cost + c ) {
                dist[ h ] = u.cost + c ;
                e.vertex = h ;
                e.cost = dist[ h ] ;
                q.push ( e ) ;
            }
        }
    }
}

void input ( ) {
    scanf ( "%d%d%d" , &n , &st , &en ) ;
    int i ;
    int x , y ;
    while ( scanf ( "%d%d" , &x , &y ) != 0 ) {
        v[ x ].push_back ( make_pair ( y , 0 ) ) ;
        v[ y ].push_back ( make_pair ( x , 1 ) ) ;
    }
}

void solve ( ) {
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        dist[ i ] = inf ;
    }
    dijkstra ( ) ;
    if ( dist[ en ] == inf ) { printf ( "X\n" ) ; }
    else { printf ( "%d\n" , dist[ en ] ) ; }
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
