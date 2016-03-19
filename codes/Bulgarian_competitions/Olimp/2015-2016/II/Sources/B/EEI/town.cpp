#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n;
int cost[200100];
vector<pair<int, int> > nei[200100];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,p,q;
    cin>>n>>a>>b;
    --a;
    --b;
    while (cin)
    {
        cin>>p>>q;
        if (!cin) continue;
        //cout<<p<<" "<<q<<endl;
        --p;
        --q;
        nei[p].push_back(make_pair(q,0));
        nei[q].push_back(make_pair(p,-1));
    }
    for (int i=0;i<n;++i)
    {
        cost[i]=1;
    }
    cost[a]=0;
    priority_queue<pair<int, int> > pq;
    pair<int, int> curr;
    curr.first=0;
    curr.second=a;
    pq.push(curr);
    int curr_cost;
    while (!pq.empty())
    {
        /*for (int i=0;i<n;++i)
        {
            cout<<i+1<<": "<<cost[i]<<endl;
        }*/
        curr=pq.top();
        pq.pop();
        p=curr.second;
        curr_cost=curr.first;
        if (curr_cost<cost[p]) continue;
        for (int i=0;i<nei[p].size();++i)
        {
            q=nei[p][i].first;
            //cout<<" "<<p+1<<": "<<q+1<<endl;
            if (cost[q]==1 || cost[q]<curr_cost+nei[p][i].second)
            {
                cost[q]=curr_cost+nei[p][i].second;
                curr.first=cost[q];
                curr.second=q;
                pq.push(curr);
            }
        }
    }
    if (cost[b]==1) cout<<"X\n";
    else cout<<-cost[b]<<'\n';
    return 0;
}