#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

const long long inf = 2000000000;
long long dist [20000];
vector < pair < int, long long > > ln [20000];

struct lEss
{
	bool operator()(pair <long long, int> s1, pair <long long, int> s2) const
	{
		return s1 > s2;
	}
};

int main ()
{
	//init
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	//input
	int n, m;
	cin >> n >> m;
	for (int i = 0 ; i < m ; i ++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		ln [b].push_back ({a, cost});
		ln [a].push_back ({b, cost});
	}
	//djikstra
	set < pair <long long, int>, lEss > pq;
	for (int i = 0 ; i < n ; i ++)
	{
		dist [i] = (i == 0)?inf:-inf;
		pq.insert ({dist [i], i});
	}
	/*
	for (int i = 0 ; i < n ; i ++)
		cout << dist [i] << " ";
	cout << endl;
	*/
	while (not pq.empty ())
	{
	/*	for (int i = 0 ; i < n ; i ++)
			cout << dist [i] << " ";
		cout << endl;*/
		auto top = *pq.begin ();
		pq.erase (pq.begin ());
//		cout << "current step" << top.first << " " << top.second << endl;

		for (auto& x : ln [top.second])
		{
			int to = x.first;
			long long cost = min (top.first, x.second);
//			cout << cost << " " << to << endl;
			if (cost > dist [to])
			{
//				cout << "update: " << to << " -> " << dist [to] << " = " << cost << "\n";
				pq.erase (pq.find ({dist [to], to}));
				pq.insert ({cost, to});
				dist [to] = cost;
			}
		}
	}
	for (int i = 1 ; i < n ; i ++)
		cout << dist [i] << " ";
	cout << endl;
}

