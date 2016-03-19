#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,a,b,i,k[40001],k1[40001],j,z,min1=99999999ll,used[40001],br,i1,ans,w;
queue<int> q[40001],q1[40001];
int DFS(int x,int y)
{
    used[x]=1;
    if(x==y)
    {
        z=1;
        int w=br;
        br=0;
        return w;
    }
    else
    {
    if(!q[x].empty()&&used[q[x].front()]==1)
        for(;!q[x].empty()||used[q[x].front()]==1;)q[x].pop();
        if(!q[x].empty())
        {
            for(;!q[x].empty();)
            {
                if(q[x].empty()) break;
                if(used[q[x].front()]==0)
            min1=min(min1,DFS(q[x].front(),y));
            q[x].pop();
            }

        }
        else
        if(q[x].empty())
        {
            if(!q1[x].empty()&&used[q1[x].front()]==1)
                for(;!q1[x].empty()||used[q1[x].front()]==1;)q1[x].pop();
            if(!q1[x].empty())
            {
                br++;
                for(;!q1[x].empty();)
                {
                    if(q1[x].empty()) break;
                    if(used[q1[x].front()]==0)
                min1=min(min1,DFS(q1[x].front(),y));
                q1[x].pop();
                }
            }
        }
    }
    return min1;

}
int main()
{
    cin>>n>>a>>b;
    for(i=1;cin>>k[i]>>k1[i]; i++)
    {

    }
    for(j=i-1; j>1; j--)
    {
        q[k[j]].push(k1[j]);
        q1[k1[j]].push(k[j]);
    }
ans=DFS(a,b);
if(z==0) cout<<"X"<<endl;
else
    cout<<ans<<endl;
    return 0;
}
/*
4 1 4
4 3
3 2
1 2
4 2
*/
