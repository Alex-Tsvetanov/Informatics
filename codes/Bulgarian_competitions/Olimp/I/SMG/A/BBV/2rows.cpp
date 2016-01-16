#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool are_mrg( vector<int>& s1, vector<int>& s2 );
void find_shared( vector<int>& s1, vector<int>& s2, set<int>& s );

int main()
{
    set<int> s;

    vector<vector<int> > seqs( 10 );

    for( int i = 0; i < 10; ++i )
    {
        int len;
        cin >> len;
        for( int j = 0; j < len; ++j )
        {
            int k;
            cin >> k;
            seqs[i].push_back( k );
        }
    }

    vector<bool> m( 5 );

    for( int i = 0; i < 5; ++i )
    {
        m[i] = are_mrg( seqs[i*2], seqs[i*2+1] );
    }

    for( int i = 0; i < 5; ++i )
    {
        cout << m[i];
    }

    cout << endl;

    return 0;
}

bool are_mrg( vector<int>& s1, vector<int>& s2 )
{
    set<int> shared;

    find_shared( s1, s2, shared );

    int i = 0, j = 0;
    while( i < s1.size() && j < s2.size() )
    {
        if( s1[i] != s2[j] && shared.find( s1[i] ) != shared.end() && shared.find( s2[j] ) != shared.end() )
        {
            return false;
        }
        else
        {
            if( s1[i] == s2[j] )
            {
                ++i;
                ++j;
            }
            if( shared.find( s1[i] ) == shared.end() )
            {
                ++i;
            }
            if( shared.find( s2[j] ) == shared.end() )
            {
                ++j;
            }
        }
    }

    return true;
}

void find_shared( vector<int>& s1, vector<int>& s2, set<int>& s )
{
    set<int> set1;
    for( int i = 0; i < s1.size(); ++i )
    {
        set1.insert( s1[i] );
    }

    for( int i = 0; i < s2.size(); ++i )
    {
        if( set1.find( s2[i] ) != set1.end() )
        {
            s.insert( s2[i] );
        }
    }
}
