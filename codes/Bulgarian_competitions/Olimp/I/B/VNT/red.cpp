#include <iostream>
using namespace std;
int n, input[20042], maxN = -1<<30, minN = 1 << 30;
int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> input[i];
        maxN = max(maxN, input[i]);
        minN = min(minN, input[i]);
    }
    int s1, s2, f1, f2;
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( input[i] == minN ) { s1 = i; break; }
    }
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( input[i] == maxN ) { s2 = i; break; }
    }
    for ( int i = n-1 ; i >= 0 ; i -- ) {
        if ( input[i] == maxN ) { f1 = i; break; }
    }
    for ( int i = n-1 ; i >= 0 ; i -- ) {
        if ( input[i] == minN ) { f2 = i; break; }
    }
    if ( f1-s1 > f2-s2 ) {
        cout << s1+1 << " " << f1+1 << "\n";
    }else if ( f1-s1 < f2-s2 ) {
        cout << s2+1 << " " << f2+1 << "\n";
    }else {
        if ( f1+s1 < f2+s2 ) {
            cout << s1+1 << " " << f1+1 << "\n";
        }else {
            cout << s2+1 << " " << f2+1 << "\n";
        }
    }
    return 0;
}
/*
10
3 1 2 5 5 4 4 5 3 1

*/
