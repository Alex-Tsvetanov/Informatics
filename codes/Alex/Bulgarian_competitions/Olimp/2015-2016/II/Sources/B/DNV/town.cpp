#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
int n,a,b;
long long mas[200005];
vector<pair<int,int> > v[200005];
void Dijkstra(int x)
{
    for(int i=1;i<=n;i++)
    {
        mas[i]=10000000;
    }
    priority_queue<pair<int,int> >q;
    q.push(make_pair(0,x));
    while(q.size()!=0)
    {
        int dist=-q.top().first;
        int ch=q.top().second;
        //cout<<dist<<" "<<ch<<" "<<v[ch].size()<<endl;
        q.pop();
        for(int i=0;i<v[ch].size();i++)
        {
            int fst=v[ch][i].first;
            int w=v[ch][i].second;
            if(mas[fst]>w+dist)
            {
                mas[fst]=w+dist;
                q.push(make_pair(-mas[fst],fst));
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y;
    cin>>n>>a>>b;
    while(cin>>x>>y)
    {
        v[x].push_back(make_pair(y,0));
        v[y].push_back(make_pair(x,1));
    }
    Dijkstra(a);
    if(mas[b]!=10000000)cout<<mas[b]<<endl;
    else cout<<"X"<<endl;
    return 0;
}
/*
7 1 7
1 2
2 3
3 4
5 4
6 5
6 7
7 1
1 5
2 4
2 7
3 6
*/
