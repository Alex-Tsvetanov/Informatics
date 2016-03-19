#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
vector<int>v[4096],ans;
int used[4096],maxt=0;
int br=0;
void BFS(int i)
{
    br=0;
    memset(used,0,sizeof(used));
    int j,work,nb;
    queue<int>q;
    used[i]=1;
    maxt=1;
    br++;
    q.push(i);
    while (!q.empty())
    {
        work=q.front();
        q.pop();
        int sz=v[work].size();
        for (j=0;j<sz;j++)
        {
            nb=v[work][j];
            if (!used[nb])
            {
                used[nb]=used[work]+1;
                if (used[nb]>maxt)maxt=used[nb]+1;
                br++;
                q.push(nb);
            }
        }
    }
}
int main()
{
    int n,m,i,minsz=1<<30;
    cin>>n>>m;
    for (i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }
    for (i=0;i<n;i++)
    {
        BFS(i);
        if (br==n)
        {
            if (maxt<minsz)
            {
                ans.clear();
                ans.push_back(i);
                minsz=maxt;
            }
            else ans.push_back(i);
           // cout<<maxt<<endl;
        }
    }
    int sz=ans.size();
    if (sz==0)
    {
        cout<<0<<endl;
        return 0;
    }
    cout<<sz<<endl;
    cout<<ans[0];
    for (i=1;i<sz;i++)
    {
            cout<<" "<<ans[i];
    }
    cout<<endl;
    return 0;
}
