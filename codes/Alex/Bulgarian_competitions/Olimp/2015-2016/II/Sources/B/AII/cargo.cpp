#include <iostream>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

inline bool weekend(int x)
{
    return x%6==0 || x%7==0;
}

int n, m, p, pHalf;
vector<pair<int, int> > requests;

vector<int> nextBusy;
vector<vector<int> > contain;
vector<bool> usedReq;

bool possible=false;
bool noSunday=false;

void go(int time, int teams, bool sundayWork, int done)
{
    if(possible&&noSunday)return;
    if(teams<0)return;
    if(time==n+1||done==m)
    {
        if(done==m)
        {
            possible=true;
            if(!sundayWork)noSunday=true;
        }
        return;
    }

    go(nextBusy[time], pHalf, sundayWork, done);

    for(size_t i=0;i<contain[time].size();i++)
    {
        int current=contain[time][i];
        if(!usedReq[current])
        {
            usedReq[current]=true;

            go(time, teams-1, (sundayWork || weekend(time)), done+1);

            usedReq[current]=false;
        }
    }
}

void optimize()
{
    int minStart=INT_MAX;
    for(int i=0;i<m;i++)
    {
        const pair<int, int> &r=requests[i];
        minStart=min(minStart, r.first);
    }
    for(int i=0;i<m;i++)
    {
        pair<int, int> &r=requests[i];
        r.first-=(minStart/7)*7;
        r.second-=(minStart/7)*7;
    }

    int maxEnd=0;
    for(int i=0;i<m;i++)
    {
        const pair<int, int> &r=requests[i];
        maxEnd=max(maxEnd, r.second);
    }

    n=min(n, maxEnd+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>p;
    for(int i=0;i<m;i++)
    {
        int x, y;
        cin>>x>>y;
        requests.push_back(make_pair(x, y));
    }

    optimize();

    contain.resize(n+1);
    usedReq.resize(m, false);
    nextBusy.resize(n+1, 0);
    for(int i=0;i<m;i++)
    {
        const pair<int, int> &req=requests[i];
        for(int j=req.first;j<=req.second;j++)
        {
            contain[j].push_back(i);
            nextBusy[j-1]=j;
        }
    }

    nextBusy[n]=n+1;
    for(int i=n;i>0;i--)if(nextBusy[i]==0)nextBusy[i]=nextBusy[i+1];

    pHalf=p/2;
    go(1, pHalf, false, 0);

    if(!possible)puts("IMPOSSIBLE");
    else if(noSunday)puts("OK");
    else puts("MIXED");

    return 0;
}
/*
100 3 2
4 5
5 6
5 7

1000000000 3 4
4 5
5 6
5 7

100 3 2
1 5
2 7
3 4

1000000 4 2
1 5
2 7
3 4
6 6

1000000 10 20
1 100
1 100
1 100
1 100
1 100
1 100
1 100
1 100
1 100
1 100

1000000 10 20
1 100
1 100
1 100
1 100
1 100
1 100
1 100
1 100
1 100
21 21
*/
