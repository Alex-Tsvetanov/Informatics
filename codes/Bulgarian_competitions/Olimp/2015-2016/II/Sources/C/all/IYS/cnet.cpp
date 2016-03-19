#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
vector<int>v[400001];
unsigned int inf=1<<31;
unsigned int n,k,minn=inf,br=0,used[4096],d[4096],dd[4096];
void read()
{
    int a,b,i;
    cin>>n>>k;
    for(i=0;i<k;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
    }
}
int BFS(int i)
{
    int j,sz,nb,u,maxn=0,b=1,br=1;
    memset(used,0,sizeof(used));
    memset(d,0,sizeof(d));
    used[i]=1;
    queue<int> q;
    q.push(i);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        if(!used[u])b++;
        used[u]=1;
        sz=v[u].size();
        for(j=0;j<sz;j++)
        {
            nb=v[u][j];
            if(!used[nb])
            {b++;
                used[nb]=1;
                q.push(nb);d[nb]=d[u]+1;
                if(d[nb]>maxn)maxn=d[nb];
            }
        }
    }
    if(b==n)
    return maxn;
    return inf;
}
int main()
{
    unsigned int i,t;
    read();
    for(i=0;i<n;i++)
    {
        sort(v[i].begin(),v[i].end());
    }
    for(i=0;i<n;i++)
    {
        t=BFS(i);
        dd[i]=t;
        if(t!=0&&t!=inf)br++;
    }
    cout<<br<<endl;
    for(i=0;i<n;i++)
    {
        if(dd[i]!=inf&&dd[i]!=0){cout<<i<<" ";br--;}if(br==0)break;
    }cout<<endl;
    return 0;
}
/*
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
7 4
4 7
*/
