#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
int n,a,b,d[200005];
vector<pair<int, int> > v[200005];
priority_queue<pair<int, int> > q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>a>>b;
    for (int i=0; i<=n; i++)
        d[i]=(1<<31)-1;
    int x,y;
    while (cin>>x>>y)
    {
        v[x].push_back(make_pair(y,0));
        v[y].push_back(make_pair(x,1));
    }
    d[a]=0;
    q.push(make_pair(0,a));
    while (!q.empty())
    {
        int w=-q.top().first,num=q.top().second;
        q.pop();
        if (d[num]<w)
            continue;
        for (int i=0; i<v[num].size(); i++)
        {
            int teg=v[num][i].second,z=v[num][i].first;
            if (d[z]>d[num]+teg)
            {
                d[z]=d[num]+teg;
                q.push(make_pair(-d[z],z));
            }
        }
    }
    if (d[b]==((1<<31)-1))
        cout<<"X\n";
    else
        cout<<d[b]<<'\n';
    return 0;
}
