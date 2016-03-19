#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int par[3000];
int m,n,br,used[4000];
vector<int>v[400000];
void read()
{
    int i,x,y;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
    }
}
void clearc()
{
    int k;
    for(k=0;k<n;k++)
    {
        used[k]=0;
    }
}
void BFS(int i)
{
    int j,sz,nb,t,k;
    clearc();
    queue<int>q;
    used[i]=1;
    q.push(i);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        sz=v[t].size();
        for(j=0;j<sz;j++)
        {
            nb=v[t][j];
            if(!used[nb])
            {
                q.push(nb);
                used[nb]=used[t]+1;
                par[nb]=t;
            }
        }
    }
    for(k=0;k<n;k++)
    {
        if(used[k]!=0)br++;
    }

}
int main()
{
int rbr=0,c;
read();
queue<int>qi;
for(int i=0;i<n;i++)
{
    br=0;
    BFS(i);
    if(br==n)
    {
        rbr++;
        qi.push(i);
    }
}
cout<<rbr<<endl;
int sz;
sz=qi.size();
cout<<sz<<endl;
while(!qi.empty())
{
    c=qi.front();
    qi.pop();
    cout<<c<<" ";
}
cout<<endl;
return 0;
}
