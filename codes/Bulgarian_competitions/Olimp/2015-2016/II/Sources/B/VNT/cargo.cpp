#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
priority_queue < pair < int , int > > q;
int n, m, p;
pair < int , int > arr[1000042];

bool able ( bool toW ) {
    int dInd = 1;
    while ( !q.empty() ) { q.pop(); }
    for ( int i = 0 ; 1 ; ) {

        if ( i == m && q.empty() ) { return 1; }
        if ( q.empty() ) {
            dInd = arr[i].first;
        }
  //      cout << "day " << dInd << "\n";
        for ( ; i < m && arr[i].first <= dInd ; i ++ ) {
 //           cout << "pushing " << arr[i].first << " " << arr[i].second << "\n";
            q.push( make_pair( -arr[i].second, -arr[i].first ) );
        }

        if ( toW || ( dInd-1 )%7 < 5 ) {
            for ( int k = p ; 1 ; k -- ) {
                if ( k == 0 ) { break; }
                if ( q.empty() ) { break; }
//                cout << "poping "<< -q.top().second << " " << -q.top().first << "\n";
                q.pop();
            }
        }

        if ( !q.empty() && -q.top().first <= dInd ) {
            return 0;
        }
        dInd ++;
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> p;
    p /= 2;
    for ( int i = 0 ; i < m ; i ++ ) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort( arr, arr+m );
    if ( able( 0 ) ) {
        cout << "OK\n";
    }else if ( able (1) ) {
        cout << "MIXED\n";
    }else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}
