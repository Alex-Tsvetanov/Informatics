#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int crosses, from, to;
int cost[200001];
int obh[200001];
vector<int> way[200001];
vector<int> opp[200001];
void srch(int curr, int sum)
{
    obh[curr] = true;
    cost[curr] = (cost[curr]==-1?sum:min(cost[curr],sum));
    int gone = 0;
    for(int i = 0; i < way[curr].size(); i ++)
    {
        if(!obh[way[curr][i]])
        {
            obh[way[curr][i]] = true;
            srch(way[curr][i], sum);
            obh[way[curr][i]] = false;
            gone ++;
        }
    }
    for(int i = 0; i < opp[curr].size(); i ++)
    {
        if(!obh[opp[curr][i]])
        {
            obh[opp[curr][i]] = true;
            srch(opp[curr][i], sum+1);
            obh[opp[curr][i]] = false;
        }
    }
    obh[curr] = false;
}
int main()
{
    cin >> crosses >> from >> to;
    int a, b;
    while(cin >> a >> b)
    {
        way[a].push_back(b);
        opp[b].push_back(a);
    }
    for(int i = 0; i < 200000; i ++) cost[i] = -1;
    srch(from, 0);
    if(cost[to] == -1) cout << "X" << endl;
    else cout << cost[to] << endl;
}
