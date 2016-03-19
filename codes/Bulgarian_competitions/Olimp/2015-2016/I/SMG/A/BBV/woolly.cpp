#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const char _1 = '1';
const char _0 = '0';
const char _Q = '?';

void add( string& n, string& k, string& output );
void count( const char& a, const char& b, const char& c, int& q, int& one, int& zero );
void count( const char& a, const char& b, int& q, int& one, int& zero );

int main()
{
    string n1, n2;
    cin >> n1 >> n2;
    reverse( n1.begin(), n1.end() );
    reverse( n2.begin(), n2.end() );

    string out;

    if( n1.size() > n2.size() )
    {
        add( n1, n2, out );
    }
    else
    {
        add( n2, n1, out );
    }

    cout << out << endl;

    return 0;
}

void add( string& n, string& k, string& output )
{
    int sz = min( n.size(), k.size() );

    char carry = _0;

    for( int i = 0; i < sz; ++i )
    {
        int q = 0, one = 0, zero = 0;
        count( n[i], k[i], carry, q, one, zero );
        if( q > 0 )
        {
            output.push_back( _Q );

            if( one >= 2 )
            {
                carry = _1;
            }
            else
            {
                carry = _Q;
            }
        }
        else
        {
            if( one >= 1 )
            {
                if( one == 2 )
                {
                    output.push_back( _0 );
                }
                else
                {
                    output.push_back( _1 );
                }
            }
            else
            {
                output.push_back( _0 );
            }

            if( one >= 2 )
            {
                carry = _1;
            }
            else
            {
                carry = _0;
            }
        }
    }

    while( carry != _0 && sz < n.size() )
    {
        int q = 0, one = 0, zero = 0;
        count( n[sz], carry, q, one, zero );
        if( q > 0 )
        {
            output.push_back( _Q );
            if( zero > 0 )
            {
                carry = _0;
            }
            else
            {
                carry = _Q;
            }
        }
        else
        {
            if( one == 0 )
            {
                output.push_back( _0 );
                carry = _0;
            }
            else if( one == 1 )
            {
                output.push_back( _1 );
                carry = _0;
            }
            else
            {
                output.push_back( _0 );
                carry = _1;
            }
        }

        ++sz;
    }

    while( sz < n.size() )
    {
        output.push_back( n[sz] );

        ++sz;
    }

    if( carry != _0 )
    {
        output.push_back( carry );
    }

    reverse( output.begin(), output.end() );
}

void count( const char& a, const char& b, int& q, int& one, int& zero )
{
    switch( a )
    {
        case _0: ++zero; break;
        case _1: ++one; break;
        case _Q: ++q; break;
    }
    switch( b )
    {
        case _0: ++zero; break;
        case _1: ++one; break;
        case _Q: ++q; break;
    }
}

void count( const char& a, const char& b, const char& c, int& q, int& one, int& zero )
{
    switch( a )
    {
        case _0: ++zero; break;
        case _1: ++one; break;
        case _Q: ++q; break;
    }
    switch( b )
    {
        case _0: ++zero; break;
        case _1: ++one; break;
        case _Q: ++q; break;
    }
    switch( c )
    {
        case _0: ++zero; break;
        case _1: ++one; break;
        case _Q: ++q; break;
    }
}
