#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

vector <int> ln [100000];

int preProcess [100000][19];
vector < int > Euler_tour_in_tree;
int Depth [100000];

void Euler_tour (int v, int prev = -1, int curr_depth = 0)
{
    Euler_tour_in_tree.push_back (v);
    Depth [v] = curr_depth;
    for (auto& x : ln [v])
    {
        if (x != prev)
        {
            Euler_tour (x, v, curr_depth + 1);
            Euler_tour_in_tree.push_back (v);
        }
    }
}

#include "../../../../Strutures/Trees/binary_trees/binary_indexed_tree/binary_indexed_tree.h"

int main ()
{
//  cin.tie(nullptr);
//  ios::sync_with_stdio (false);
    int n;
    cin >> n;
    for (int i = 0 ; i < n - 1; i ++)
    {
        int x;
        cin >> x;
        ln [x].push_back (i + 1);
    }
    Euler_tour (0);

    for (int i = 0 ; i < n ; i ++)
        ln [i].clear ();
    
    cout << endl;
    for (int i = 0 ; i < (int)Euler_tour_in_tree.size () ; i ++)
        cout << setw (2) << Euler_tour_in_tree [i] << " ";
    cout << endl;
    for (int i = 0 ; i < (int)Euler_tour_in_tree.size () ; i ++)
        cout << setw (2) << Depth [Euler_tour_in_tree [i]] << " ";
    cout << endl;
    for (int i = 0 ; i < (int)Euler_tour_in_tree.size () ; i ++)
    {
        ln [Euler_tour_in_tree [i]].push_back (i);
    }

    BIT<int> index_tree;
//    index_tree.init (move (Euler_tour_in_tree));

    int q;
    cin >> q;
    for (int i = 0 ; i < q ; i ++)
    {
        int a, b;
        cin >> a >> b;
        int LCA = index_tree.query (ln [a][0], ln [b][0]);
        if (a == b)
            cout << "You are there";
        else if ( LCA == b or LCA == a)
            cout << "Directly";
        else
            cout << "Through " << LCA;
        cout << endl;
    }
}
