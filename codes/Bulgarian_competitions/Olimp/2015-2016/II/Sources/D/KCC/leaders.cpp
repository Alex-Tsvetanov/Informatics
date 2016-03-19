#include<bits/stdc++.h>
using namespace std;
int n,i,ch,p,br,bri;
int main ()
{
    cin >> n;
    cin >> ch;
    p=ch;
    br=0;
    bri=0;
    for ( i=2; i<=n; i++ )
    {
        cin >> ch;
        if ( p>ch ) { br++; if ( br==1 ) cout << p; else cout << " " << p; bri++; }
        else if ( i==n && ch>=p ) { br++; if ( br==1 ) cout << ch; else cout << " " << ch; }
        p=ch;
    }
    cout << endl;
    return 0;
}
/**
7
50 1 40 2 3 4 30
*/
