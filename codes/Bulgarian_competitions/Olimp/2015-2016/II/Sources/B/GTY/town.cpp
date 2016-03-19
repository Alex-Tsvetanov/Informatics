

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<utility>
using namespace std;

#define TO second
#define LEN first

vector<pair<int ,int > > ms[200016];
bool used [200016];
priority_queue< pair<int , int > > pq;
int Dijkstra(int from, int to)
{
    pair <int, int> cur(1000000000,from);
    pq.push(cur);
    while(!pq.empty())
    {
        cur = pq.top();
        used[cur.TO] = 1;
        if(cur.TO == to)
        {
            return cur.LEN;
        }
        pq.pop();
        int bs = ms[cur.TO].size();
        for(int i = 0;i<bs;i++)
        {
            if(used[ms[cur.TO][i].TO])continue;
            pair<int, int >P(cur.LEN - ms[cur.TO][i].LEN, ms[cur.TO][i].TO);
            pq.push(P);
        }
    }
    return -1;
}



int main()
{
    int N,A,B,br = 0;
    cin>>N>>A>>B;
    int a,b;
    for(;cin>>a;)
    {
        cin>>b;
        pair<int, int> E;
        E.TO = b;
        E.LEN = 0;
        ms[a].push_back(E);
        E.TO = a;
        E.LEN = 1;
        ms[b].push_back(E);
    }
    int res = Dijkstra(A,B);
    if(res == -1)
    {
        cout<<"X\n";
        return 0;
    }
    cout<<1000000000 - res<<"\n";


    return 0;
}
