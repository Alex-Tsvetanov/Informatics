#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int k, m, p;
vector < int > input;
vector < int > ans;
int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> p >> m;
    for ( int i = 0 ; i < m ; i ++ ) {
        int a, b;
        cin >> a >> b;
        input.push_back( a );
        input.push_back( b );
    }
    cin >> k;
    sort( input.begin(), input.end() );
    for ( int i = 0 ; i < input.size() ; ) {
        int j = i;
        for ( ; j < input.size() && input[i] == input[j] ; j ++ ) {}
        if ( j-i >= k ) {
            ans.push_back(input[i]);
        }
        i = j;
    }
    cout << ans.size() << "\n";
    for ( int i = 0 ; i < ans.size() ; i ++ ) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
/*
    6 7
    1 2
    1 4
    2 3
    2 4
    2 5
    3 4
    3 6
    3
*/
