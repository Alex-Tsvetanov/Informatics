#include <iostream>
#include <string>
#include <vector>

using namespace  std;

const int DIFF = 97;
const int B_BEG = '(';
const int B_END = ')';

bool op( bool lhs, bool rhs );
bool res( string& e, bool *val, int s, int &n_s );
void get_vals( string& s, bool val[] );

int main()
{
    string e;
    cin >> e;

    bool cont = true;
    bool val[ 30 ];

    vector<bool> rest;

    while( cont )
    {
        string s;
        cin >> s;
        if( s[0] == '2' )
            break;
        else
        {
            get_vals( s, val );
        }

        int ns;
        bool r = res( e, val, 0, ns );
        rest.push_back( r );
    }

    for( int i = 0; i < rest.size(); ++i )
        cout << rest[i];
    cout << endl;

    return 0;
}

void get_vals( string& s, bool val[] )
{
    for( int i = 0; i < s.size(); ++i )
    {
        if( s[i] == '0' )
            val[i] = 0;
        else
            val[i] = 1;
    }
}

bool res( string& e, bool *val, int s, int &n_s )
{
    bool current_res = val[ e[s] - DIFF ];

    int i = s+1;
    for( i = s+1; i < e.size(); ++i )
    {
        int new_s;
        if( e[i] == B_BEG )
        {
            current_res = op( current_res, res( e, val, i+1, new_s ) );
            i = new_s;
        }
        else if( e[i] == B_END )
        {
            n_s = i;
            break;
        }
        else
        {
            current_res = op( current_res, val[ e[i] - DIFF ] );
        }
    }

    return current_res;
}

bool op( bool lhs, bool rhs )
{
    if( lhs == 1 && rhs == 1 )
        return 0;
    else
        return 1;
}
