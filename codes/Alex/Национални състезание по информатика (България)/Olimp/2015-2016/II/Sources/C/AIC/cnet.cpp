#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

vector < int > ln [3000];
bool visited [3000];
long long max_depths [3000];
int n;

void bfs (int s)
{
    for (int i = 0 ; i < 3000 ; i ++)
        visited [i] = false;
    int max_depth = 0;
    queue < pair < int, int > > q;
    q.push (make_pair (s, 0));
    visited [s] = true;
    while (not q.empty ())
    {
        int curr = q.front ().first;
        int depth = q.front ().second;
        max_depth = max (max_depth, depth);
        q.pop ();
        visited [curr] = true;
        for (int i = 0 ; i < (int)ln [curr].size () ; i ++)
            if (not visited [ln [curr][i]])
            {
                q.push (make_pair (ln [curr][i], depth + 1));
            }
    }
    for (int i = 0 ; i < n ; i ++)
        if (visited [i] == false)
        {
            max_depths [s] = -1;
            return ;
        }

    max_depths [s] = max_depth;
}

int main ()
{
    cin.tie (NULL);
    ios::sync_with_stdio (false);
    int m;
    cin >> n >> m;
    for (int i = 0 ; i < m ; i ++)
    {
        int a, b;
        cin >> a >> b;
        ln [a].push_back (b);
    }
    for (int i = 0 ; i < n ; i ++)
        bfs (i);
    vector < int > ans;
    long long min_for_find = 1000000;
    for (int i = 0 ; i < n ; i ++)
        if (max_depths [i] > -1)
            min_for_find = min (min_for_find, max_depths [i]);
    for (int i = 0 ; i < n ; i ++)
        if (max_depths [i] == min_for_find)
            ans.push_back (i);
//    for (int i = 0 ; i < ans.size () - 1 ; i ++)
//        cout << ans [i] << " -> " << max_depths [ans [i]] << "\n";
//    cout << ans [ans.size () - 1] << " -> " << max_depths [ans [ans.size () - 1]] << "\n";
    cout << ans.size () << "\n";
    if (ans.size () > 0)
    {
        for (int i = 0 ; i < (int)ans.size () - 1 ; i ++)
            cout << ans [i] << " ";
        cout << ans [ans.size () - 1] << "\n";
    }
    return 0;
}
