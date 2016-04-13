#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <queue>

using namespace std;

typedef vector<vector<short> > Graph;
void BFS( Graph& G, short *dp );

int main()
{
    string s;
    cin >> s;

    Graph G( s.size() + 1 );
    for( short i = 0; i < G.size() - 1; ++i )
    {
        G[i].push_back( i+1 );
    }

    for( short i = 1; i < G.size()-1; ++i )
    {
        for( short j = 0; j < i; ++j )
        {
            if( s[j] == s[i] )
            {
                if( i - j == 1 || G[j+1].back() == i )
                {
                    G[j].push_back( i+1 );
                }
            }
        }
    }

    short dp[ G.size() ];
    for( short i = 0; i < G.size(); ++i )
    {
        dp[i] = SHRT_MAX;
    }
    dp[0] = 0;

    BFS( G, dp );

    cout << dp[ G.size() - 1 ] - 1 << endl;

    return 0;
}

void BFS( Graph& G, short *dp )
{
    queue<short> Q;
    Q.push( 0 );

    while( !Q.empty() )
    {
        int top = Q.front();
        Q.pop();

        for( int i = 0; i < G[top].size(); ++i )
        {
            int v = G[top][i];

            if( dp[v] == SHRT_MAX )
            {
                Q.push( v );
                dp[v] = dp[top] + 1;
            }
        }

        if( dp[ G.size() - 1 ] != SHRT_MAX )
            break;
    }
}
