#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, b, e;
vector < int > G[3001];

bool BFS (int s)
{
    int br = 0;
    queue < int > q;
    bool used[3001];
    for (int i = 0; i < n; ++ i) used[i] = false;
    q.push (s);
    used[s] = true;
    br ++;
    while (!q.empty ())
    {
        for (int i = 0; i < G[q.front ()].size (); ++ i)
        {
            if (!used[G[q.front ()][i]])
            {
                q.push (G[q.front ()][i]);
                used[G[q.front ()][i]] = true;
                br ++;
            }
        }
        q.pop ();
    }
    if (br == n) return true;
    return false;

}

int main ( )
{
    ios :: sync_with_stdio (0);
    cin.tie (0);
    cout.tie (0);
    cin >> n >> m;
    for (int i = 0; i < m; ++ i)
    {
        cin >> b >> e;
        G[b].push_back (e);
    }
    vector < int > ans;
    for (int i = 0; i < n; ++ i) if (BFS (i)) ans.push_back (i);
    cout << ans.size () << endl;
    for (int i = 0; i < ans.size () - 1; ++ i) cout << ans[i] << " ";
    cout << ans[ans.size () - 1] << endl;
	return 0;
}
