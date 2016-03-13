#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct node{
    int n;
    int w;
};

typedef vector<vector<node> > Graph;

int BFS( Graph& G, int n, vector<int>& W );

int main()
{
    int n, m;

    cin >> n >> m;

    Graph G(n);

    for( int i = 0; i < m; ++i )
    {
        int u, v, w;
        cin >> u >> v >> w;
        G[ u - 1 ].push_back( {v - 1, w} );
        G[ v - 1 ].push_back( {u - 1, w} );
    }

    vector<int> W( G.size(), INT_MIN );
    W[ 0 ] = INT_MAX;

    cout << BFS( G, n-1, W ) << endl;

    return 0;
}

int BFS( Graph& G, int n, vector<int>& W )
{
    vector<bool> used( G.size(), false );
    used[ 0 ] = true;



    queue<int> Q;
    Q.push( 0 );

    while( !Q.empty() )
    {
        int top = Q.front();

        for( int i = 0; i < G[top].size(); ++i )
        {
            int dist = min( W[ top ], G[top][i].w );
            if( dist > W[ G[top][i].n ] )
            {
                W[ G[top][i].n ] = dist;
            }

            if( !used[ G[top][i].n ] )
            {
                Q.push( G[top][i].n );
                used[ G[top][i].n ] = true;
            }
        }

        Q.pop();
    }

    if( W[ n ] != INT_MIN )
    {
        return W[ n ];
    }
    else
    {
        return 0;
    }
}
