#include <iostream>
#include <list>

using namespace std;

typedef long long lint;

bool does_cross( lint a1, lint b1, lint a2, lint b2 );

int main()
{
    lint m, n;
    cin >> m >> n;

    list<pair<lint,lint> > secs;

    for( lint i = 0; i < n ; ++i )
    {
        lint a, b;
        cin >> a >> b;
        for( list<pair<lint,lint> >::iterator iter = secs.begin(); iter != secs.end(); iter )
        {
            if( does_cross( iter->first, iter->second, a, b ) )
            {
                iter = secs.erase( iter );
            }
            else
            {
                ++iter;
            }
        }

        pair<lint,lint> ab( a,b );
        secs.push_back( ab );
    }

    cout << secs.size() << endl;

    return 0;
}

bool does_cross( lint a1, lint b1, lint a2, lint b2 )
{
    if( a1 <= a2 && a2 <= b1 )
    {
        return true;
    }
    else if( a1 <= b2 && b2 <= b1 )
    {
        return true;
    }
    else
    {
        return false;
    }
}
