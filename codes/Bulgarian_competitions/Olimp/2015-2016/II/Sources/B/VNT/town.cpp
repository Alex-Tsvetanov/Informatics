#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int a, b, n;
vector < pair < int , int > > neigh[200042];
bool used[200042];
int ans[200042];
priority_queue < pair < int , int > > q;

void dj ( int s ) {

    for ( q.push( make_pair( 0, s ) ); !q.empty() ; ) {
        int crr = q.top().second;
        int len = -q.top().first;
        q.pop();
        if ( used[crr] ) { continue; }
        used[crr] = 1;
        ans[crr] = len;
        for ( int i = 0 ; i < neigh[crr].size() ; i ++ ) {
            q.push( make_pair ( -( len + neigh[crr][i].second ), neigh[crr][i].first ) );
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> a >> b;
    int u, v;
    while ( cin >> u >> v ) {
        neigh[u].push_back( make_pair( v, 0 ) );
        neigh[v].push_back( make_pair( u, 1 ) );
    }
    dj( a );
    if ( !used[b] ) {
        cout << "X\n";
    }else {
        cout << ans[b] << "\n" ;
    }
    return 0;
}
