#include<iostream>
#include<queue>
using namespace std;
vector<int> v[3000];
queue<int> qu;
int n,m;
int bfs(int a)
{
    int m[3005]={0};
    int t,d=0,s=0;
    qu.push(a);
    s=qu.size();
    t=qu.front();
    while(!qu.empty())
    {
        s--;
        if(s==0)
        {
            d++;
            s=qu.size();
        }
        t=qu.front();
        //cout<<t<<endl;
        if(m[t]==1)
        {
            qu.pop();
            continue;
        }
        m[t]=1;
        d++;
        for(int i=0; i<v[t].size(); i++)
        {
            qu.push(v[t][i]);
        }
        qu.pop();
    }
    for(int i=0; i<n; i++)
    {
        if(m[i]==0)return 0;
    }
    return d;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    int a,b;
    for(int i=0; i<m; i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
    }
    int otg[3005];
    int br=0;
    int d, maxd=10000000;
    for(int i=0; i<n; i++)
    {
        d=bfs(i);
       // cout<<d<<endl;
        if(d<maxd&&d>0)
        {
            maxd=d;
            br=0;
            otg[br]=i;
        }
        else if(d==maxd)
        {
            br++;
            otg[br]=i;
        }
    }
    cout<<br+1<<endl;
    for(int i=0;i<=br;i++)
    {
        cout<<otg[i]<<" ";
    }
    cout<<endl;
    return 0;
}

/**

8 13
0 1
0 2
1 3
3 0
7 1
3 5
4 1
4 5
7 5
5 2
5 6
4 7
7 4
*/
