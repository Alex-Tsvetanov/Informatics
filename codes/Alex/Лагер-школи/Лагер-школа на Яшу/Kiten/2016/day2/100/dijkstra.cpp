#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

const uint64_t inf = ((uint64_t)(-1));
vector < uint64_t > dist;
vector < vector < pair < int, uint64_t > > > ln;

struct lEss
{
    bool operator()(pair <uint64_t, int> s1, pair <uint64_t, int> s2) const
    {
        return s1 < s2;
    }
};

int main ()
{
    cin.tie (nullptr);
    ios::sync_with_stdio (false);
	//cout << inf << std::endl;
    int n, m;
    cin >> n >> m;
	ln.resize (n);
	dist.resize (n);
    for (int i = 0 ; i < m ; i ++)
    {
        int a, b;
		uint64_t cost;
        cin >> a >> b >> cost;
		a --;
		b --;
        ln [a].push_back ({b, cost});
    }
    set < pair <uint64_t, int>, lEss > pq;
	pq.insert ({dist [0] = 0, 0});
    for (int i = 1 ; i < n ; i ++)
    {
        dist [i] = inf;
        pq.insert ({dist [i], i});
    }
    while (not pq.empty ())
    {
        auto top = *pq.begin ();
        pq.erase (pq.begin ());
		//cout << "Top: " << top.second << " " << top.first << std::endl;

        for (auto& x : ln [top.second])
        {
            int to = x.first;
            uint64_t cost = top.first + x.second;
			//cout << "\tLN: " << to << " " << cost << "\n";
            if (cost < dist [to])
            {
                if (pq.find ({dist [to], to}) != pq.end ())
					pq.erase (pq.find ({dist [to], to}));
                pq.insert ({cost, to});
                dist [to] = cost;
            }
        }
    }
	cout << 0 << " ";
    for (int i = 1 ; i < n ; i ++)
        cout << dist [i] << " ";
    cout << endl;
}
