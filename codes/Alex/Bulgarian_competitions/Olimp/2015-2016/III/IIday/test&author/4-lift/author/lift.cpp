#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#define MAXLIFTS 1024
#define MAXN 1000009
using namespace std;
int n, k, pUp, pDown, pIn, pOut;
vector<int> lifts[MAXLIFTS];
set<int> s;
map <int, int> renames;
vector<pair<int, int> > v[4096];
bool visited[4096];

int main ()
{
	scanf("%d%d%d%d%d%d", &n, &pUp, &pDown, &pIn, &pOut, &k);
	for (int i = 0; i < k; i++)
	{
		int q, f;
		scanf("%d", &q);
		for (int j = 0; j < q; j++)
		{
			scanf("%d", &f);
			lifts[i].push_back(f);
			s.insert(f);		
		}
	}
	s.insert(1);
	s.insert(n);

	int br = 0;
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		renames[*it]=++br;
		//printf("%d means %d\n", br, *it);
	}

	for (map<int, int>::iterator it = renames.begin(); it != renames.end(); it++)
	{
		if (it == renames.begin())
			continue;
		map<int, int>::iterator it2 = it;
		do
		{
			it2--;
			v[it->second].push_back(make_pair(it2->second, (it->first - it2->first)*pDown));
			v[it2->second].push_back(make_pair(it->second, (it->first - it2->first)*pUp));
		} while (it2 != renames.begin());
	}
	for (int i = 0; i < k; i++)
		for (int j = 0; j < lifts[i].size()-1; j++)
			for (int l = j+1; l < lifts[i].size(); l++)
			{
				int p1 = renames[lifts[i][j]], p2 = renames[lifts[i][l]];
				v[p1].push_back(make_pair(p2, pIn + pOut));
				v[p2].push_back(make_pair(p1, pIn + pOut));
			}
	/*for (int i = 1; i <= br; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
			printf("%d:%d  ", v[i][j].first, v[i][j].second);
		printf(" -- %d\n", i);
	}*/
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, 1));


	int target = renames[n];

	for (;!q.empty();)
	{
		int pos = q.top().second;
		int t = -q.top().first;
		q.pop();

		if (pos == target)
		{
			printf("%d\n", t);
			return 0;
		}
		if (visited[pos])
			continue;
		visited[pos] = true;
		
		for (int i = 0; i < v[pos].size(); i++)
		{
			if (visited[v[pos][i].first])
				continue;
			q.push(make_pair(- (t + v[pos][i].second), v[pos][i].first));
		}
	}
	return 0;
}
